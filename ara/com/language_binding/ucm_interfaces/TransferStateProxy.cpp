#include "TransferStateProxy.h"

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
                /******************** constructor ************************/                  
                TransferStateProxy::HandleType::HandleType(InstanceIdentifier id,int16_t p): identifier{id},
                                                                                            port_no{p}
                {}

                /************ setters and getters *************************/
                void TransferStateProxy::HandleType::setId(InstanceIdentifier id)
                {   identifier=id;  }

                void TransferStateProxy::HandleType::setPort(int16_t p)
                {   port_no=p;  }

                int16_t TransferStateProxy::HandleType::getPort()const
                {   return port_no; }

                const InstanceIdentifier& TransferStateProxy::HandleType::GetInstanceId()const
                {   return identifier;  }

                void TransferStateProxy::HandleType::setRequester(FieldServiceRequester *r)
                {   requester = r;  }

                FieldServiceRequester* TransferStateProxy::HandleType::getRequester()
                { return requester; }  

                /*********************** static functions **********************/
                ServiceHandleContainer<TransferStateProxy::HandleType> TransferStateProxy::findSerivce(InstanceIdentifier id)
                {
                    FieldServiceRequester *requester;
                    requester = new FieldServiceRequester(c_ServiceId,
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
                            std::this_thread::yield();    // added
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
                TransferStateProxy::TransferStateProxy (HandleType &handle)
                {
                    requester = handle.getRequester();
                }

                /************************ fundemental funtions *******************/
                void TransferStateProxy::subscribe(size_t maxSampleCount)
                {
                    requester->fieldClient->Subscribe(maxSampleCount);
                }

                helper::SubscriptionState TransferStateProxy::GetSubscriptionState() const
                {
                    return requester->fieldClient->GetSubscriptionState();
                }

                std::future<bool> TransferStateProxy::set(std::vector<uint8_t> &data)
                {
                    return requester->fieldClient->set(data);
                }

                std::future<bool> TransferStateProxy::get(std::vector<uint8_t> &data)
                {
                    return requester->fieldClient->get(data);
                }

                void TransferStateProxy::printSubscriptionState()
                {
                    requester->fieldClient->printCurrentState();
                }

                void TransferStateProxy::SetReceiveHandler(Handler h)
                {
                    requester->fieldClient->SetReceiveHandler(h);
                }

                void TransferStateProxy::UnsetReceiveHandler()
                {
                    requester->fieldClient->UnsetReceiveHandler();
                }

                /********************* deconstructor *******************/  
                TransferStateProxy::~TransferStateProxy()
                {
                    delete requester;
                }
        }
    }

}