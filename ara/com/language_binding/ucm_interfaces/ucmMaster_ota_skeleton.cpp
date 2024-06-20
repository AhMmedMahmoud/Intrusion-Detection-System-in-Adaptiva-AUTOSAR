#include "ucmMaster_ota_skeleton.h"


static const std::string c_AnyIpAddress{"0.0.0.0"};
static const std::string c_NicIpAddress{"127.0.0.1"};
static const std::string c_MulticastGroup{"239.0.0.1"};
static const uint16_t c_ServiceDiscoveryOfferingPort{5555};
static const uint16_t c_Tcp_port = 1200;
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
            UCMMASTER_OTA_Skelton::UCMMASTER_OTA_Skelton( ara::com::InstanceIdentifier id) : UCMMaster_OTA_RPCSServiceProvider
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
            std::vector<uint8_t> UCMMASTER_OTA_Skelton::GetSwClusterInfoImp()
            {
                std::vector<uint8_t> data = {4,5,6,6};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_OTA_Skelton::GetSwPackagesImp()
            {
                std::vector<uint8_t> data = {4,5,6,6};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_OTA_Skelton::GetVehicleUCMInfoImp()
            {
                std::vector<uint8_t> data = {4,5,6,6};
                return data;
            }
            uint8_t UCMMASTER_OTA_Skelton::TransferVehiclePackageImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 80;
            }
            uint8_t UCMMASTER_OTA_Skelton::TransferStartImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 81;
            }
            uint8_t UCMMASTER_OTA_Skelton::TransferDataImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 82;
            }
            std::vector<uint8_t> UCMMASTER_OTA_Skelton::GetCampaignHistoryImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                std::vector<uint8_t> data = {1,1,1,3};
                return data;
            }
            std::vector<uint8_t> UCMMASTER_OTA_Skelton::SwPackageInventoryImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                std::vector<uint8_t> data = {1,1,1,3};
                return data;
            }
            uint8_t UCMMASTER_OTA_Skelton::CancelCampaignImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 85;
            }
            uint8_t UCMMASTER_OTA_Skelton::TransferExitImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 86;
            }
            uint8_t UCMMASTER_OTA_Skelton::DeleteTransferImp(const std::vector<uint8_t> &list) 
            {
                for (const auto &element : list) 
                {
                    std::cout << static_cast<int>(element) << " "; 
                } 
                std::cout << std::endl;
                
                return 87;
            }                                 
            void UCMMASTER_OTA_Skelton::AllowCampaignImp()
            {
                std::cout << "AllowCampaignImp from provider\n";
            }             

            /********************* deconstructor *******************/
            UCMMASTER_OTA_Skelton::~UCMMASTER_OTA_Skelton()
            {}
        }
    }
}
