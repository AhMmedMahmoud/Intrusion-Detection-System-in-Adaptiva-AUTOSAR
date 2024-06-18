#include "idsm.h"
#include <iostream>
#include <algorithm>
#include "../ids/ids_message.h"

//#include "../Manifest/manifestOperations.h"
//#include "../Manifest/sharedEventsInterface.h"

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
                uint16_t _methodID = request.MessageId();
                if(_methodID == cMethodReportEventCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const CountType count=1) \n";
                    
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.end()-1));
                    if(_index != -1 && manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum() != manifest::SecurityEventReportingModeEnum::OFF)
                    {
                        uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                        uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                        uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                        uint8_t _count = payload[payload[0]+1];
                    
                        ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                                    ids::ProtocolHeader(0,0,0),
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
                }
                else if(_methodID == cMethodReportEventTimestampTypeCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const TimestampType timestamp,\n";
                    std::cout << "                  const CountType count=1)\n";
                    
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index != -1 && manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum() != manifest::SecurityEventReportingModeEnum::OFF)
                    {
                        uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                        uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                        uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                        size_t _offset = payload[0]+1;
                        uint32_t _nanoseconds = ara::com::helper::ExtractInteger(payload, _offset);
                        uint32_t _seconds = ara::com::helper::ExtractInteger(payload, _offset);
                        uint8_t _count = payload[_offset];
                    
                        ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                                    ids::ProtocolHeader(0,1,0),
                                                                    _idsMInstanceID,
                                                                    _sensorInstanceId,
                                                                    _eventDefinationID,
                                                                    _count
                                                                    ),
                                                    ids::Timestamp( ids::TimeStampSource::AUTOSAR,
                                                                    _nanoseconds,
                                                                    _seconds)
                                                );
                        std::cout << "-------IDS message-------\n";
                        _message.print();
                        mSendingQueue.TryEnqueue(std::move(_message.Payload())); 
                    }
                }
                else if(_methodID == cMethodReportEventContextDataTypeCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const ContextDataType &contextData,\n";
                    std::cout << "                  const CountType count=1) \n"; 
                    
                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index != -1 && manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum() != manifest::SecurityEventReportingModeEnum::OFF)
                    {
                        uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                        uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                        uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();
                        uint8_t _count = *(payload.rbegin());

                        manifest::SecurityEventReportingModeEnum _reportingMode = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum(); 
                        if(_reportingMode == manifest::SecurityEventReportingModeEnum::DETAILED)
                        {
                            std::vector<uint8_t> _dataContext = std::vector<uint8_t>(payload.begin()+1+payload[0],payload.end()-1);
                            
                            ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                                        ids::ProtocolHeader(0,0,1),
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
                        else if(_reportingMode == manifest::SecurityEventReportingModeEnum::BRIEF)
                        {
                            ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                                       ids::ProtocolHeader(0,0,0),
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
                    }
                }
                else if(_methodID == cMethodReportEventContextDataTypeTimestampTypeCountType)
                {
                    std::cout << "-----------------\n";
                    std::cout << "void ReportEvent (const ContextDataType &contextData,\n";
                    std::cout << "                  const TimestampType timestamp,\n";
                    std::cout << "                  const CountType count=1)\n";

                    std::vector<uint8_t> payload = request.RpcPayload();
                    int _index = manifest::ManifestManager::find(std::string(payload.begin()+1,payload.begin()+1+payload[0]));
                    if(_index != -1 && manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventReportingModeEnum() != manifest::SecurityEventReportingModeEnum::OFF)
                    {
                        uint8_t _sensorInstanceId = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSensorInstanceId();
                        uint16_t _eventDefinationID = manifest::eventContextMappings[_index].getMappedSecurityEvent().getSecurityEventDefinition().getId();
                        uint16_t _idsMInstanceID = manifest::eventContextMappings[_index].getIdsmInstance();

                        size_t _offset = payload[0]+1;
                        uint32_t _nanoseconds = ara::com::helper::ExtractInteger(payload, _offset);
                        uint32_t _seconds = ara::com::helper::ExtractInteger(payload, _offset);

                        std::vector<uint8_t> _dataContext = std::vector<uint8_t>(payload.begin()+_offset, payload.end()-1);
                        
                        uint8_t _count = *(payload.rbegin());

                        ids::IDSMessage _message( ids::EventFrame( 10,  // protocolVersion
                                                                    ids::ProtocolHeader(0,1,1),
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
                } 
            }

            void IDSM::InvokeEventHandler(const ara::com::someip::rpc::SomeIpRpcMessage &request)
            {  
                request.print(); 
                if(isValidMessage(request))
                {
                    logic(request);
                }
                else
                {
                    // ignore
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
                        std::cout << "------------------------------------------------\n";
                        std::cout << ".....sent message..... \n";
                        ids::IDSMessage toSend  = ids::IDSMessage::Deserialize(_payload);
                        toSend.print();
                        std::cout << "--------------------------------------------------\n";
                        
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