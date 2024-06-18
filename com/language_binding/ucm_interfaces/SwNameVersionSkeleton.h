#ifndef SW_NAME_VERSION_SKELETON_H
#define SW_NAME_VERSION_SKELETON_H

#include "../../network_binding/someip/service/field_Only/field_service_provider.h"
#include "../../helper/instance_id.h"

namespace ara 
{
    namespace com
    {
        namespace skelton
        {
            class requestedPackageSkelton : public ara::com::someip::sd::FieldServiceProvider 
            {                    
                public:
                    /****************** constructor ************************************/
                    requestedPackageSkelton( ara::com::InstanceIdentifier id);
                    
                    /*
                    init
                    offerSerivce
                    update
                    getState
                    */

                    /******** disable copy constructor and equal assigment operator *****/
                    requestedPackageSkelton(const requestedPackageSkelton &other) = delete;
                    requestedPackageSkelton & operator=(const requestedPackageSkelton &other) = delete;
                    
                    /********************* deconstructor *******************/
                    ~requestedPackageSkelton();
            };
        }
    }
}

#endif