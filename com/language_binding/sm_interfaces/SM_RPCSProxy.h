#ifndef SM_RPCSP_ROXY_H
#define SM_RPCSP_ROXY_H

#include "../../network_binding/someip/service/rpcs_Only/sm_rpcs_service_requester.h"
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

            class SM_RPCS_Proxy
            {
                public:
                    class HandleType
                    {
                        private:  
                            /********************** attributes ************************/                     
                            ara::com::InstanceIdentifier identifier;
                            int16_t port_no;
                            RPCSServiceRequester *requester;
                      
                        public:
                            /******************** constructor ************************/                  
                            HandleType(InstanceIdentifier id,int16_t p);

                            /************ setters and getters *************************/
                            void setId(InstanceIdentifier id);
                            void setPort(int16_t p);
                            int16_t getPort()const;
                            const InstanceIdentifier &GetInstanceId()const;
                            void setRequester(RPCSServiceRequester *r);
                            RPCSServiceRequester* getRequester();  
                    };

                    /*********************** static functions **********************/
                    static ServiceHandleContainer<HandleType> findSerivce(InstanceIdentifier id);

                    /************************* constructor **************************/
                    SM_RPCS_Proxy (HandleType &handle);
   
                    /************************ fundemental funtions *******************/
                    std::future<bool> RequestUpdateSession(std::vector<uint8_t> &data);                                
                    std::future<bool> PrepareUpdate(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> VerifyUpdate(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> PrepareRollback(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    void StopUpdateSession();
                    void ResetMachine();

                    /******** disable copy constructor and equal assigment operator *****/ 
                    SM_RPCS_Proxy(const SM_RPCS_Proxy &other) = delete;
                    SM_RPCS_Proxy& operator=(const SM_RPCS_Proxy &other) = delete;

                    /********************* deconstructor *******************/          
                    ~SM_RPCS_Proxy();

                private:
                    /*************************** atttibutes ****************/
                    HandleType  *Handle;
                    RPCSServiceRequester *requester;
            };
        }
    }
}

#endif