#ifndef SECURITY_EVENT_DEFINATION_H
#define SECURITY_EVENT_DEFINATION_H

#include "manifest_types.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventDefinition
            {
            private:
                /******* attributes ******/
                SymbolProps eventSymbolName;
                PositiveInteger id;

            public:
                /********* getter and setter ******/
                SymbolProps getEventSymbolName(){return eventSymbolName;}
                PositiveInteger getId(){return id;}
                void setEventSymbolName(SymbolProps _eventSymbolName){eventSymbolName = _eventSymbolName;}
                void setId(PositiveInteger _id){id = _id;}

                /********** helper functions *******/
                void print(uint8_t identaion = 0)
                {
                    if(identaion == 1)
                    {
                        std::cout << "  -  Defination.SymbolName: " << eventSymbolName << "\n";
                        std::cout << "  -  Defination.id: " << id << "\n";
                    }
                    if(identaion == 2)
                    {
                        std::cout << "    -    Defination.SymbolName: " << eventSymbolName << "\n";
                        std::cout << "    -    Defination.id: " << id << "\n";
                    }
                    else
                    {
                        std::cout << "Defination.SymbolName: " << eventSymbolName << "\n";
                        std::cout << "Defination.id: " << id << "\n";
                    }
                }
            };
        }
    }
}

#endif