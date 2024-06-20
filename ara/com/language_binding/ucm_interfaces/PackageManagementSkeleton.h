#ifndef PACKAGE_MANAGEMENT_SKELETON_H
#define PACKAGE_MANAGEMENT_SKELETON_H

#include "../../network_binding/someip/service/field_Only/field_service_provider.h"
#include "../../helper/instance_id.h"

namespace ara 
{
    namespace com
    {
        namespace skelton
        {
            class currentStatusSkelton : public ara::com::someip::sd::FieldServiceProvider 
            {                    
                public:
                    /****************** constructor ************************************/
                    currentStatusSkelton( ara::com::InstanceIdentifier id);
                    
                    /*
                    init
                    offerSerivce
                    update
                    getState
                    */

                    /******** disable copy constructor and equal assigment operator *****/
                    currentStatusSkelton(const currentStatusSkelton &other) = delete;
                    currentStatusSkelton & operator=(const currentStatusSkelton &other) = delete;
                         
                    /********************* deconstructor *******************/
                    ~currentStatusSkelton();
            };
        }
    }
}

#endif