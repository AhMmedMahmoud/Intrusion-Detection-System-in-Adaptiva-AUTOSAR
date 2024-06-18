#ifndef UCM_MASTER_UCM_SKELETON_H
#define UCM_MASTER_UCM_SKELETON_H

#include "../../network_binding/someip/service/rpcs_Only/ucmMaster_ucm_rpcs_service_provider.h"
#include "../../helper/instance_id.h"

namespace ara 
{
    namespace com
    {
        namespace skelton
        {
            class UCMMASTER_UCM_Skelton : public ara::com::someip::sd::UCMMaster_UCM_RPCSServiceProvider 
            {                    
                public:
                    /***************** constructor ************************/                 
                    UCMMASTER_UCM_Skelton( ara::com::InstanceIdentifier id);
                    
                    /*
                    init
                    offerSerivce
                    */

                    /**************** override abstract functions ********/
                    virtual uint8_t ActivateImp() override;
                    virtual uint8_t FinishImp() override;
                    virtual std::vector<uint8_t> GetIdImp() override;
                    virtual std::vector<uint8_t> GetSwClusterChangeInfoImp() override;
                    virtual std::vector<uint8_t> GetSwPackagesImp() override;
                    virtual std::vector<uint8_t> GetSwClusterInfoImp() override;
                    virtual uint8_t RevertProcessedSwPackagesImp() override;
                    virtual uint8_t RollbackImp() override;
                    virtual uint8_t CancelImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t DeleteTransferImp(const std::vector<uint8_t> &list) override;
                    virtual std::vector<uint8_t> GetHistoryImp(const std::vector<uint8_t> &list) override;
                    virtual std::vector<uint8_t> GetSwClusterManifestInfoImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t GetSwProcessProgressImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t ProcessSwPackageImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t TransferDataImp(const std::vector<uint8_t> &list) override;
                    virtual uint8_t TransferExitImp(const std::vector<uint8_t> &list) override;
                    virtual std::vector<uint8_t> TransferStartImp(const std::vector<uint8_t> &list) override;

                    /******** disable copy constructor and equal assigment operator *****/
                    UCMMASTER_UCM_Skelton(const UCMMASTER_UCM_Skelton &other) = delete;
                    UCMMASTER_UCM_Skelton & operator=(const UCMMASTER_UCM_Skelton &other) = delete;
                    
                    /********************* deconstructor *******************/
                    ~UCMMASTER_UCM_Skelton();
            };
            
        }
    }
}

#endif