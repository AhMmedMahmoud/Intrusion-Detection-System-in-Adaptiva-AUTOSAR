#include "manifest_manager.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            /*********** constructor ***********/
            ManifestManager::ManifestManager(std::string _jsonFilePath) noexcept : jsonFilePath{_jsonFilePath}
            {}

            /********** getter and setter ******/
            std::string ManifestManager::getJsonFilePath()
            {
                return jsonFilePath;
            }
            
            /******* fundmental functions ******/
            void ManifestManager::setJsonFilePath(std::string _jsonFilePath)
            {
                jsonFilePath = _jsonFilePath;
            }
            
            void ManifestManager::parseJSON() 
            {
                // Open the file
                FILE* fp = fopen(jsonFilePath.c_str(), "rb");
                if (!fp) {
                    std::cerr << "Could not open file: " << jsonFilePath << std::endl;
                    return;
                }

                // Read the file
                char readBuffer[65536];
                rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

                // Parse the JSON
                rapidjson::Document document;
                document.ParseStream(is);
                fclose(fp);

                if (document.HasParseError()) {
                    std::cerr << "Error parsing JSON" << std::endl;
                    return;
                }

                // Parse Filters
                if (document.HasMember("Filters") && document["Filters"].IsArray()) {
                    const rapidjson::Value& filtersArray = document["Filters"];
                    for (rapidjson::SizeType i = 0; i < filtersArray.Size(); i++) 
                    {
                        if(filtersArray[i].HasMember("Specifier") && filtersArray[i].HasMember("Kind") &&
                        filtersArray[i]["Specifier"].IsString() && filtersArray[i]["Kind"].IsString()
                        )
                        {                                            
                            std::string _kind = filtersArray[i]["Kind"].GetString();
                            if(_kind == "Threshold")
                            {
                                SecurityEventThresholdFilter filter;
                                filter.parse(filtersArray[i]);
                                thresholdFilters.push_back(filter);
                            }
                            else if(_kind == "State")
                            {
                                SecurityEventStateFilter filter;
                                filter.parse(filtersArray[i]);
                                stateFilters.push_back(filter);
                            }
                            else if(_kind == "Aggregation")
                            {
                                SecurityEventAggregationFilter filter;
                                filter.parse(filtersArray[i]);
                                aggregationFilters.push_back(filter);
                            }
                            else if(_kind == "OneEveryN")
                            {
                                SecurityEventOneEveryNFilter filter;
                                filter.parse(filtersArray[i]);
                                everyOneNFilters.push_back(filter);
                            }
                            else
                                std::cout << "kind of filter is invalid\n";
                        }
                    }
                } 
                else 
                {
                    std::cerr << "'filters' is missing or not an array" << std::endl;
                }

                // Parse FilterChains
                if (document.HasMember("FilterChains") && document["FilterChains"].IsArray()) {
                    const rapidjson::Value& filterChainsArray = document["FilterChains"];
                    for (rapidjson::SizeType i = 0; i < filterChainsArray.Size(); i++) {
                        SecurityEventFilterChain filterChain;
                        filterChain.parse(filterChainsArray[i]);
                        filterchains.push_back(filterChain);
                    }
                } 
                else 
                {
                    std::cerr << "'FilterChains' is missing or not an array" << std::endl;
                }

                // Parse events
                if (document.HasMember("Events") && document["Events"].IsArray()) {
                    const rapidjson::Value& eventsArray = document["Events"];
                    for (rapidjson::SizeType i = 0; i < eventsArray.Size(); i++) {
                        SecurityEventContextProps event;
                        event.parse(eventsArray[i]);
                        events.push_back(event);
                    }
                } 
                else 
                {
                    std::cerr << "'events' is missing or not an array" << std::endl;
                }

                // Parse SecurityEventContextMapping
                if (document.HasMember("EventContextMapping") && document["EventContextMapping"].IsArray()) {
                    const rapidjson::Value& eventContextMappingsArray = document["EventContextMapping"];
                    for (rapidjson::SizeType i = 0; i < eventContextMappingsArray.Size(); i++) {
                        SecurityEventContextMapping eventContextMapping;
                        eventContextMapping.parse(eventContextMappingsArray[i]);
                        eventContextMappings.push_back(eventContextMapping);
                    }
                } 
                else 
                {
                    std::cerr << "'events' is missing or not an array" << std::endl;
                }
            }


            void ManifestManager::printEventsMetaData()
            {
                for(SecurityEventContextProps obj: events)
                {
                    obj.print();
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printThresholdFiltersMetaData()
            {
                for(SecurityEventThresholdFilter obj: thresholdFilters)
                {
                    obj.print();
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printStateFilterMetaData()
            {
                for(SecurityEventStateFilter obj: stateFilters)
                {
                    obj.print();
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printAggregationFiltersMetaData()
            {
                for(SecurityEventAggregationFilter obj: aggregationFilters)
                {
                    obj.print();
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printOneEveryNFiltersMetaData()
            {
                for(SecurityEventOneEveryNFilter obj: everyOneNFilters)
                {
                    obj.print();
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printFilterChainsMetaData()
            {
                for(SecurityEventFilterChain obj: filterchains)
                {
                    obj.print(1);
                    std::cout << "----------------------\n";
                }
            }
            void ManifestManager::printEventContextMappingsMetaData()
            {
                for(SecurityEventContextMapping obj: eventContextMappings)
                {
                    obj.print(2);
                    std::cout << "----------------------\n";
                }
            }
        }
    }
}