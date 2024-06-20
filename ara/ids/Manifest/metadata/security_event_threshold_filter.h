#ifndef SECURITY_EVENT_THRESHOLD_FILTER_H
#define SECURITY_EVENT_THRESHOLD_FILTER_H

#include "manifest_types.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventThresholdFilter
            {
            private:
                /******* attributes *****/
                TimeValue intervalLength = 0;
                PositiveInteger thresholdNumber = 0;
                std::string specifier = "null";  // extra attribute

            public:
                /******* getter and setter ******/
                TimeValue getIntervalLength(){return intervalLength;}
                PositiveInteger getThresholdNumber(){return thresholdNumber;}
                std::string getSpecifier(){return specifier;}
                void setIntervalLength(TimeValue _intervalLength){intervalLength = _intervalLength;}
                void setThresholdNumber(PositiveInteger _thresholdNumber){thresholdNumber = _thresholdNumber;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}
            
                /********** fundemental function *******/
                void parse(const rapidjson::Value& filter) 
                {
                    if (filter.HasMember("IntervalLength") && filter["IntervalLength"].IsInt()) 
                    {
                        intervalLength = filter["IntervalLength"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "IntervalLength is missing or not a integer" << std::endl;
                    }

                    if (filter.HasMember("ThresholdNumber") && filter["ThresholdNumber"].IsInt()) 
                    {
                        thresholdNumber = filter["ThresholdNumber"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "ThresholdNumber is missing or not a integer" << std::endl;
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
                    if(identation == 2)
                    {                 
                        std::cout << "    -    Specifier: " <<specifier << "\n";
                        //std::cout << "  - Kind: " << "Threshold Filter\n";
                        std::cout << "    -    ThesholdNumber: " << thresholdNumber << "\n";
                        std::cout << "    -    IntervalLenght: " << intervalLength << "\n";
                    }
                    else if(identation == 1)
                    {
                        std::cout << "  -  Specifier: " <<specifier << "\n";
                        //std::cout << "  -  Kind: " << "Threshold Filter\n";
                        std::cout << "  -  ThesholdNumber: " << thresholdNumber << "\n";
                        std::cout << "  -  IntervalLenght: " << intervalLength << "\n";
                    }
                    else
                    {
                        std::cout << "Specifier: " <<specifier << "\n";
                        //std::cout << "Kind: " << "Threshold Filter\n";
                        std::cout << "ThesholdNumber: " << thresholdNumber << "\n";
                        std::cout << "IntervalLenght: " << intervalLength << "\n";
                    }

                }
            };
        }
    }
}

#endif