#ifndef SECURITY_EVENT_AGGREGATION_FILTER_H
#define SECURITY_EVENT_AGGREGATION_FILTER_H

#include "manifest_types.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventAggregationFilter
            {
            private:
                /********* attributes  ********/
                SecurityEventContextDataSourceEnum contextDataSource = SecurityEventContextDataSourceEnum::NOT_REPORTER;
                TimeValue minimumIntervalLength = 0;
                std::string specifier = "null";  // extra attribute
            
            public:
                /********* getter and setter ******/
                SecurityEventContextDataSourceEnum getContextDataSource(){return contextDataSource;}
                TimeValue getMinimumIntervalLength(){return minimumIntervalLength;}
                std::string getSpecifier(){return specifier;}
                void setContextDataSource(SecurityEventContextDataSourceEnum _contextDataSource){contextDataSource = _contextDataSource;}
                void setMinimumIntervalLength(TimeValue _minimumIntervalLength){minimumIntervalLength = _minimumIntervalLength;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}

                /********** fundemental function *******/
                void parse(const rapidjson::Value& filter) 
                {                
                    if (filter.HasMember("IntervalLength") && filter["IntervalLength"].IsInt()) 
                    {
                        minimumIntervalLength = filter["IntervalLength"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "minimumIntervalLength is missing or not a int" << std::endl;
                    }

                    if (filter.HasMember("Specifier") && filter["Specifier"].IsString()) 
                    {
                        specifier = filter["Specifier"].GetString();
                    } 
                    else 
                    {
                        std::cerr << "Specifier is missing or not a string" << std::endl;
                    }
                }
            
                /*********** helper functions **********/
                void print(uint8_t identation = 0)
                {
                    if(identation == 1)
                    {
                        std::cout << "  - Specifier: " <<specifier << "\n";
                        //std::cout << "  - Kind: " << "Aggregation Filter\n";
                        std::cout << "  - IntervalLength: " << minimumIntervalLength << "\n";
                    }
                    else if(identation == 2)
                    {
                        std::cout << "    -   Specifier: " <<specifier << "\n";
                        //std::cout << "    -   Kind: " << "Aggregation Filter\n";
                        std::cout << "    -   IntervalLength: " << minimumIntervalLength << "\n";
                    }
                    else
                    {
                        std::cout << "Specifier: " <<specifier << "\n";
                        //std::cout << "Kind: " << "Aggregation Filter\n";
                        std::cout << "IntervalLength: " << minimumIntervalLength << "\n";
                    }
                }
            };
        }
    }
}
#endif