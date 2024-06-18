#include "SM_RPCSProxy.h"

static const std::string c_AnyIpAddress{"0.0.0.0"};
static const std::string c_NicIpAddress{"127.0.0.1"};
static const std::string c_MulticastGroup{"239.0.0.1"};
static const uint16_t c_ServiceDiscoveryFindingPort{6666};
static const uint16_t c_ServiceId = 1;
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
            SM_RPCS_Proxy::HandleType::HandleType(InstanceIdentifier id,int16_t p): identifier{id},
                                                                    port_no{p}
            {}

            /************ setters and getters *************************/
            void SM_RPCS_Proxy::HandleType::setId(InstanceIdentifier id)
            {   identifier=id;  }

            void SM_RPCS_Proxy::HandleType::setPort(int16_t p)
            {   port_no=p;  }

            int16_t SM_RPCS_Proxy::HandleType::getPort()const
            {   return port_no; }

            const InstanceIdentifier& SM_RPCS_Proxy::HandleType::GetInstanceId()const
            {   return identifier;  }

            void SM_RPCS_Proxy::HandleType::setRequester(RPCSServiceRequester *r)
            {   requester = r;  }

            RPCSServiceRequester* SM_RPCS_Proxy::HandleType::getRequester()
            { return requester; }    

            /*********************** static functions **********************/
            ServiceHandleContainer<SM_RPCS_Proxy::HandleType> SM_RPCS_Proxy::findSerivce(InstanceIdentifier id)
            {
                RPCSServiceRequester *requester;
                requester = new RPCSServiceRequester(c_ServiceId,
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
                bool *running = new bool(true);
                std::thread t1([poller,running](){
                    while(*running)
                    {
                        poller->TryPoll(cTimeoutMs);
                        std::this_thread::yield();
                    }
                });

                uint16_t _port;
                bool _result = requester->findService(_port);
                if(!_result)
                {
                    std::vector<HandleType> handles;
                    
                    *running = false;
                    //std::cout << "11111111111111\n";
                    t1.join();
                    delete running;
                    //std::cout << "11111111111111\n";
                    return handles;
                }
                else
                {
                    std::vector<HandleType> handles;
                    HandleType handleTypeObj(id,_port);
                    handleTypeObj.setRequester(requester);
                    handles.push_back(handleTypeObj);
                    
                    *running = false;
                    //std::cout << "2222222222222222222\n";
                    t1.join();
                    delete running;
                    //std::cout << "2222222222222222222\n";
                    return handles;
                }
            }

            /************************* constructor **************************/
            SM_RPCS_Proxy::SM_RPCS_Proxy (HandleType &handle)
            {
                requester = handle.getRequester();
            }

            /************************ fundemental funtions *******************/
            std::future<bool> SM_RPCS_Proxy::RequestUpdateSession(std::vector<uint8_t> &data)
            {
                std::vector<uint8_t> payload;
                return requester->RequestUpdateSession(payload,data);
            }

            std::future<bool> SM_RPCS_Proxy::PrepareUpdate(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->PrepareUpdate(payload,data);
            }

            std::future<bool> SM_RPCS_Proxy::VerifyUpdate(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->VerifyUpdate(payload,data);
            }
            
            std::future<bool> SM_RPCS_Proxy::PrepareRollback(const std::vector<uint8_t> &payload,
                            std::vector<uint8_t> &data)
            {
                return requester->PrepareRollback(payload,data);
            }
           
            void SM_RPCS_Proxy::StopUpdateSession()
            {
                requester->StopUpdateSession();
            }

            void SM_RPCS_Proxy::ResetMachine()
            {
                requester->ResetMachine();
            }

            /********************* deconstructor *******************/
            SM_RPCS_Proxy::~SM_RPCS_Proxy()
            {
                delete requester;
            }
        }
    }

}