#include "ucmMaster_ucm_skeleton.h"


static const std::string c_AnyIpAddress{"0.0.0.0"};
static const std::string c_NicIpAddress{"127.0.0.1"};
static const std::string c_MulticastGroup{"239.0.0.1"};
static const uint16_t c_ServiceDiscoveryOfferingPort{5555};
static const uint16_t c_Tcp_port = 1700;
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
        namespace skelton
        {
            /***************** constructor ************************/
            UCMMASTER_UCM_Skelton::UCMMASTER_UCM_Skelton( ara::com::InstanceIdentifier id) : UCMMaster_UCM_RPCSServiceProvider
                                                                ( 
                                                                    c_ServiceId,        
                                                                    id.getInstanceId(),
                                                                    c_MajorVersion,                   
                                                                    c_MinorVersion,                       
                                                                    c_EventgroupId,                          
                                                                    new AsyncBsdSocketLib::Poller(),
                                                                    c_NicIpAddress,
                                                                    c_MulticastGroup,
                                                                    c_ServiceDiscoveryOfferingPort,
                                                                    c_Tcp_port,              
                                                                    c_ProtocolVersion
                                                                )  
            {}  

            /**************** override abstract functions ********/
            uint8_t UCMMASTER_UCM_Skelton::ActivateImp()
            {
                return 48;
            }
            uint8_t UCMMASTER_UCM_Skelton::FinishImp()
            {
                return 49;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetIdImp()
            {
                std::vector<uint8_t> data = {1,2,3,4};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetSwClusterChangeInfoImp()
            {
                std::vector<uint8_t> data = {5,6,7,8};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetSwPackagesImp()
            {
                std::vector<uint8_t> data = {1,0,1,0};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetSwClusterInfoImp()
            {
                std::vector<uint8_t> data = {2,0,2,4};
                return data;
            }
            uint8_t UCMMASTER_UCM_Skelton::RevertProcessedSwPackagesImp()
            {
                return 54;
            }
            uint8_t UCMMASTER_UCM_Skelton::RollbackImp()
            {
                return 55;
            }
            uint8_t UCMMASTER_UCM_Skelton::CancelImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 70;
            }
            uint8_t UCMMASTER_UCM_Skelton::DeleteTransferImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 71;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetHistoryImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                std::vector<uint8_t> data = {1,0,1,0};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::GetSwClusterManifestInfoImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                std::vector<uint8_t> data = {1,0,1,0};
                return data;
            }
            uint8_t UCMMASTER_UCM_Skelton::GetSwProcessProgressImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 74;
            }
            uint8_t UCMMASTER_UCM_Skelton::ProcessSwPackageImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 75;
            }
            uint8_t UCMMASTER_UCM_Skelton::TransferDataImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 76;
            }
            uint8_t UCMMASTER_UCM_Skelton::TransferExitImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 77;
            }
            std::vector<uint8_t> UCMMASTER_UCM_Skelton::TransferStartImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                std::vector<uint8_t> data = {1,0,1,0};
                return data;
            }

            /********************* deconstructor *******************/
            UCMMASTER_UCM_Skelton::~UCMMASTER_UCM_Skelton()
            {}
        }
    }
}
