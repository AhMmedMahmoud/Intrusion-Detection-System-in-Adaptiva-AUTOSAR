#ifndef SM_RPCS_SKELETON_H
#define SM_RPCS_SKELETON_H

#include "../../network_binding/someip/service/rpcs_Only/sm_rpcs_service_provider.h"
#include "../../helper/instance_id.h"

namespace ara 
{
    namespace com
    {
        namespace skelton
        {
            class SM_RPCS_Skelton : public ara::com::someip::sd::RPCSServiceProvider 
            {                    
                public:
                    /***************** constructor ************************/                 
                    SM_RPCS_Skelton( ara::com::InstanceIdentifier id);
                    
                    /*
                    init
                    offerSerivce
                    */

                    /**************** override abstract functions ********/
                    virtual bool RequestUpdateSessionImp() override;
                    virtual bool PrepareUpdateImp(const std::vector<uint8_t> &list) override;
                    virtual bool VerifyUpdateImp(const std::vector<uint8_t> &list) override;
                    virtual bool PrepareRollbackImp(const std::vector<uint8_t> &list) override;
                    virtual void StopUpdateSessionImp() override;            
                    virtual void ResetMachineImp() override;     

                    /******** disable copy constructor and equal assigment operator *****/
                    SM_RPCS_Skelton(const SM_RPCS_Skelton &other) = delete;
                    SM_RPCS_Skelton & operator=(const SM_RPCS_Skelton &other) = delete;
                    
                    /********************* deconstructor *******************/
                    ~SM_RPCS_Skelton();
            };
            
        }
    }
}

#endif