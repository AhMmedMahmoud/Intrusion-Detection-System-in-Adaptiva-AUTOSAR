#ifndef IDSM_H
#define IDSM_H

#include "../../com/network_binding/sockets/include/poller.h"
#include "../../com/network_binding/sockets/include/udp_client.h"
#include "../../com/helper/concurrent_queue.h"
#include "../../com/network_binding/someip/someipRpcMsg/someip_rpc_message.h"
#include <functional>
#include <stdint.h>
#include <vector>


namespace ara
{
    namespace idsm
    {
        namespace someip
        {
            class IDSM
            {
            private:
                /*********************** poller attributes  *******************/
                static const size_t cBufferSize{1300};
                ara::com::helper::ConcurrentQueue<std::vector<uint8_t>> mSendingQueue;
                AsyncBsdSocketLib::Poller *const mPoller;
                AsyncBsdSocketLib::UdpClient mUdpSocket;
                AsyncBsdSocketLib::UdpClient mUdpSocket_idsm_to_idsr;
                const std::string cNicIpAddress;
                const std::string cMulticastGroup;
                const uint16_t cPort_Sensors_IDSM;
                const uint16_t cPort_IDSM_IDSR;
                static const std::string cAnyIpAddress;

                /******************************* attributes ******************************/
                uint16_t mServiceId;
                uint16_t mInstanceId;
                uint8_t mMajorVersion;
                uint16_t mEventgroupId;
                const uint8_t mProtocolVersion;
                const uint8_t mInterfaceVersion;                    
                uint16_t cInitialSessionId{1};
                
                /********************** poller functions  *********************/
                void onReceive();
                void onSend();

                /**********************  internal functions  *********************/
                bool isValidMessage(const ara::com::someip::rpc::SomeIpRpcMessage &request);                
                void InvokeEventHandler(const ara::com::someip::rpc::SomeIpRpcMessage &request);
                void logic(const ara::com::someip::rpc::SomeIpRpcMessage &request);

            public:
                /******************* constructor  *******************************/
                /// @brief Constructor
                /// @param poller BSD sockets poller
                /// @param nicIpAddress Network interface controller IPv4 address
                /// @param multicastGroup Multicast group IPv4 address
                /// @param port Multicast UDP port number
                /// @throws std::runtime_error Throws when the UDP socket configuration failed
                IDSM(
                    uint16_t serviceId,
                    uint16_t instanceId,
                    uint8_t majorVersion,
                    uint16_t eventgroupId, 
                    AsyncBsdSocketLib::Poller *poller,
                    std::string nicIpAddress,
                    std::string multicastGroup,
                    uint16_t port_Snesors_IDSM,
                    uint16_t port_IDSM_IDSR,
                    uint8_t protocolVersion,
                    uint8_t interfaceVersion);

                /**************** override deconstructor  *********************/
                ~IDSM();
            };
        }
    }
}

#endif