#include "ucmMaster_ucm_rpcs_service_provider.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace sd
            {
                /******************************* constants **********************************/
                using HandlerTypeFunc = std::function<bool(const std::vector<uint8_t> &, std::vector<uint8_t> &)>;

                const uint16_t  cAcvtivateMethodID = 4002;
                const uint16_t  cFinishMethodID = 4003;
                const uint16_t  cGetIdMethodID = 4004;
                const uint16_t  cGetSwClusterChangeInfoMethodID = 4005;
                const uint16_t  cGetSwPackagesMethodID = 4006;
                const uint16_t  cGetSwClusterInfoMethodID = 4007;
                const uint16_t  cRevertProcessedSwPackagesMethodID = 4008;
                const uint16_t  cRollbackMethodID = 4009;
                const uint16_t  cCancelMethodID  = 4013;
                const uint16_t  cDeleteTransferMethodID  = 4014;
                const uint16_t  cGetHistoryMethodID  = 4015;
                const uint16_t  cGetSwClusterManifestInfoMethodID  = 4016;
                const uint16_t  cGetSwProcessProgressMethodID  = 4017;
                const uint16_t  cProcessSwPackageMethodID  = 4018;
                const uint16_t  cTransferDataMethodID  = 4019;
                const uint16_t  cTransferExitMethodID  = 4020;
                const uint16_t  cTransferStartMethodID  = 4021;

                /******************************* constructors  ******************************/
                UCMMaster_UCM_RPCSServiceProvider::UCMMaster_UCM_RPCSServiceProvider(
                    uint16_t serviceId,
                    uint16_t instanceId,
                    uint8_t majorVersion,
                    uint8_t minorVersion,
                    uint16_t eventgroupId, 
                    AsyncBsdSocketLib::Poller *poller,
                    std::string nicIpAddress,
                    std::string multicastGroup,
                    uint16_t port,
                    uint16_t endpointRpcsPort,
                    //uint16_t endpointEventPort,
                    uint8_t protocolVersion,
                    uint8_t interfaceVersion): mServiceId{serviceId},
                                            mInstanceId{instanceId},
                                            mMajorVersion{majorVersion},
                                            mMinorVersion{minorVersion},
                                            mEventgroupId{eventgroupId},
                                            mProtocolVersion{protocolVersion},
                                            mInterfaceVersion{interfaceVersion},
                                            mPoller{poller},
                                            cNicIpAddress{nicIpAddress},
                                            cMulticastGroup{multicastGroup},
                                            cPort{port},
                                            mEndpointRpcsPort{endpointRpcsPort},
                                            mUdpSocket(cAnyIpAddress, port, nicIpAddress, multicastGroup)
                {
                    bool _successful{mUdpSocket.TrySetup()};
                    if (!_successful)
                    {
                        throw std::runtime_error("UDP socket setup failed.");
                    }

                    auto _receiver{std::bind(&UCMMaster_UCM_RPCSServiceProvider::onReceive, this)};
                    _successful = mPoller->TryAddReceiver(&mUdpSocket, _receiver);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket receiver failed.");
                    }

                    auto _sender{std::bind(&UCMMaster_UCM_RPCSServiceProvider::onSend, this)};
                    _successful = mPoller->TryAddSender(&mUdpSocket, _sender);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket sender failed.");
                    }
                }


                /******************************* fundemental functions *********************/
                void UCMMaster_UCM_RPCSServiceProvider::init()
                {
                    /********* initilization for rpcs ****************/
                    rpcServer = new rpc::SocketRpcServer( mPoller,
                                                         "127.0.0.1",
                                                          mEndpointRpcsPort,
                                                          mProtocolVersion,
                                                          mInterfaceVersion);

                    HandlerTypeFunc handler_Activate = std::bind(&UCMMaster_UCM_RPCSServiceProvider::Activate, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cAcvtivateMethodID, handler_Activate);

                    HandlerTypeFunc handler_Finish = std::bind(&UCMMaster_UCM_RPCSServiceProvider::Finish, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cFinishMethodID, handler_Finish);

                    HandlerTypeFunc handler_GetId = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetId, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetIdMethodID, handler_GetId);

                    HandlerTypeFunc handler_GetSwClusterChangeInfo = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetSwClusterChangeInfo, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwClusterChangeInfoMethodID, handler_GetSwClusterChangeInfo);
               
                    HandlerTypeFunc handler_GetSwPackages = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetSwPackages, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwPackagesMethodID, handler_GetSwPackages);

                    HandlerTypeFunc handler_GetSwClusterInfo = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetSwClusterInfo, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwClusterInfoMethodID, handler_GetSwClusterInfo);
              
                    HandlerTypeFunc handler_RevertProcessedSwPackages = std::bind(&UCMMaster_UCM_RPCSServiceProvider::RevertProcessedSwPackages, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cRevertProcessedSwPackagesMethodID, handler_RevertProcessedSwPackages);              

                    HandlerTypeFunc handler_Rollback = std::bind(&UCMMaster_UCM_RPCSServiceProvider::Rollback, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cRollbackMethodID, handler_Rollback);    

                    HandlerTypeFunc handler_Cancel = std::bind(&UCMMaster_UCM_RPCSServiceProvider::Cancel, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cCancelMethodID, handler_Cancel);     

                    HandlerTypeFunc handler_DeleteTransfer = std::bind(&UCMMaster_UCM_RPCSServiceProvider::DeleteTransfer, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cDeleteTransferMethodID, handler_DeleteTransfer); 

                    HandlerTypeFunc handler_GetHistory = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetHistory, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetHistoryMethodID, handler_GetHistory); 

                    HandlerTypeFunc handler_GetSwClusterManifestInfo = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetSwClusterManifestInfo, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwClusterManifestInfoMethodID, handler_GetSwClusterManifestInfo);  

                    HandlerTypeFunc handler_GetSwProcessProgress = std::bind(&UCMMaster_UCM_RPCSServiceProvider::GetSwProcessProgress, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwProcessProgressMethodID, handler_GetSwProcessProgress);  

                    HandlerTypeFunc handler_ProcessSwPackage = std::bind(&UCMMaster_UCM_RPCSServiceProvider::ProcessSwPackage, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cProcessSwPackageMethodID, handler_ProcessSwPackage); 

                    HandlerTypeFunc handler_TransferData = std::bind(&UCMMaster_UCM_RPCSServiceProvider::TransferData, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferDataMethodID, handler_TransferData);             

                    HandlerTypeFunc handler_TransferExit = std::bind(&UCMMaster_UCM_RPCSServiceProvider::TransferExit, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferExitMethodID, handler_TransferExit);  

                    HandlerTypeFunc handler_TransferStart = std::bind(&UCMMaster_UCM_RPCSServiceProvider::TransferStart, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferStartMethodID, handler_TransferStart);                    
                }


                void UCMMaster_UCM_RPCSServiceProvider::offerService()
                {                    
                    // make SOMEIP/SD message
                    SomeIpSdMessage mOfferServiceMessage;

                    // prepare offering entry
                    auto _offerServiceEntry
                    {
                        entry::ServiceEntry::CreateOfferServiceEntry( mServiceId,
                                                                      mInstanceId,
                                                                      mMajorVersion,
                                                                      mMinorVersion
                                                                    )
                    };

                    helper::Ipv4Address ipAddress("127.0.0.1");

                    // prepare endpoint option
                    auto _offerEndpointOption
                    {
                        option::Ipv4EndpointOption::CreateUnitcastEndpoint( false,
                                                                            ipAddress,
                                                                            option::Layer4ProtocolType::Tcp,
                                                                            mEndpointRpcsPort
                                                                          )
                    };

                    // add created option to created entry 
                    _offerServiceEntry->AddFirstOption(std::move(_offerEndpointOption));
                    
                    // add created entry to created message
                    mOfferServiceMessage.AddEntry(std::move(_offerServiceEntry));

                    // send the message
                    Send(mOfferServiceMessage);
                }


                void UCMMaster_UCM_RPCSServiceProvider::stopService()
                {
                     // make SOMEIP/SD message
                    SomeIpSdMessage mStofServiceMessage;

                    // prepare offering entry
                    auto _offerServiceEntry
                    {
                        entry::ServiceEntry::CreateStopOfferEntry( mServiceId,
                                                                   mInstanceId,
                                                                   mMajorVersion,
                                                                   mMinorVersion
                                                                 )
                    };

                    helper::Ipv4Address ipAddress("127.0.0.1");

                    // prepare endpoint option
                    auto _offerEndpointOption
                    {
                        option::Ipv4EndpointOption::CreateUnitcastEndpoint( false,
                                                                            ipAddress,
                                                                            option::Layer4ProtocolType::Tcp,
                                                                            mEndpointRpcsPort
                                                                          )
                    };

                    // add created option to created entry 
                    _offerServiceEntry->AddFirstOption(std::move(_offerEndpointOption));
                    
                    // add created entry to created message
                    mStofServiceMessage.AddEntry(std::move(_offerServiceEntry));

                    // send the message
                    Send(mStofServiceMessage);
                }

                
                /**************************** poller functions  **********************************/
                void UCMMaster_UCM_RPCSServiceProvider::onReceive()
                {
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
                        sd::SomeIpSdMessage _receivedMessage{sd::SomeIpSdMessage::Deserialize(cRequestPayload)};
                        
                        // call function that contain what to do with received message
                        //InvokeEventHandler(std::move(_receivedMessage));
                    }
                }

                void UCMMaster_UCM_RPCSServiceProvider::onSend()
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


                void UCMMaster_UCM_RPCSServiceProvider::Send(const SomeIpSdMessage &message)
                {
                    std::vector<uint8_t> _payload{message.Payload()};
                    mSendingQueue.TryEnqueue(std::move(_payload));
                }


                AsyncBsdSocketLib::Poller* UCMMaster_UCM_RPCSServiceProvider::getPoller()
                {
                    return mPoller;
                }


                /******************* functions *****************************/
                bool UCMMaster_UCM_RPCSServiceProvider::Activate(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nActivate is called\n";

                    uint8_t funcResult = ActivateImp();

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::Finish(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nFinish is called\n";

                    uint8_t funcResult = FinishImp();

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetId(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetId is called\n";

                    std::vector<uint8_t> funcResult = GetIdImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetSwClusterChangeInfo(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwClusterChangeInfo is called\n";

                    std::vector<uint8_t> funcResult = GetSwClusterChangeInfoImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetSwPackages(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwPackages is called\n";

                    std::vector<uint8_t> funcResult = GetSwPackagesImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetSwClusterInfo(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwClusterInfo is called\n";

                    std::vector<uint8_t> funcResult = GetSwClusterInfoImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::RevertProcessedSwPackages(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nRevertProcessedSwPackages is called\n";

                    uint8_t funcResult = RevertProcessedSwPackagesImp();

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::Rollback(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nRollback is called\n";

                    uint8_t funcResult = RollbackImp();

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::Cancel(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nCancel is called\n";

                    uint8_t funcResult = CancelImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::DeleteTransfer(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nDeleteTransfer is called\n";

                    uint8_t funcResult = DeleteTransferImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetHistory(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetHistory is called\n";

                    std::vector<uint8_t> funcResult = GetHistoryImp(input);

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetSwClusterManifestInfo(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwClusterManifestInfo is called\n";

                    std::vector<uint8_t> funcResult = GetSwClusterManifestInfoImp(input);

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::GetSwProcessProgress(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwProcessProgress is called\n";

                    uint8_t funcResult = GetSwProcessProgressImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::ProcessSwPackage(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nProcessSwPackage is called\n";

                    uint8_t funcResult = ProcessSwPackageImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::TransferData(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferData is called\n";

                    uint8_t funcResult = TransferDataImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::TransferExit(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferExit is called\n";

                    uint8_t funcResult = TransferExitImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_UCM_RPCSServiceProvider::TransferStart(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferStart is called\n";

                    std::vector<uint8_t> funcResult = TransferStartImp(input);

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                /**************************** deconstructor  ************************/
                UCMMaster_UCM_RPCSServiceProvider::~UCMMaster_UCM_RPCSServiceProvider()
                {
                    mPoller->TryRemoveSender(&mUdpSocket);
                    mPoller->TryRemoveReceiver(&mUdpSocket);
                    delete mPoller;
                }
            }
        }
    }
}