#ifndef UCM_MASTER_OTA_PROXY_H
#define UCM_MASTER_OTA_PROXY_H

#include "../../network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_requester.h"
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

            class UCMMASTER_OTA_Proxy
            {
                public:
                    class HandleType
                    {
                        private:  
                            /********************** attributes ************************/                     
                            ara::com::InstanceIdentifier identifier;
                            int16_t port_no;
                            UCMMaster_OTA_RPCSServiceRequester *requester;
   
                        public:
                            /******************** constructor ************************/                  
                            HandleType(InstanceIdentifier id,int16_t p);

                            /************ setters and getters *************************/
                            void setId(InstanceIdentifier id);
                            void setPort(int16_t p);
                            int16_t getPort()const;
                            const InstanceIdentifier &GetInstanceId()const;
                            void setRequester(UCMMaster_OTA_RPCSServiceRequester *r);
                            UCMMaster_OTA_RPCSServiceRequester* getRequester();  
                    };


                    /*********************** static functions **********************/
                    static ServiceHandleContainer<HandleType> findSerivce(InstanceIdentifier id);

                    /************************* constructor **************************/
                    UCMMASTER_OTA_Proxy (HandleType &handle);

                    /************************ fundemental funtions *******************/
                    std::future<bool> GetSwClusterInfo(std::vector<uint8_t> &data);     
                    std::future<bool> GetSwPackages(std::vector<uint8_t> &data);     
                    std::future<bool> GetVehicleUCMInfo(std::vector<uint8_t> &data);     
                    std::future<bool> TransferVehiclePackage(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferStart(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferData(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> GetCampaignHistory(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> SwPackageInventory(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> CancelCampaign(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> TransferExit(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    std::future<bool> DeleteTransfer(const std::vector<uint8_t> &payload, std::vector<uint8_t> &data);
                    void AllowCampaign();

                    /******** disable copy constructor and equal assigment operator *****/ 
                    UCMMASTER_OTA_Proxy(const UCMMASTER_OTA_Proxy &other) = delete;
                    UCMMASTER_OTA_Proxy& operator=(const UCMMASTER_OTA_Proxy &other) = delete;

                    /********************* deconstructor *******************/          
                    ~UCMMASTER_OTA_Proxy();

                private:
                    /*************************** atttibutes ****************/
                    HandleType  *Handle;
                    UCMMaster_OTA_RPCSServiceRequester *requester;
            };
        }
    }

}

#endif