#ifndef MANIFEST_MANAGER_H
#define MANIFEST_MANAGER_H

#include "../metadata/security_event_context_props.h"
#include "../metadata/manifest_headers.h"
#include "../metadata/manifest_types.h"
#include "../metadata/security_event_context_props.h"
#include "../metadata/security_event_filter_chain.h"
#include "../shared/shared_stateFilters.h"
#include "../shared/shared_thresholdFilters.h"
#include "../shared/shared_aggregationFilters.h"
#include "../shared/shared_everyOneNFilters.h"
#include "../shared/shared_events.h"
#include "../shared/shared_eventContextMappings.h"
#include "../shared/shared_filterchains.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class ManifestManager
            {
            private:
                /************ attributes ***********/
                std::string jsonFilePath;
            public: 
                /*********** constructor ***********/
                ManifestManager(std::string _jsonFilePath) noexcept;

                /********** getter and setter ******/
                std::string getJsonFilePath();
                void setJsonFilePath(std::string _jsonFilePath);
                
                /******* fundmental functions ******/
                void parseJSON(); 
                void printEventsMetaData();
                void printThresholdFiltersMetaData();
                void printStateFilterMetaData();
                void printAggregationFiltersMetaData();
                void printOneEveryNFiltersMetaData();
                void printFilterChainsMetaData();
                void printEventContextMappingsMetaData();

                static int find(std::string specifer)
                {
                    for(int i = 0; i < eventContextMappings.size(); i++)
                    {
                        if(eventContextMappings[i].getMappedSecurityEvent().getSpecifier() == specifer)
                            return i;
                    }
                    return -1;
                }
            };
        }
    }
}

#endif