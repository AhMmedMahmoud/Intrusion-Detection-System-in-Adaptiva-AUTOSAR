#ifndef SECURITY_EVENT_CONTEXT_PROPS_H
#define SECURITY_EVENT_CONTEXT_PROPS_H

#include "manifest_types.h"
#include "security_event_definition.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventContextProps
            {
            private:
                /****** attributes ******/
                SecurityEventContextData contextData;
                SecurityEventReportingModeEnum defaultReportingMode;
                Boolean persistentStorage;
                SecurityEventDefinition securityEvent;
                PositiveInteger sensorInstanceId;
                PositiveInteger severity;
                std::string specifier;  // extra attribute

            public:
                /******** getter and setter  ******/
                SecurityEventContextData getSecurityEventContextData(){return contextData;}
                SecurityEventReportingModeEnum getSecurityEventReportingModeEnum(){return defaultReportingMode;}
                Boolean getPersistentStorage(){return persistentStorage;}
                SecurityEventDefinition getSecurityEventDefinition(){return securityEvent;}
                PositiveInteger getSensorInstanceId(){return sensorInstanceId;}
                PositiveInteger getSeverity(){return severity;}
                std::string getSpecifier(){return specifier;}
                void setSecurityEventContextData(SecurityEventContextData _contextData){contextData = _contextData;}
                void setSecurityEventReportingModeEnum(SecurityEventReportingModeEnum _defaultReportingMode){defaultReportingMode = _defaultReportingMode;}
                void setPersistentStorage(Boolean _persistentStorage){persistentStorage = _persistentStorage;}
                void setSecurityEventDefinition(SecurityEventDefinition _securityEvent){securityEvent = _securityEvent;}
                void setSensorInstanceId(PositiveInteger _sensorInstanceId){sensorInstanceId = _sensorInstanceId;}
                void setSeverity(PositiveInteger _severity){severity = _severity;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}

                /********** fundemental function *******/
                void parse(const rapidjson::Value& event) 
                {
                    if (event.HasMember("Specifier") && event["Specifier"].IsString()) 
                    {
                        specifier = event["Specifier"].GetString();
                    } 
                    else 
                    {
                        std::cerr << "EventTypeSpecifier is missing or not a string" << std::endl;
                    }

                    if (event.HasMember("Definition") && event["Definition"].IsObject()) 
                    {
                        if (event["Definition"].HasMember("SymbolName") && event["Definition"]["SymbolName"].IsString())
                        {
                            securityEvent.setEventSymbolName(event["Definition"]["SymbolName"].GetString());
                        }
                        else
                        {
                            std::cerr << "SymbolName is missing or not a string" << std::endl;
                        }

                        if (event["Definition"].HasMember("ID") && event["Definition"]["ID"].IsInt())
                        {
                            securityEvent.setId(event["Definition"]["ID"].GetInt());                        }
                        else
                        {
                            std::cerr << "ID is missing or not a int" << std::endl;
                        }          
                    }
                    else 
                    {
                        std::cerr << "Definition is missing or not an object" << std::endl;
                    }

                    if (event.HasMember("SensorInstanceID") && event["SensorInstanceID"].IsInt()) 
                    {
                        sensorInstanceId = event["SensorInstanceID"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "SensorInstanceID is missing or not an int" << std::endl;
                    }

                    if (event.HasMember("ReportingMode") && event["ReportingMode"].IsString()) 
                    {
                        std::string _defaultReportingMode = event["ReportingMode"].GetString();
                        if(_defaultReportingMode == "OFF" || _defaultReportingMode == "off")
                            defaultReportingMode = SecurityEventReportingModeEnum::OFF;
                        else if(_defaultReportingMode == "BRIEF" || _defaultReportingMode == "brief")
                            defaultReportingMode = SecurityEventReportingModeEnum::BRIEF;
                        else if(_defaultReportingMode == "DETAILED" || _defaultReportingMode == "detailed")
                            defaultReportingMode = SecurityEventReportingModeEnum::DETAILED;
                        else if(_defaultReportingMode == "BRIEF_BYPASSING_FILTERS" || _defaultReportingMode == "brief_bypassing_filters")
                            defaultReportingMode = SecurityEventReportingModeEnum::BRIEF_BYPASSING_FILTERS;
                        else if(_defaultReportingMode == "DETAILED_BYPASSING_FILTERS" || _defaultReportingMode == "detailed_bypassing_filters")
                            defaultReportingMode = SecurityEventReportingModeEnum::DETAILED_BYPASSING_FILTERS;
                        else
                            std::cerr << "Reporting Mode isnot correct\n" << std::endl;
                    } 
                    else
                    {
                        std::cerr << "ReportingMode is missing or not a string" << std::endl;
                    }

                    if (event.HasMember("Severity") && event["Severity"].IsInt()) 
                    {
                        severity = event["Severity"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "Severity is missing or not an int" << std::endl;
                    }

                    if (event.HasMember("PersistentStorage") && event["PersistentStorage"].IsBool()) 
                    {
                        persistentStorage = event["PersistentStorage"].GetBool();
                    }
                    else
                    {
                        std::cerr << "PersistentStorage is missing or not a bool" << std::endl;
                    }

                    if (event.HasMember("ContextData") && event["ContextData"].IsString()) 
                    {
                        contextData = event["ContextData"].GetString();
                    } 
                    else 
                    {
                        std::cerr << "ContextData is missing or not a string" << std::endl;
                    }
                }

                /******* helper functions *******/
                void print(bool identation = false)
                {
                    if(identation)
                    {
                        std::cout << "  -  Specifier: " << specifier << "\n";
                        std::cout << "  -  ContextData: " << contextData << "\n";
                        std::cout << "  -  ReportingMode: " << static_cast<int>(defaultReportingMode) << "\n";
                        std::cout << "  -  PersistentStorage: " << persistentStorage << "\n";
                        securityEvent.print(identation+1);
                        std::cout << "  -  SensorInstanceId: " << sensorInstanceId << "\n";
                        std::cout << "  -  Severity: " << severity << "\n"; 
                    }
                    else
                    {
                        std::cout << "Specifier: " << specifier << "\n";
                        std::cout << "ContextData: " << contextData << "\n";
                        std::cout << "ReportingMode: " << static_cast<int>(defaultReportingMode) << "\n";
                        std::cout << "PersistentStorage: " << persistentStorage << "\n";
                        securityEvent.print();
                        std::cout << "SensorInstanceId: " << sensorInstanceId << "\n";
                        std::cout << "Severity: " << severity << "\n"; 
                    }
                }
            };
        }
    }
}

#endif