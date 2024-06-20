#include "ucmMaster_ota_proxy.h"

static const std::string c_AnyIpAddress{"0.0.0.0"};
static const std::string c_NicIpAddress{"127.0.0.1"};
static const std::string c_MulticastGroup{"239.0.0.1"};
static const uint16_t c_ServiceDiscoveryFindingPort{6666};
static const uint16_t c_ServiceId = 3;
static const uint8_t c_MajorVersion = 10;
static const uint8_t c_MinorVersion = 4;
static const uint16_t c_EventgroupId = 5;
static const uint8_t c_ProtocolVersion = 20;
static const uint16_t c_InterfaceVersion = 2;
static const uint16_t c_ClientId = 1;
static const int cTimeoutMs = 100;


namespace ara 
{
    namespace com
    {
        namespace proxy
        {    
            /******************** constructors ************************/   
            UCMMASTER_OTA_Proxy::HandleType::HandleType(InstanceIdentifier id,int16_t p): identifier{id},
                                                                    port_no{p}
            {}

            /************ setters and getters *************************/
            void UCMMASTER_OTA_Proxy::HandleType::setId(InstanceIdentifier id)
            {   identifier=id;  }

            void UCMMASTER_OTA_Proxy::HandleType::setPort(int16_t p)
            {   port_no=p;  }

            int16_t UCMMASTER_OTA_Proxy::HandleType::getPort()const
            {   return port_no; }

            const InstanceIdentifier& UCMMASTER_OTA_Proxy::HandleType::GetInstanceId()const
            {   return identifier;  }

            void UCMMASTER_OTA_Proxy::HandleType::setRequester(UCMMaster_OTA_RPCSServiceRequester *r)
            {   requester = r;  }

            UCMMaster_OTA_RPCSServiceRequester* UCMMASTER_OTA_Proxy::HandleType::getRequester()
            { return requester; }    

            /*********************** static functions **********************/
            static bool running = true;
            ServiceHandleContainer<UCMMASTER_OTA_Proxy::HandleType> UCMMASTER_OTA_Proxy::findSerivce(InstanceIdentifier id)
            {
                UCMMaster_OTA_RPCSServiceRequester *requester;
                requester = new UCMMaster_OTA_RPCSServiceRequester(c_ServiceId,
                                        id.getInstanceId(),
                                        c_MajorVersion,
                                        c_MinorVersion,
                                        c_EventgroupId,
                                        new AsyncBsdSocketLib::Poller(),
                                        c_NicIpAddress,
                                        c_MulticastGroup,
                                        c_ServiceDiscoveryFindingPort,
                                        c_ProtocolVersion);
                
                Poller *poller = requester->getPoller();

                std::thread t1([poller](){
                    while(running)
                    {
                        std::cout << "before try poll\n";
                        poller->TryPoll(cTimeoutMs);
                        std::cout << "after try poll\n";
                        std::this_thread::yield();    // added
                        std::cout << "after yield\n";
                    }
                });

                uint16_t _port;
                bool _result = requester->findService(_port);
                if(!_result)
                {
                    std::vector<HandleType> handles;
                    
                    running = false;
                    std::cout << "11111111111111\n";
                    t1.join();
                    std::cout << "11111111111111\n";
                    return handles;
                }
                else
                {
                    std::vector<HandleType> handles;
                    HandleType handleTypeObj(id,_port);
                    handleTypeObj.setRequester(requester);
                    handles.push_back(handleTypeObj);
                    
                    std::cout << "2222222222222222222\n";
                    running = false;
                    std::cout << "2222222222222222222\n";
                    std::this_thread::yield();
                    std::cout << "2222222222222222222\n";
                    t1.join();
                    std::cout << "2222222222222222222\n";
                    return handles;
                }

                /******* original *****/
                /*
                Poller *poller = requester->getPoller();
                bool *running = new bool(true);

                std::thread t1([poller,running](){
                    while(*running)
                    {
                        poller->TryPoll(cTimeoutMs);
                        std::this_thread::yield();    // added
                    }
                });

                uint16_t _port;
                bool _result = requester->findService(_port);
                if(!_result)
                {
                    std::vector<HandleType> handles;
                    
                    *running = false;
                    std::cout << "11111111111111\n";
                    t1.join();
                    delete running;
                    std::cout << "11111111111111\n";
                    return handles;
                }
                else
                {
                    std::vector<HandleType> handles;
                    HandleType handleTypeObj(id,_port);
                    handleTypeObj.setRequester(requester);
                    handles.push_back(handleTypeObj);
                    
                    *running = false;
                    std::cout << "2222222222222222222\n";
                    t1.join();
                    delete running;
                    std::cout << "2222222222222222222\n";
                    return handles;
                }
                */
            }

            /************************* constructor **************************/
            UCMMASTER_OTA_Proxy::UCMMASTER_OTA_Proxy (HandleType &handle)
            {
                requester = handle.getRequester();
            }

            /************************ fundemental funtions *******************/
            std::future<bool> UCMMASTER_OTA_Proxy::GetSwClusterInfo(std::vector<uint8_t> &data)
            {
                std::vector<uint8_t> payload;
                return requester->GetSwClusterInfo(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::GetSwPackages(std::vector<uint8_t> &data)
            {
                std::vector<uint8_t> payload;
                return requester->GetSwPackages(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::GetVehicleUCMInfo(std::vector<uint8_t> &data)
            {
                std::vector<uint8_t> payload;
                return requester->GetVehicleUCMInfo(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::TransferVehiclePackage(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->TransferVehiclePackage(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::TransferStart(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->TransferStart(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::TransferData(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->TransferData(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::GetCampaignHistory(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->GetCampaignHistory(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::SwPackageInventory(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->SwPackageInventory(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::CancelCampaign(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->CancelCampaign(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::TransferExit(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->TransferExit(payload,data);
            }

            std::future<bool> UCMMASTER_OTA_Proxy::DeleteTransfer(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->DeleteTransfer(payload,data);
            }

            void UCMMASTER_OTA_Proxy::AllowCampaign()
            {
                requester->AllowCampaign();
            }

            /********************* deconstructor *******************/
            UCMMASTER_OTA_Proxy::~UCMMASTER_OTA_Proxy()
            {
                    delete requester;
            }
        }
    }

}