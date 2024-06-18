#include "ucmMaster_ota_rpcs_service_provider.h"

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

                /******************************* constructors  ******************************/
                UCMMaster_OTA_RPCSServiceProvider::UCMMaster_OTA_RPCSServiceProvider(
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

                    auto _receiver{std::bind(&UCMMaster_OTA_RPCSServiceProvider::onReceive, this)};
                    _successful = mPoller->TryAddReceiver(&mUdpSocket, _receiver);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket receiver failed.");
                    }

                    auto _sender{std::bind(&UCMMaster_OTA_RPCSServiceProvider::onSend, this)};
                    _successful = mPoller->TryAddSender(&mUdpSocket, _sender);
                    if (!_successful)
                    {
                        throw std::runtime_error("Adding UDP socket sender failed.");
                    }
                }


                /******************************* fundemental functions *********************/
                void UCMMaster_OTA_RPCSServiceProvider::init()
                {
                    /********* initilization for rpcs ****************/
                    rpcServer = new rpc::SocketRpcServer( mPoller,
                                                         "127.0.0.1",
                                                          mEndpointRpcsPort,
                                                          mProtocolVersion,
                                                          mInterfaceVersion);

                    

                    HandlerTypeFunc handler_GetSwClusterInfo = std::bind(&UCMMaster_OTA_RPCSServiceProvider::GetSwClusterInfo, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwClusterInfoMethodID, handler_GetSwClusterInfo);
    
                    HandlerTypeFunc handler_GetSwPackages = std::bind(&UCMMaster_OTA_RPCSServiceProvider::GetSwPackages, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetSwPackagesMethodID, handler_GetSwPackages);

                    HandlerTypeFunc handler_GetVehicleUCMInfo = std::bind(&UCMMaster_OTA_RPCSServiceProvider::GetVehicleUCMInfo, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetVehicleUCMInfoMethodID, handler_GetVehicleUCMInfo);

     
                    HandlerTypeFunc handler_TransferVehiclePackage = std::bind(&UCMMaster_OTA_RPCSServiceProvider::TransferVehiclePackage, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferVehiclePackageMethodID, handler_TransferVehiclePackage);                       

                    HandlerTypeFunc handler_TransferStart = std::bind(&UCMMaster_OTA_RPCSServiceProvider::TransferStart, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferStartMethodID, handler_TransferStart);                       
                
                    HandlerTypeFunc handler_TransferData = std::bind(&UCMMaster_OTA_RPCSServiceProvider::TransferData, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferDataMethodID, handler_TransferData);  

                    HandlerTypeFunc handler_GetCampaignHistory = std::bind(&UCMMaster_OTA_RPCSServiceProvider::GetCampaignHistory, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cGetCampaignHistoryMethodID, handler_GetCampaignHistory);                       

                    HandlerTypeFunc handler_SwPackageInventory = std::bind(&UCMMaster_OTA_RPCSServiceProvider::SwPackageInventory, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cSwPackageInventoryMethodID, handler_SwPackageInventory);                       

                    HandlerTypeFunc handler_CancelCampaign = std::bind(&UCMMaster_OTA_RPCSServiceProvider::CancelCampaign, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cCancelCampaignMethodID, handler_CancelCampaign);                       

                    HandlerTypeFunc handler_TransferExit = std::bind(&UCMMaster_OTA_RPCSServiceProvider::TransferExit, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cTransferExitMethodID, handler_TransferExit);                       

                    HandlerTypeFunc handler_DeleteTransfer = std::bind(&UCMMaster_OTA_RPCSServiceProvider::DeleteTransfer, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cDeleteTransferMethodID, handler_DeleteTransfer); 


                    HandlerTypeFunc handler_AllowCampaign = std::bind(&UCMMaster_OTA_RPCSServiceProvider::AllowCampaign, this, std::placeholders::_1, std::placeholders::_2);
                    rpcServer->SetHandler(mServiceId, cAllowCampaignMethodID, handler_AllowCampaign);
                }


                void UCMMaster_OTA_RPCSServiceProvider::offerService()
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


                void UCMMaster_OTA_RPCSServiceProvider::stopService()
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
                void UCMMaster_OTA_RPCSServiceProvider::onReceive()
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

                void UCMMaster_OTA_RPCSServiceProvider::onSend()
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


                void UCMMaster_OTA_RPCSServiceProvider::Send(const SomeIpSdMessage &message)
                {
                    std::vector<uint8_t> _payload{message.Payload()};
                    mSendingQueue.TryEnqueue(std::move(_payload));
                }


                AsyncBsdSocketLib::Poller* UCMMaster_OTA_RPCSServiceProvider::getPoller()
                {
                    return mPoller;
                }


                /******************* functions *****************************/
                bool UCMMaster_OTA_RPCSServiceProvider::GetSwClusterInfo(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwClusterInfo is called\n";

                    std::vector<uint8_t> funcResult = GetSwClusterInfoImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::GetSwPackages(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetSwPackages is called\n";

                    std::vector<uint8_t> funcResult = GetSwPackagesImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::GetVehicleUCMInfo(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetVehicleUCMInfo is called\n";

                    std::vector<uint8_t> funcResult = GetVehicleUCMInfoImp();

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }





                bool UCMMaster_OTA_RPCSServiceProvider::TransferVehiclePackage(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferVehiclePackage is called\n";

                    uint8_t funcResult = TransferVehiclePackageImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::TransferStart(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferStart is called\n";

                    uint8_t funcResult = TransferStartImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::TransferData(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nTransferData is called\n";

                    uint8_t funcResult = TransferDataImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::GetCampaignHistory(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nGetCampaignHistory is called\n";

                    std::vector<uint8_t> funcResult = GetCampaignHistoryImp(input);

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::SwPackageInventory(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nSwPackageInventory is called\n";

                    std::vector<uint8_t> funcResult = SwPackageInventoryImp(input);

                    output = funcResult; // Put the sum in the output vector

                    return true;
                }                                

                bool UCMMaster_OTA_RPCSServiceProvider::CancelCampaign(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nCancelCampaign is called\n";

                    uint8_t funcResult = CancelCampaignImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::TransferExit(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nCancelCampaignTransferExit is called\n";

                    uint8_t funcResult = TransferExitImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }

                bool UCMMaster_OTA_RPCSServiceProvider::DeleteTransfer(const std::vector<uint8_t> &input, std::vector<uint8_t> &output) 
                {
                    std::cout << "\nDeleteTransfer is called\n";

                    uint8_t funcResult = DeleteTransferImp(input);

                    output.push_back(funcResult); // Put the sum in the output vector

                    return true;
                }


                bool UCMMaster_OTA_RPCSServiceProvider::AllowCampaign(const std::vector<uint8_t> &input, std::vector<uint8_t> &output)
                {
                    AllowCampaignImp();
                    return false;
                }
               
                /**************************** deconstructor  ************************/
                UCMMaster_OTA_RPCSServiceProvider::~UCMMaster_OTA_RPCSServiceProvider()
                {
                    mPoller->TryRemoveSender(&mUdpSocket);
                    mPoller->TryRemoveReceiver(&mUdpSocket);
                    delete mPoller;
                }
            }
        }
    }
}