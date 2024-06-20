#ifndef UCM_MASTER_OTA_SKELETON_H
#define UCM_MASTER_OTA_SKELETON_H

#include "../../network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_provider.h"
#include "../../helper/instance_id.h"

namespace ara 
{
    namespace com
    {
        namespace skelton
        {
            class UCMMASTER_OTA_Skelton : public ara::com::someip::sd::UCMMaster_OTA_RPCSServiceProvider 
            {                    
                public:
                    /***************** constructor ************************/                 
                    UCMMASTER_OTA_Skelton( ara::com::InstanceIdentifier id);
                    
                    /*
                    init
                    offerSerivce
                    */

                    /**************** override abstract functions ********/
                    virtual std::vector<uint8_t> GetSwClusterInfoImp() override;
                    virtual std::vector<uint8_t> GetSwPackagesImp() override;
                    virtual std::vector<uint8_t> GetVehicleUCMInfoImp() override;
                    virtual uint8_t TransferVehiclePackageImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t TransferStartImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t TransferDataImp(const std::vector<uint8_t> &list) override;
                    virtual std::vector<uint8_t> GetCampaignHistoryImp(const std::vector<uint8_t> &list) override;
                    virtual std::vector<uint8_t> SwPackageInventoryImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t CancelCampaignImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t TransferExitImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t DeleteTransferImp(const std::vector<uint8_t> &list) override;        
                    virtual void AllowCampaignImp() override;            

                    /******** disable copy constructor and equal assigment operator *****/
                    UCMMASTER_OTA_Skelton(const UCMMASTER_OTA_Skelton &other) = delete;
                    UCMMASTER_OTA_Skelton & operator=(const UCMMASTER_OTA_Skelton &other) = delete;
                    
                    /********************* deconstructor *******************/
                    ~UCMMASTER_OTA_Skelton();
            };
            
        }
    }
}

#endif