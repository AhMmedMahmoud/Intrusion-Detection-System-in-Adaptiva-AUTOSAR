#include "idsm.h"
#include <iostream>
#include <algorithm>
#include "../ids_protocol/ids_message.h"
#include "../Manifest/manager/manifest_manager.h"
#include "../Manifest/shared/shared_eventContextMappings.h"

namespace ara
{
    namespace idsm
    {
        namespace someip
        {
            const uint16_t cMethodReportEventCountType = 1;
            const uint16_t cMethodReportEventTimestampTypeCountType = 2;
            const uint16_t cMethodReportEventContextDataTypeCountType = 3;
            const uint16_t cMethodReportEventContextDataTypeTimestampTypeCountType = 4;
            const std::string IDSM::cAnyIpAddress("0.0.0.0");

            /******************************* constructors  ******************************/
            IDSM::IDSM( uint16_t serviceId,
                        uint16_t instanceId,
                        uint8_t majorVersion,
                        uint16_t eventgroupId, 
                        AsyncBsdSocketLib::Poller *poller,
                        std::string nicIpAddress,
                        std::string multicastGroup,
                        uint16_t port_Sensors_IDSM,
                        uint16_t port_IDSM_IDSR,
                        uint8_t protocolVersion,
                        uint8_t interfaceVersion) : mServiceId{serviceId},
                                                    mInstanceId{instanceId},
                                                    mMajorVersion{majorVersion},
                                                    mEventgroupId{eventgroupId},
                                                    mProtocolVersion{protocolVersion},
                                                    mInterfaceVersion{interfaceVersion},      
                                                    cNicIpAddress{nicIpAddress},
                                                    cMulticastGroup{multicastGroup},
                                                    cPort_Sensors_IDSM{port_Sensors_IDSM},
                                                    cPort_IDSM_IDSR{port_IDSM_IDSR},
                                                    mPoller{poller},
                                                    mUdpSocket(cAnyIpAddress, port_Sensors_IDSM, nicIpAddress, multicastGroup),
                                                    mUdpSocket_idsm_to_idsr(cAnyIpAddress, port_IDSM_IDSR, nicIpAddress, multicastGroup)
            {
                bool _successful{mUdpSocket.TrySetup()};
                if (!_successful)
                {
                    throw std::runtime_error("Sensors_IDSM UDP socket setup failed.");
                }

                auto _receiver{std::bind(&IDSM::onReceive, this)};
                _successful = mPoller->TryAddReceiver(&mUdpSocket, _receiver);
                if (!_successful)
                {
                    throw std::runtime_error("Adding Sensors_IDSM UDP socket receiver failed.");
                }

                _successful = mUdpSocket_idsm_to_idsr.TrySetup();
                if (!_successful)
                {
                    throw std::runtime_error("IDSM_IDSR UDP socket setup failed.");
                }

                auto _sender{std::bind(&IDSM::onSend, this)};
                _successful = mPoller->TryAddSender(&mUdpSocket_idsm_to_idsr, _sender);
                if (!_successful)
                {
                    throw std::runtime_error("Adding IDSM_IDSR UDP socket sender failed.");
                }

                manifest::ManifestManager manager("../Manifest/manifest.json");
                manager.parseJSON();
                
                for(manifest::SecurityEventContextMapping obj : manifest::eventContextMappings)
                {
                    myMap[obj.getMappedSecurityEvent().getSecurityEventDefinition().getId()] = 
                        obj.getFilterChain().getOneEveryN().getN();
                }
            }

            bool IDSM::isValidMessage(const ara::com::someip::rpc::SomeIpRpcMessage &request)
            {    
                auto _serviceID = request.MessageId() >> 16;
                auto _methodID = request.MessageId() & 0xffff;
                if(
                    (_serviceID == mServiceId)
                    && (_methodID == cMethodReportEventCountType || 
                        _methodID == cMethodReportEventTimestampTypeCountType ||
                        _methodID == cMethodReportEventContextDataTypeCountType ||
                        _methodID == cMethodReportEventContextDataTypeTimestampTypeCountType
                       )
                    && (request.ProtocolVersion() == mProtocolVersion)
                    && (request.InterfaceVersion() == mInterfaceVersion)
                    && (request.MessageType() == ara::com::someip::SomeIpMessageType::Request)
                    && (request.ReturnCode() == ara::com::someip::SomeIpReturnCode::eOK)
                )
                {
                    return true;
                }

                std::cout << "invalid message\n";
                return false;
            }

            void IDSM::logic(const ara::com::someip::rpc::SomeIpRpcMessage &request)
            {
                ///// get method id that crossponds to received message /////
                uint16_t _methodID = request.MessageId();

                ///// read current state machine /////
                std::string _currentStateMachine = "State_1";

/**********************************************************
* received message  : void ReportEvent( CountType count)  *
**********************************************************/
                if(_methodID == cMethodReportEventCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const CountType count=1) \n";  
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.end()-1));
                    if(_index == -1) return;

                    uint8_t _sensorInstanceId;
                    uint16_t _eventDefinationID;
                    uint16_t _idsMInstanceID;
                    uint8_t _count;
                    
                    _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                    _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                    _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                    _count = payload[payload[0]+1];

                    ///////////////////////////
                    // Reporting Mode filter //
                    ///////////////////////////            
                    switch(getReportingMode(_index))
                    {
                        case manifest::SecurityEventReportingModeEnum::BRIEF_BYPASSING_FILTERS:
                        case manifest::SecurityEventReportingModeEnum::DETAILED_BYPASSING_FILTERS:
                            NoFilters( _idsMInstanceID,
                                       _sensorInstanceId,
                                       _eventDefinationID,
                                       _count
                                     );    
                        break;

                        case manifest::SecurityEventReportingModeEnum::BRIEF:
                        case manifest::SecurityEventReportingModeEnum::DETAILED:   
                            if(stateMachineFilterExists(_index))
                            {
                                std::cout << "stateFilter exists\n";
                                if(isCurrentMachineStateOneOfBlockingState(_index,_currentStateMachine))
                                {
                                    std::cout << "\tone of blocking states\n";
                                    return;
                                }
                                std::cout << "\tnot one of blocking states\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count
                                               );
                            }
                            else
                            {       
                                std::cout << "stateFilter not exists\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count
                                               );
                            }
                        break;

                        case manifest::SecurityEventReportingModeEnum::OFF: 
                            return;
                        break;
                    }
                }
/************************************************************************
* received message  : void ReportEvent( TimestampType timestamp,        *
*                                       CountType count                 *
*                                     )                                 *
************************************************************************/
                else if(_methodID == cMethodReportEventTimestampTypeCountType)
                {
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index == -1) return;

                    uint8_t _sensorInstanceId;
                    uint16_t _eventDefinationID;
                    uint16_t _idsMInstanceID;
                    size_t _offset;
                    uint32_t _nanoseconds;
                    uint32_t _seconds;
                    uint8_t _count;

                    _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                    _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                    _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                    _offset = payload[0]+1;
                    _nanoseconds = ara::com::helper::ExtractInteger(payload, _offset);
                    _seconds = ara::com::helper::ExtractInteger(payload, _offset);
                    _count = payload[_offset];

                    ///////////////////////////
                    // Reporting Mode filter //
                    ///////////////////////////            
                    switch(getReportingMode(_index))
                    {
                        case manifest::SecurityEventReportingModeEnum::BRIEF_BYPASSING_FILTERS:
                        case manifest::SecurityEventReportingModeEnum::DETAILED_BYPASSING_FILTERS:
                            NoFilters( _idsMInstanceID,
                                       _sensorInstanceId,
                                       _eventDefinationID,
                                       _count,
                                       _nanoseconds,
                                       _seconds
                                     );    
                        break;

                        case manifest::SecurityEventReportingModeEnum::BRIEF:
                        case manifest::SecurityEventReportingModeEnum::DETAILED:   
                            if(stateMachineFilterExists(_index))
                            {
                                std::cout << "stateFilter exists\n";
                                if(isCurrentMachineStateOneOfBlockingState(_index,_currentStateMachine))
                                {
                                    std::cout << "\tone of blocking states\n";
                                    return;
                                }
                                std::cout << "\tnot one of blocking states\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count,
                                                 _nanoseconds,
                                                 _seconds
                                               );
                            }
                            else
                            {       
                                std::cout << "stateFilter not exists\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count,
                                                 _nanoseconds,
                                                 _seconds
                                               );
                            }
                        break;

                        case manifest::SecurityEventReportingModeEnum::OFF: 
                            return;
                        break;
                    }
                }
/************************************************************************
* received message  : void ReportEvent( ContextDataType contextData     *
*                                       CountType count                 *
*                                     )                                 *
************************************************************************/
                else if(_methodID == cMethodReportEventContextDataTypeCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const ContextDataType &contextData,\n";
                    std::cout << "                  const CountType count=1) \n"; 
                    
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index == -1)
                        return ;

                    uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                    uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                    uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                    uint8_t _count = *(payload.rbegin());
                    std::vector<uint8_t> _dataContext = std::vector<uint8_t>(payload.begin()+1+payload[0],payload.end()-1);

                    ///////////////////////////
                    // Reporting Mode filter //
                    ///////////////////////////            
                    switch(getReportingMode(_index))
                    {
                        case manifest::SecurityEventReportingModeEnum::BRIEF_BYPASSING_FILTERS:
                        case manifest::SecurityEventReportingModeEnum::DETAILED_BYPASSING_FILTERS:
                            NoFilters( _idsMInstanceID,
                                       _sensorInstanceId,
                                       _eventDefinationID,
                                       _count,
                                       _dataContext
                                     );    
                        break;

                        case manifest::SecurityEventReportingModeEnum::BRIEF:
                        case manifest::SecurityEventReportingModeEnum::DETAILED:   
                            if(stateMachineFilterExists(_index))
                            {
                                std::cout << "stateFilter exists\n";
                                if(isCurrentMachineStateOneOfBlockingState(_index,_currentStateMachine))
                                {
                                    std::cout << "\tone of blocking states\n";
                                    return;
                                }
                                std::cout << "\tnot one of blocking states\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count,
                                                 _dataContext
                                               );
                            }
                            else
                            {       
                                std::cout << "stateFilter not exists\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count,
                                                 _dataContext
                                               );
                            }
                        break;

                        case manifest::SecurityEventReportingModeEnum::OFF: 
                            return;
                        break;
                    }
                }
/************************************************************************
* received message  : void ReportEvent( ContextDataType contextData     *
*                                       TimestampType timestamp,        *
*                                       CountType count                 *
*                                     )                                 *
************************************************************************/
                else if(_methodID == cMethodReportEventContextDataTypeTimestampTypeCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const ContextDataType &contextData,\n";
                    std::cout << "                  const TimestampType timestamp,\n";
                    std::cout << "                  const CountType count=1)\n";

                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index == -1)
                        return;

                    uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                    uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                    uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();

                    size_t _offset = payload[0]+1;
                    uint32_t _nanoseconds = ara::com::helper::ExtractInteger(payload, _offset);
                    uint32_t _seconds = ara::com::helper::ExtractInteger(payload, _offset);
                    std::vector<uint8_t> _dataContext = std::vector<uint8_t>(payload.begin()+_offset, payload.end()-1);
                    uint8_t _count = *(payload.rbegin());

                    ///////////////////////////
                    // Reporting Mode filter //
                    ///////////////////////////            
                    switch(getReportingMode(_index))
                    {
                        case manifest::SecurityEventReportingModeEnum::BRIEF_BYPASSING_FILTERS:
                        case manifest::SecurityEventReportingModeEnum::DETAILED_BYPASSING_FILTERS:
                            NoFilters( _idsMInstanceID,
                                       _sensorInstanceId,
                                       _eventDefinationID,
                                       _count
                                     );    
                        break;

                        case manifest::SecurityEventReportingModeEnum::BRIEF:
                        case manifest::SecurityEventReportingModeEnum::DETAILED:   
                            if(stateMachineFilterExists(_index))
                            {
                                std::cout << "stateFilter exists\n";
                                if(isCurrentMachineStateOneOfBlockingState(_index,_currentStateMachine))
                                {
                                    std::cout << "\tone of blocking states\n";
                                    return;
                                }
                                std::cout << "\tnot one of blocking states\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count,
                                                 _nanoseconds,
                                                 _seconds,
                                                 _dataContext
                                               );
                            }
                            else
                            {       
                                std::cout << "stateFilter not exists\n";
                                
                                oneEveryNFilter( _index,
                                                 _idsMInstanceID,
                                                 _sensorInstanceId,
                                                 _eventDefinationID,
                                                 _count
                                               );
                            }
                        break;

                        case manifest::SecurityEventReportingModeEnum::OFF: 
                            return;
                        break;
                    }
                }
            }

            void IDSM::InvokeEventHandler(const ara::com::someip::rpc::SomeIpRpcMessage &request)
            {  
                request.print(); 
                if(isValidMessage(request))
                {
                    logic(request);
                }              
            }

            bool IDSM::stateMachineFilterExists(int _index)
            {
                return manifest::eventContextMappings[_index].getFilterChain().getState().getSpecifier() != "null";
            } 

            bool IDSM::oneEveryNFilterExists(int _index)
            {
                return manifest::eventContextMappings[_index].getFilterChain().getOneEveryN().getSpecifier() != "null";
            }

            bool IDSM::isCurrentMachineStateOneOfBlockingState(int _index, std::string _currentStateMachine)
            {
                std::vector<std::string> _blockingStates;
                _blockingStates = manifest::eventContextMappings[_index].getFilterChain().getState().getBlockIfStateActiveAp();
                auto it = std::find( _blockingStates.begin(), _blockingStates.end(), _currentStateMachine);
                return (!(it == _blockingStates.end())); 
            }

            manifest::SecurityEventReportingModeEnum IDSM::getReportingMode(int _index)
            {
                return manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum();
            }

            int IDSM::getN(int _index)
            {
                return manifest::eventContextMappings[_index].getFilterChain().getOneEveryN().getN();
            }

            void IDSM::NoFilters( uint16_t _idsMInstanceID,
                                uint8_t _sensorInstanceId,
                                uint16_t _eventDefinationID,
                                uint16_t _count,
                                uint32_t _nanoseconds,
                                uint32_t _seconds,
                                const std::vector<uint8_t> &_dataContext
                              )
            {
                ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                           ids::ProtocolHeader(1,1,1),
                                                           _idsMInstanceID,
                                                           _sensorInstanceId,
                                                           _eventDefinationID,
                                                           _count
                                                         ),
                                          ids::Timestamp( ids::TimeStampSource::AUTOSAR,
                                                          _nanoseconds,
                                                          _seconds
                                                        ),
                                          ids:: ContextDataFrame( (_dataContext.size() <= 127) ? ids::ContextDataSize::SHORT : ids::ContextDataSize::LONG,
                                                                  _dataContext.size(),
                                                                  _dataContext
                                                                )
                                                );
                std::cout << "-------IDS message-------\n";
                _message.print();
                mSendingQueue.TryEnqueue(std::move(_message.Payload())); 
            }

            void IDSM::NoFilters( uint16_t _idsMInstanceID,
                                  uint8_t _sensorInstanceId,
                                  uint16_t _eventDefinationID,
                                  uint16_t _count,
                                  const std::vector<uint8_t> &_dataContext
                                )
            {
                ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                            ids::ProtocolHeader(1,0,1),
                                            _idsMInstanceID,
                                            _sensorInstanceId,
                                            _eventDefinationID,
                                            _count
                                            ),
                                          ids:: ContextDataFrame( (_dataContext.size() <= 127) ? ids::ContextDataSize::SHORT : ids::ContextDataSize::LONG,
                                                                  _dataContext.size(),
                                                                  _dataContext
                                                                )
                                        );
                
                std::cout << "-------IDS message-------\n";
                _message.print();
                mSendingQueue.TryEnqueue(std::move(_message.Payload())); 
            }

            void IDSM::NoFilters( uint16_t _idsMInstanceID,
                                  uint8_t _sensorInstanceId,
                                  uint16_t _eventDefinationID,
                                  uint16_t _count,
                                  uint32_t _nanoseconds,
                                  uint32_t _seconds
                                )
            {
                ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                           ids::ProtocolHeader(1,1,0),
                                                           _idsMInstanceID,
                                                           _sensorInstanceId,
                                                           _eventDefinationID,
                                                           _count
                                                         ),
                                          ids::Timestamp( ids::TimeStampSource::AUTOSAR,
                                                          _nanoseconds,
                                                          _seconds
                                                        )
                                        );
                std::cout << "-------IDS message-------\n";
                _message.print();
                mSendingQueue.TryEnqueue(std::move(_message.Payload()));
            }

            void IDSM::NoFilters( uint16_t _idsMInstanceID,
                                  uint8_t _sensorInstanceId,
                                  uint16_t _eventDefinationID,
                                  uint16_t _count
                                )
            {
                ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                            ids::ProtocolHeader(1,0,0),
                                                            _idsMInstanceID,
                                                            _sensorInstanceId,
                                                            _eventDefinationID,
                                                            _count
                                                         )
                                        );
                std::cout << "-------IDS message-------\n";
                _message.print();
                mSendingQueue.TryEnqueue(std::move(_message.Payload()));
            }

            void IDSM::oneEveryNFilter( int _index,
                                        uint16_t _idsMInstanceID,
                                        uint8_t _sensorInstanceId,
                                        uint16_t _eventDefinationID,
                                        uint16_t _count,
                                        uint32_t _nanoseconds,
                                        uint32_t _seconds,
                                        const std::vector<uint8_t> &_dataContext
                                      )
            {
                if(oneEveryNFilterExists(_index))
                {
                    std::cout << "oneEveryNFilterExists\n";
                
                    if( myMap[_eventDefinationID] == getN(_index))
                    {
                        std::cout << "\tnow\n";
                        NoFilters( _idsMInstanceID,
                                   _sensorInstanceId,
                                   _eventDefinationID,
                                   _count,
                                   _nanoseconds,
                                   _seconds,
                                   _dataContext
                                  );
                        myMap[_eventDefinationID] = 1;
                    }
                    else
                    {
                        std::cout << "\tnot now\n";
                        myMap[_eventDefinationID] = myMap[_eventDefinationID]+1;  
                    }
                }
                else
                {
                    NoFilters( _idsMInstanceID,
                               _sensorInstanceId,
                               _eventDefinationID,
                               _count,
                               _nanoseconds,
                               _seconds,
                               _dataContext
                             );
                }
            }

            void IDSM::oneEveryNFilter( int _index,
                                        uint16_t _idsMInstanceID,
                                        uint8_t _sensorInstanceId,
                                        uint16_t _eventDefinationID,
                                        uint16_t _count,
                                        const std::vector<uint8_t> &_dataContext
                                      )
            {
                if(oneEveryNFilterExists(_index))
                {
                    std::cout << "oneEveryNFilterExists\n";
                
                    if( myMap[_eventDefinationID] == getN(_index))
                    {
                        std::cout << "\tnow\n";
                        NoFilters( _idsMInstanceID,
                                   _sensorInstanceId,
                                   _eventDefinationID,
                                   _count,
                                   _dataContext
                                 );           
                        myMap[_eventDefinationID] = 1;
                    }
                    else
                    {
                        std::cout << "\tnot now\n";
                        myMap[_eventDefinationID] = myMap[_eventDefinationID]+1;  
                    }
                }
                else
                {
                    NoFilters( _idsMInstanceID,
                               _sensorInstanceId,
                               _eventDefinationID,
                               _count,
                               _dataContext
                             ); 
                }
            }

            void IDSM::oneEveryNFilter( int _index,
                                        uint16_t _idsMInstanceID,
                                        uint8_t _sensorInstanceId,
                                        uint16_t _eventDefinationID,
                                        uint16_t _count,
                                        uint32_t _nanoseconds,
                                        uint32_t _seconds 
                                      )
            {
                if(oneEveryNFilterExists(_index))
                {
                    std::cout << "oneEveryNFilterExists\n";
        
                    if( myMap[_eventDefinationID] == getN(_index))
                    {
                        std::cout << "\tnow\n";
                        NoFilters( _idsMInstanceID,
                                   _sensorInstanceId,
                                   _eventDefinationID,
                                   _count,
                                   _nanoseconds,
                                   _seconds
                                 );
                        myMap[_eventDefinationID] = 1;
                    }
                    else
                    {
                        std::cout << "\tnot now\n";
                        myMap[_eventDefinationID] = myMap[_eventDefinationID]+1;  
                    }
                }
                else
                {
                    std::cout << "oneEveryNFilter not exist Exist\n";
                    NoFilters( _idsMInstanceID,
                               _sensorInstanceId,
                               _eventDefinationID,
                               _count,
                               _nanoseconds,
                               _seconds
                             );
                }
            }

            void IDSM::oneEveryNFilter( int _index,
                                        uint16_t _idsMInstanceID,
                                        uint8_t _sensorInstanceId,
                                        uint16_t _eventDefinationID,
                                        uint16_t _count 
                                      )
            {
                if(oneEveryNFilterExists(_index))
                {
                    std::cout << "oneEveryNFilterExists\n";
                
                    if( myMap[_eventDefinationID] == getN(_index))
                    {
                        std::cout << "\tnow\n";
                        NoFilters( _idsMInstanceID,
                                   _sensorInstanceId,
                                   _eventDefinationID,
                                   _count
                                 ); 
                        myMap[_eventDefinationID] = 1;
                    }
                    else
                    {
                        std::cout << "\tnot now\n";
                        myMap[_eventDefinationID] = myMap[_eventDefinationID]+1;  
                    }
                }
                else
                {
                    std::cout << "oneEveryNFilter not exist Exist\n";
                    NoFilters( _idsMInstanceID,
                                _sensorInstanceId,
                                _eventDefinationID,
                                _count
                             ); 
                }
            }

            /**************************** poller functions  **********************************/
            void IDSM::onReceive()
            {
                std::cout << "------------------------- onReceive ------------------\n";

                // define array to receive serialized SOMEIP/SD message
                std::array<uint8_t, cBufferSize> _buffer;

                std::string _ipAddress;
                uint16_t _port;

                // receive serialized SOMEIP/SD message in form of array not vector
                ssize_t _receivedSize{mUdpSocket.Receive(_buffer, _ipAddress, _port)};
                if (_receivedSize > 0 && _port == cPort_Sensors_IDSM && _ipAddress == cNicIpAddress)
                {
                    const std::vector<uint8_t> cRequestPayload(
                        std::make_move_iterator(_buffer.begin()),
                        std::make_move_iterator(_buffer.begin() + _receivedSize));

                    // Create the received message from the received payload
                    ara::com::someip::rpc::SomeIpRpcMessage _receivedMessage{ara::com::someip::rpc::SomeIpRpcMessage::Deserialize(cRequestPayload)};
                    
                    // call function that contain what to do with received message
                    
                    InvokeEventHandler(_receivedMessage);
                }
            }

            void IDSM::onSend()
            {
                while (!mSendingQueue.Empty())
                {
                    //std::cout << "--------------------------- onSend -------------------\n";
                    std::vector<uint8_t> _payload;
                    bool _dequeued{mSendingQueue.TryDequeue(_payload)};
                    if (_dequeued)
                    {       
                        // for printing
                        std::cout << "---------------------- onSend -----------------------\n";
                        std::cout << ".....sent message..... \n";
                        ids::IDSMessage toSend  = ids::IDSMessage::Deserialize(_payload);
                        toSend.print();
                        //std::cout << "--------------------------------------------------\n";
                        
                        std::array<uint8_t, cBufferSize> _buffer;
                        std::copy_n(
                            std::make_move_iterator(_payload.begin()),
                            _payload.size(),
                            _buffer.begin());

                        mUdpSocket_idsm_to_idsr.Send(_buffer, cMulticastGroup, cPort_IDSM_IDSR);
                    }
                }
            }

            /**************************** deconstructor  ************************/
            IDSM::~IDSM()
            {
                mPoller->TryRemoveReceiver(&mUdpSocket);
            }
        }
    }
}