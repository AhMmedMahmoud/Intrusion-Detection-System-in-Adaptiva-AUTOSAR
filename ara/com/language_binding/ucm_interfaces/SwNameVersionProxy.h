#ifndef SW_NAME_VERSION_PROXY_H
#define SW_NAME_VERSION_PROXY_H

#include "../../network_binding/someip/service/field_Only/field_service_requester.h"
#include "../../helper/instance_id.h"

using namespace ara::com::someip::sd;
using namespace ara::com::helper;
using namespace AsyncBsdSocketLib;

namespace ara 
{
    namespace com
    {
        namespace proxy
        {    
            template <typename t>
            using ServiceHandleContainer = std::vector<t>;

            class requestedPackageProxy
            {
                public:
                    using Handler = std::function<void(const std::vector<uint8_t> &)>;

                    class HandleType
                    {
                        private:  
                            /********************** attributes ************************/                     
                            ara::com::InstanceIdentifier identifier;
                            int16_t port_no;
                            FieldServiceRequester *requester;
  
                        public:
                            /******************** constructors ************************/                      
                            HandleType(InstanceIdentifier id,int16_t p);

                            /************ setters and getters *************************/
                            void setId(InstanceIdentifier id);
                            void setPort(int16_t p);
                            int16_t getPort()const;
                            const InstanceIdentifier &GetInstanceId()const;
                            void setRequester(FieldServiceRequester *r);
                            FieldServiceRequester* getRequester();  
                    };

                    /*********************** static functions **********************/
                    static ServiceHandleContainer<HandleType> findSerivce(InstanceIdentifier id);

                    /************************* constructor **************************/
                    requestedPackageProxy (HandleType &handle);
   
                    /************************ fundemental funtions *******************/
                    void subscribe(size_t maxSampleCount);
                    helper::SubscriptionState GetSubscriptionState() const;
                    std::future<bool> set(std::vector<uint8_t> &data);
                    std::future<bool> get(std::vector<uint8_t> &data);
                    void printSubscriptionState();                  
                    void SetReceiveHandler(Handler h);
                    void UnsetReceiveHandler();

                    /******** disable copy constructor and equal assigment operator *****/                 
                    requestedPackageProxy(const requestedPackageProxy &other) = delete;
                    requestedPackageProxy& operator=(const requestedPackageProxy &other) = delete;

                    /********************* deconstructor *******************/         
                    ~requestedPackageProxy();

                private:
                    /*************************** atttibutes ****************/
                    FieldServiceRequester *requester;
            };
        }
    }
}

#endif