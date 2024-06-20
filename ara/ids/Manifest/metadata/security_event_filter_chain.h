#ifndef SECURITY_EVENT_FILTER_CHAIN_H
#define SECURITY_EVENT_FILTER_CHAIN_H

#include "security_event_one_every_n_filter.h"
#include "security_event_state_filter.h"
#include "security_event_threshold_filter.h"
#include "security_event_aggregation_filter.h"
#include "../shared/shared_stateFilters.h"
#include "../shared/shared_thresholdFilters.h"
#include "../shared/shared_aggregationFilters.h"
#include "../shared/shared_everyOneNFilters.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventFilterChain
            {
            private:
                /******** attributes ******/
                SecurityEventAggregationFilter aggregation;
                SecurityEventOneEveryNFilter oneEveryN;
                SecurityEventStateFilter state;
                SecurityEventThresholdFilter threshold;
                std::string specifier;  // extra attribute

            public:
                /******** getter and setter  ******/
                SecurityEventAggregationFilter getAggregation(){return aggregation;}
                SecurityEventOneEveryNFilter getOneEveryN(){return oneEveryN;}
                SecurityEventStateFilter getState(){return state;}
                SecurityEventThresholdFilter getThreshold(){return threshold;}
                std::string getSpecifier(){return specifier;}
                void setAggregation(SecurityEventAggregationFilter _aggregation){aggregation=_aggregation;}
                void setOneEveryN(SecurityEventOneEveryNFilter _oneEveryN){oneEveryN=_oneEveryN;}
                void setState(SecurityEventStateFilter _state){state=_state;}
                void setThreshold(SecurityEventThresholdFilter _threshold){threshold=_threshold;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}
            
                /********** fundemental function *******/
                void parse(const rapidjson::Value& filterChain) 
                {
                    if (filterChain.HasMember("Aggregation") && filterChain["Aggregation"].IsString()) 
                    {
                        std::string _aggregation = filterChain["Aggregation"].GetString();
                        
                        for(SecurityEventAggregationFilter obj: aggregationFilters)
                        {
                            if(obj.getSpecifier() == _aggregation)
                            {
                                aggregation = obj;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "Aggregation is missing or not a string" << std::endl;
                    }

                    if (filterChain.HasMember("State") && filterChain["State"].IsString()) 
                    {
                        std::string _state = filterChain["State"].GetString();
            
                        for(SecurityEventStateFilter obj: stateFilters)
                        {
                            if(obj.getSpecifier() == _state)
                            {
                                state = obj;
                                break;
                            }
                        }  
                    }
                    else 
                    {
                        std::cerr << "State is missing or not a string" << std::endl;
                    }

                    if (filterChain.HasMember("OneEveryN") && filterChain["OneEveryN"].IsString()) 
                    {
                        std::string _oneEveryN = filterChain["OneEveryN"].GetString();
                        
                        for(SecurityEventOneEveryNFilter obj: everyOneNFilters)
                        {
                            if(obj.getSpecifier() == _oneEveryN)
                            {
                                oneEveryN = obj;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "OneEveryN is missing or not a string" << std::endl;
                    }

                    if (filterChain.HasMember("Threshold") && filterChain["Threshold"].IsString()) 
                    {
                        std::string _threshold = filterChain["Threshold"].GetString();
                        
                        for(SecurityEventThresholdFilter obj: thresholdFilters)
                        {
                            if(obj.getSpecifier() == _threshold)
                            {
                                threshold = obj;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "Threshold is missing or not a string" << std::endl;
                    }

                    if (filterChain.HasMember("Specifier") && filterChain["Specifier"].IsString()) 
                    {
                        specifier = filterChain["Specifier"].GetString();
                    } 
                    else 
                    {
                        std::cerr << "Specifier is missing or not a string" << std::endl;
                    }
                }
            
                /*********** helper functions **********/
                void print(uint8_t identation = 0)
                {
                    if(identation == 2)
                    {
                        std::cout << "  -  Specifier: " << specifier << "\n";

                        std::cout << "  -  Aggregation: " << aggregation.getSpecifier() << "\n";
                        if(aggregation.getSpecifier() != "null")
                            aggregation.print(identation);
                        
                        std::cout << "  -  OneEveryN: " << oneEveryN.getSpecifier() << "\n";
                        if(oneEveryN.getSpecifier() != "null")
                            oneEveryN.print(identation);
                        
                        std::cout << "  -  State: " << state.getSpecifier() << "\n";
                        if(state.getSpecifier() != "null")
                            state.print(identation);
                        
                        std::cout << "  -  Threshold: " << threshold.getSpecifier() << "\n";   
                        if(threshold.getSpecifier() != "null")
                            threshold.print(identation);
                    }
                    else
                    {
                        std::cout << "Specifier: " << specifier << "\n";

                        std::cout << "Aggregation: " << aggregation.getSpecifier() << "\n";
                        if(aggregation.getSpecifier() != "null")
                            aggregation.print(identation);
                        
                        std::cout << "OneEveryN: " << oneEveryN.getSpecifier() << "\n";
                        if(oneEveryN.getSpecifier() != "null")
                            oneEveryN.print(identation);
                        
                        std::cout << "State: " << state.getSpecifier() << "\n";
                        if(state.getSpecifier() != "null")
                            state.print(identation);
                        
                        std::cout << "Threshold: " << threshold.getSpecifier() << "\n";   
                        if(threshold.getSpecifier() != "null")
                            threshold.print(identation);
                    }
                }
            };
        }
    }
}

#endif