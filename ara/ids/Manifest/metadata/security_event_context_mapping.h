#ifndef SeCURITY_EVENT_CONTEXT_MAPPING_H
#define SeCURITY_EVENT_CONTEXT_MAPPING_H

#include "manifest_types.h"
#include "security_event_filter_chain.h"
#include "security_event_context_props.h"
#include "../shared/shared_filterchains.h"
#include "../shared/shared_events.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventContextMapping
            {
            private:
                /********* attributes *********/
                SecurityEventFilterChain filterChain;
                IdsmInstance idsmInstance;
                SecurityEventContextProps mappedSecurityEvent;

            public:
                /********* getter and setter  *******/
                SecurityEventFilterChain getFilterChain(){return filterChain;}
                IdsmInstance getIdsmInstance(){return idsmInstance;}
                SecurityEventContextProps getMappedSecurityEvent(){return mappedSecurityEvent;}
                void setFilterChain(SecurityEventFilterChain _filterChain){filterChain = _filterChain;}
                void setIdsmInstance(IdsmInstance _idsmInstance){idsmInstance = _idsmInstance;}
                void getMappedSecurityEvent(SecurityEventContextProps _mappedSecurityEvent){mappedSecurityEvent = _mappedSecurityEvent;}
            
                /********** fundemental function *******/
                void parse(const rapidjson::Value& eventContextMapping) 
                {               
                    if (eventContextMapping.HasMember("FilterChain") && eventContextMapping["FilterChain"].IsString()) 
                    {
                        std::string _filterChain = eventContextMapping["FilterChain"].GetString();
                        
                        for(SecurityEventFilterChain obj: filterchains)
                        {
                            if(obj.getSpecifier() == _filterChain)
                            {
                                filterChain = obj;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "FilterChain is missing or not a string" << std::endl;
                    }

                    if (eventContextMapping.HasMember("Event") && eventContextMapping["Event"].IsString()) 
                    {
                        std::string _event = eventContextMapping["Event"].GetString();
                        
                        for(SecurityEventContextProps obj: events)
                        {
                            if(obj.getSpecifier() == _event)
                            {
                                mappedSecurityEvent = obj;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "Event is missing or not a string" << std::endl;
                    }

                    if (eventContextMapping.HasMember("IdsmInstance") && eventContextMapping["IdsmInstance"].IsInt()) 
                    {
                        idsmInstance = eventContextMapping["IdsmInstance"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "IdsmInstance is missing or not a string" << std::endl;
                    }
                }
            
                /*********** helper functions **********/
                void print(uint8_t identation = 0)
                {
                    std::cout << "FilterChain: " << filterChain.getSpecifier() << "\n";
                    filterChain.print(identation);
                    std::cout << "IdsmInstance: " << idsmInstance << "\n";
                    std::cout << "Event: " << mappedSecurityEvent.getSpecifier() << "\n";
                    mappedSecurityEvent.print(identation);
                }
            };  
        }
    }
}

#endif