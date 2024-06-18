#include "idsr.h"
#include <iostream>
#include <algorithm>
#include "../ids/ids_message.h"

namespace ara
{
    namespace idsm
    {
        namespace someip
        {
            const std::string IDSR::cAnyIpAddress("0.0.0.0");

            /******************************* constructors  ******************************/
            IDSR::IDSR( uint16_t serviceId,
                        uint16_t instanceId,
                        uint8_t majorVersion,
                        uint16_t eventgroupId, 
                        AsyncBsdSocketLib::Poller *poller,
                        std::string nicIpAddress,
                        std::string multicastGroup,
                        uint16_t port,
                        uint8_t protocolVersion,
                        uint8_t interfaceVersion) : mServiceId{serviceId},
                                                    mInstanceId{instanceId},
                                                    mMajorVersion{majorVersion},
                                                    mEventgroupId{eventgroupId},
                                                    mProtocolVersion{protocolVersion},
                                                    mInterfaceVersion{interfaceVersion},      
                                                    cNicIpAddress{nicIpAddress},
                                                    cMulticastGroup{multicastGroup},
                                                    cPort{port},
                                                    mPoller{poller},
                                                    mUdpSocket(cAnyIpAddress, port, nicIpAddress, multicastGroup)
            {
                bool _successful{mUdpSocket.TrySetup()};
                if (!_successful)
                {
                    throw std::runtime_error("UDP socket setup failed.");
                }

                auto _receiver{std::bind(&IDSR::onReceive, this)};
                _successful = mPoller->TryAddReceiver(&mUdpSocket, _receiver);
                if (!_successful)
                {
                    throw std::runtime_error("Adding UDP socket receiver failed.");
                }
            }

            void IDSR::InvokeEventHandler(ids::IDSMessage request)
            {  
                request.print(); 
            }

            /**************************** poller functions  **********************************/
            void IDSR::onReceive()
            {
                std::cout << "------------------------- onReceive ------------------\n";

                // define array to receive serialized SOMEIP/SD message
                std::array<uint8_t, cBufferSize> _buffer;

                std::string _ipAddress;
                uint16_t _port;

                // receive serialized SOMEIP/SD message in form of array not vector
                ssize_t _receivedSize{mUdpSocket.Receive(_buffer, _ipAddress, _port)};
                if (_receivedSize > 0 && _port == cPort && _ipAddress == cNicIpAddress)
                {
                    const std::vector<uint8_t> cRequestPayload(
                        std::make_move_iterator(_buffer.begin()),
                        std::make_move_iterator(_buffer.begin() + _receivedSize));

                    // Create the received message from the received payload
                    ids::IDSMessage _receivedMessage{ids::IDSMessage::Deserialize(cRequestPayload)};
                    
                    // call function that contain what to do with received message
                    
                    InvokeEventHandler(std::move(_receivedMessage));
                }
            }

            /**************************** deconstructor  ************************/
            IDSR::~IDSR()
            {
                mPoller->TryRemoveReceiver(&mUdpSocket);
            }
        }
    }
}