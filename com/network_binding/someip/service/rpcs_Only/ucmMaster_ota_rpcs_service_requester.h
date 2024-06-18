#ifndef UCM_MASTER_OTA_REQUESTER_RPCS_H
#define UCM_MASTER_OTA_REQUESTER_RPCS_H

#include "../../../sockets/include/poller.h"
#include "../../../sockets/include/udp_client.h"
#include "../../../../helper/concurrent_queue.h"
#include "../../../../helper/concurrent_queue.h"
#include "../../someipSdMsg/someip_sd_message.h"
#include "../../someipSdMsg/entry/eventgroup_entry.h"
#include "../../someipSdMsg/entry/service_entry.h"
#include "../../someipSdMsg/option/ipv4_endpoint_option.h"
#include "../../someipRpcMsg/someip_rpc_message.h"
#include "../../rpc/socket_rpc_client.h"
#include "../../events/socket_event_client.h"
#include <condition_variable>
#include <iostream>
#include <algorithm>

namespace ara
{
    namespace com
    {
        namespace someip
        {
            /// @brief SOME/IP service discovery namespace
            /// @note The namespace is not part of the ARA standard.
            namespace sd
            {
                class UCMMaster_OTA_RPCSServiceRequester
                {
                public: 
                    /******************************* attributes ******************************/
                    rpc::SocketRpcClient *rpcClient;       

                private: 
                    /******************************* attributes ******************************/
                    uint16_t mServiceId;
                    uint16_t mInstanceId;
                    uint8_t mMajorVersion;
                    uint8_t mMinorVersion;
                    uint16_t mEventgroupId;

                    const uint8_t mProtocolVersion;
                    const uint8_t mInterfaceVersion;
                    const uint8_t mCounter;

                    /******************************* useful variables ************************/

                    // queue at which we get received messages that contained acknowledging entry
                    helper::ConcurrentQueue<sd::SomeIpSdMessage> mMessageBuffer;

                    // mutex object
                    std::mutex mSubscriptionMutex;
                    // trier to take mutex
                    std::unique_lock<std::mutex> mSubscriptionLock;
                    std::condition_variable mSubscriptionConditionVariable;
                    // flag
                    bool mValidNotify;


                     // queue at which we get received messages that contained acknowledging entry
                    helper::ConcurrentQueue<sd::SomeIpSdMessage> mOfferingBuffer;

                    // mutex object
                    std::mutex mOfferingMutex;
                    // trier to take mutex
                    std::unique_lock<std::mutex> mOfferingLock;
                    std::condition_variable mOfferingConditionVariable;
                    // flag
                    bool mOfferingValidNotify;


                    /*********************** poller attributes  *******************/

                    static const size_t cBufferSize{256};
                    helper::ConcurrentQueue<std::vector<uint8_t>> mSendingQueue;
                    AsyncBsdSocketLib::Poller *const mPoller;
                    AsyncBsdSocketLib::UdpClient mUdpSocket;

                    const std::string cNicIpAddress;
                    const std::string cMulticastGroup;
                    const uint16_t cPort;
                    static const std::string cAnyIpAddress;
                    

                    /********************** poller functions  *********************/
                    void onReceive();
                    void onSend();
                    void Send(const SomeIpSdMessage &message);


                    /******************************* internal functions *********************/
                    void InvokeOfferingHandler(SomeIpSdMessage &&message);

                    bool tryExtractOfferedEndpoint(
                        const SomeIpSdMessage &message,
                        std::string &ipAddress,
                        uint16_t &port) const;

                    bool init(uint16_t &_port);

                public:
                    /******************* constructor  *******************************/
                    UCMMaster_OTA_RPCSServiceRequester(
                        uint16_t serviceId,
                        uint16_t instanceId,
                        uint8_t majorVersion,
                        uint8_t minorVersion,
                        uint16_t eventgroupId, 
                        AsyncBsdSocketLib::Poller *poller,
                        std::string nicIpAddress,
                        std::string multicastGroup,
                        uint16_t port,
                        uint8_t protocolVersion,
                        uint8_t interfaceVersion = 1);


                    /******************************* fundemental functions *********************/
                    bool TryGetTransportInfo(int duration, std::string &ipAddress,uint16_t &port);

                    bool TryGetTransportInfo(std::string &ipAddress,uint16_t &port);

                    bool findService();

                    bool findService(uint16_t &_port);


                    /************************** getter  ***************************/
                    AsyncBsdSocketLib::Poller* getPoller();


                    /********************** rpc methods  ***************************/
                    std::future<bool> GetSwClusterInfo(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> GetSwPackages(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> GetVehicleUCMInfo(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);

                    
                    std::future<bool> TransferVehiclePackage(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferStart(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferData(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> GetCampaignHistory(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> SwPackageInventory(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> CancelCampaign(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferExit(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> DeleteTransfer(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);


                    void AllowCampaign();
                                       
                    /*************************  deconstructor  *********************/
                    ~UCMMaster_OTA_RPCSServiceRequester();
                };
            }
        }
    }
}

#endif