#include "ucmMaster_ota_rpcs_service_requester.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace sd
            {
                /******************* constants *************/
                const uint16_t  cGetSwClusterInfoMethodID = 4000;
                const uint16_t  cGetSwPackagesMethodID = 4001;
                const uint16_t  cGetVehicleUCMInfoMethodID = 4002;
                
                const uint16_t  cTransferVehiclePackageMethodID = 4003;
                const uint16_t  cTransferStartMethodID = 4004;
                const uint16_t  cTransferDataMethodID = 4005;
                const uint16_t  cGetCampaignHistoryMethodID = 4006;
                const uint16_t  cSwPackageInventoryMethodID = 4007;
                const uint16_t  cCancelCampaignMethodID = 4008;
                const uint16_t  cTransferExitMethodID = 4009;
                const uint16_t  cDeleteTransferMethodID = 4010;
                
                const uint16_t  cAllowCampaignMethodID = 4011;
                
                const std::string UCMMaster_OTA_RPCSServiceRequester::cAnyIpAddress("0.0.0.0");



                /********************** rpc methods  ***************************/
                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::GetSwClusterInfo(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cGetSwClusterInfoMethodID, mCounter, payload, data);
                }  

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::GetSwPackages(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cGetSwPackagesMethodID, mCounter, payload, data);
                }  

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::GetVehicleUCMInfo(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cGetVehicleUCMInfoMethodID, mCounter, payload, data);
                }  



                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::TransferVehiclePackage(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cTransferVehiclePackageMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::TransferStart(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cTransferStartMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::TransferData(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cTransferDataMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::GetCampaignHistory(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cGetCampaignHistoryMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::SwPackageInventory(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cSwPackageInventoryMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::CancelCampaign(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cCancelCampaignMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::TransferExit(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cTransferExitMethodID, mCounter, payload, data);
                } 

                std::future<bool> UCMMaster_OTA_RPCSServiceRequester::DeleteTransfer(const std::vector<uint8_t> &payload,
                                   std::vector<uint8_t> &data)
                {
                    return rpcClient->RequestWithoutHandler(mServiceId, cDeleteTransferMethodID, mCounter, payload, data);
                }                 


                void UCMMaster_OTA_RPCSServiceRequester::AllowCampaign()
                {
                    std::vector<uint8_t> payload;
                    rpcClient->RequestWithoutResponse(mServiceId, cAllowCampaignMethodID, mCounter, payload);
                }    
       
                /******************************* internal functions *********************/
                bool UCMMaster_OTA_RPCSServiceRequester::init(uint16_t &_port)
                {
                    std::string ip;
                    uint16_t port;
                    std::cout << "waiting for ip address and port number from service discovery\n";
                    bool _result = TryGetTransportInfo(4000, ip, port);
                    //bool _result = TryGetTransportInfo(ip, port);
                    if(!_result)
                        return false;
                    
                    std::cout << "service discovery sends ip address and port nuumber\n";

                    rpcClient = new rpc::SocketRpcClient(mPoller,
                                                    ip,
                                                    port,
                                                    mProtocolVersion,
                                                    mInterfaceVersion);
                    
                    std::cout << "rpc socket client is created";     
                    return _result;
                }
                
                

                /******************************* constructors  ******************************/
                UCMMaster_OTA_RPCSServiceRequester::UCMMaster_OTA_RPCSServiceRequester(
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
                    uint8_t interfaceVersion) : mServiceId{serviceId},
                                                mInstanceId{instanceId},
                                                mMajorVersion{majorVersion},
                                                mMinorVersion{minorVersion},
                                                mEventgroupId{eventgroupId},
                        
                                                mProtocolVersion{protocolVersion},
                                                mInterfaceVersion{interfaceVersion},
                                                mCounter{0},

                                                mSubscriptionLock(mSubscriptionMutex, std::defer_lock),
                                                mValidNotify{true},
                                                
                                                mOfferingLock(mOfferingMutex, std::defer_lock),
                                                mOfferingValidNotify{true},

                                                mPoller{poller},
                                                cNicIpAddress{nicIpAddress},
                                                cMulticastGroup{multicastGroup},
                                                cPort{port},
                                                mUdpSocket(cAnyIpAddress, port, nicIpAddress, multicastGroup)
                {
                    bool _successful{mUdpSocket.TrySetup()};
                    if (!_successful)
                    {
                        throw std::runtime_error("UDP socket setup failed.");
                    }

                    auto _receiver{std::bind(&UCMMaster_OTA_RPCSServiceRequester::onReceive, this)};
                    _successful = mPoller->TryAddReceiver(&mUdpSocket, _receiver);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket receiver failed.");
                    }

                    auto _sender{std::bind(&UCMMaster_OTA_RPCSServiceRequester::onSend, this)};
                    _successful = mPoller->TryAddSender(&mUdpSocket, _sender);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket sender failed.");
                    }
                }


                /******************************* fundemental functions *********************/
                void UCMMaster_OTA_RPCSServiceRequester::InvokeOfferingHandler(sd::SomeIpSdMessage &&message)
                {
                    for (auto &entry : message.Entries())
                    {
                        if (entry->Type() == entry::EntryType::Offering)
                        {
                            if (auto _serviceEnty = dynamic_cast<entry::ServiceEntry *>(entry.get()))
                            {
                                bool _result = (_serviceEnty->ServiceId() != mServiceId || (_serviceEnty->InstanceId() != mInstanceId));
                                if(_result)
                                {
                                   std::cout << "receive offering message but not for me\n";
                                   break;
                                }
                            }
                            
                            std::cout << "\n------------------------------------------------\n";
                            std::cout << ".....received message..... \n";
                            message.print();
                            std::cout << "-------------------------------------------------\n\n";
                            bool _enqueued = mOfferingBuffer.TryEnqueue(std::move(message));
                            if (_enqueued)
                            {
                                mOfferingConditionVariable.notify_one();
                            }
                            break;
                        }
                    }
                }
                
                bool UCMMaster_OTA_RPCSServiceRequester::findService()
                {
                    // create SOMEIP/SD message
                    SomeIpSdMessage mFindServieMessage;

                    // prepare offering entry 
                    auto _findServiceEntry{entry::ServiceEntry::CreateFindServiceEntry(mServiceId,0xfffffff,mInstanceId,mMajorVersion,mMinorVersion)};
                    
                    // add this entry to the message
                    mFindServieMessage.AddEntry(std::move(_findServiceEntry));

                    // send the message
                    Send(mFindServieMessage);

                    uint16_t _port;
                    bool _result = init(_port);
                    if(_result)
                    {
                        std::cout << "connecting to service instace is done\n";
                    }
                    else
                    {
                        std::cout << "connecting to service instace is fail\n";
                    }
                    return _result;
                }

                bool UCMMaster_OTA_RPCSServiceRequester::tryExtractOfferedEndpoint(
                    const SomeIpSdMessage &message,
                    std::string &ipAddress, uint16_t &port) const
                {
                    for (size_t i = 0; i < message.Entries().size(); ++i)
                    {
                        auto entry = message.Entries().at(i).get();

                        // Endpoints are end-up in the first options
                        for (size_t j = 0; entry->FirstOptions().size(); ++j)
                        {
                            auto option = entry->FirstOptions().at(j).get();

                            if (option->Type() == option::OptionType::IPv4Endpoint)
                            {
                                auto cEndpoint{
                                    dynamic_cast<const option::Ipv4EndpointOption *>(
                                        option)};

                                if (cEndpoint &&
                                    cEndpoint->L4Proto() == option::Layer4ProtocolType::Tcp)
                                {
                                    ipAddress = cEndpoint->IpAddress().ToString();
                                    port = cEndpoint->Port();

                                    return true;
                                }
                            }
                        }
                    }
                    return false;
                }


                bool UCMMaster_OTA_RPCSServiceRequester::TryGetTransportInfo(int duration, std::string &ipAddress,uint16_t &port)
                {
                    bool _result;

                    if (mMessageBuffer.Empty())
                    {
                        std::cout << "-- buffer of received messages is empty --\n";
                        mOfferingLock.lock();
                        std::cv_status _status = mOfferingConditionVariable.wait_for(
                                mOfferingLock, std::chrono::milliseconds(duration));
                        mOfferingLock.unlock();
                        _result = mOfferingValidNotify && (_status != std::cv_status::timeout);
                    }
                    else
                    {
                        std::cout << "-- buffer of receiver messages has messages --\n";
                        // There are still processed subscription messages in the buffer, so no need to wait.
                        _result = true;
                    }

                    // In the case of successful get, set the first processed subscription to the output argument
                    if (_result)
                    {
                        std::cout << "-- fill passed message with received message --\n";
                        SomeIpSdMessage message;
                        _result = mOfferingBuffer.TryDequeue(message);
                        if(_result)
                        {
                            _result = tryExtractOfferedEndpoint(message,ipAddress,port);
                        }
                    }

                    return _result;
                }

                bool UCMMaster_OTA_RPCSServiceRequester::TryGetTransportInfo(std::string &ipAddress,uint16_t &port)
                {
                    bool _result;

                    if (mMessageBuffer.Empty())
                    {
                        std::cout << "-- buffer of received messages is empty --\n";
                        mOfferingLock.lock();
                        std::cout << "before mOfferingConditionVariable.wait(mOfferingLock) \n";
                        mOfferingConditionVariable.wait(mOfferingLock);
                        std::cout << "after mOfferingConditionVariable.wait(mOfferingLock) \n";
                        mOfferingLock.unlock();
                        _result = mOfferingValidNotify;
                    }
                    else
                    {
                        std::cout << "-- buffer of receiver messages has messages --\n";
                        // There are still processed subscription messages in the buffer, so no need to wait.
                        _result = true;
                    }

                    // In the case of successful get, set the first processed subscription to the output argument
                    if (_result)
                    {
                        std::cout << "-- fill passed message with received message --\n";
                        SomeIpSdMessage message;
                        _result = mOfferingBuffer.TryDequeue(message);
                        if(_result)
                        {
                            _result = tryExtractOfferedEndpoint(message,ipAddress,port);
                        }
                    }

                    return _result;
                }

                bool UCMMaster_OTA_RPCSServiceRequester::findService(uint16_t &_port)
                {
                    // create SOMEIP/SD message
                    SomeIpSdMessage mFindServieMessage;

                    // prepare offering entry 
                    auto _findServiceEntry{entry::ServiceEntry::CreateFindServiceEntry(mServiceId,0xfffffff,mInstanceId,mMajorVersion,mMinorVersion)};
                    
                    // add this entry to the message
                    mFindServieMessage.AddEntry(std::move(_findServiceEntry));

                    // send the message
                    Send(mFindServieMessage);

                    bool _result = init(_port);
                    if(_result)
                    {
                        std::cout << "connecting to service instace is done\n";
                    }
                    else
                    {
                        std::cout << "connecting to service instace is fail\n";
                    }
                    return _result;
                }

                /**************************** poller functions  **********************************/
                void UCMMaster_OTA_RPCSServiceRequester::onReceive()
                {
                    // define array to receive serialized SOMEIP/SD message
                    std::array<uint8_t, cBufferSize> _buffer;

                    std::string _ipAddress;
                    uint16_t _port;
              
                    // receive serialized SOMEIP/SD message in form of array not vector
                    ssize_t _receivedSize{mUdpSocket.Receive(_buffer, _ipAddress, _port)};
                    if (_receivedSize > 0 && _port == cPort && _ipAddress == cNicIpAddress)
                    {
                        // convert serialized SOMEIP/SD message from array into vector
                        const std::vector<uint8_t> cRequestPayload(
                            std::make_move_iterator(_buffer.begin()),
                            std::make_move_iterator(_buffer.begin() + _receivedSize));

                        // Create the received message from the received payload
                        sd::SomeIpSdMessage _receivedMessage{sd::SomeIpSdMessage::Deserialize(cRequestPayload)};
                    
                        // call function that contain what to do with received message
                        InvokeOfferingHandler(std::move(_receivedMessage));
                    }
                }

                void UCMMaster_OTA_RPCSServiceRequester::onSend()
                {
                    while (!mSendingQueue.Empty())
                    {
                        //std::cout << "------------ onSend ------------\n";
                        std::vector<uint8_t> _payload;
                        bool _dequeued{mSendingQueue.TryDequeue(_payload)};
                        if (_dequeued)
                        {       
                            // for printing
                            std::cout << "\n------------------------------------------------\n";
                            std::cout << ".....sent message..... \n";
                            SomeIpSdMessage toSend  = SomeIpSdMessage::Deserialize(_payload);
                            toSend.print();
                            std::cout << "--------------------------------------------------\n";
                            
                            std::array<uint8_t, cBufferSize> _buffer;
                            std::copy_n(
                                std::make_move_iterator(_payload.begin()),
                                _payload.size(),
                                _buffer.begin());

                            mUdpSocket.Send(_buffer, cMulticastGroup, cPort);
                        }
                    }
                }

                void UCMMaster_OTA_RPCSServiceRequester::Send(const SomeIpSdMessage &message)
                {
                    std::vector<uint8_t> _payload{message.Payload()};
                    mSendingQueue.TryEnqueue(std::move(_payload));
                }


                AsyncBsdSocketLib::Poller* UCMMaster_OTA_RPCSServiceRequester::getPoller()
                {
                    return mPoller;
                }


                /**************************** deconstructor  ************************/
                UCMMaster_OTA_RPCSServiceRequester::~UCMMaster_OTA_RPCSServiceRequester()
                {
                    // Condition variable notifications are not valid anymore during destruction.
                    mValidNotify = false;
                    // Release the threads waiting for the condition variables before desctruction
                    mSubscriptionConditionVariable.notify_one();

                    mPoller->TryRemoveSender(&mUdpSocket);
                    mPoller->TryRemoveReceiver(&mUdpSocket);
                    
                    delete mPoller;
                }
            }
        }
    }
}