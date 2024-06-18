#ifndef SECURITY_EVENT_ONE_EVERY_N_FILTER_H
#define SECURITY_EVENT_ONE_EVERY_N_FILTER_H

#include "manifest_types.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventOneEveryNFilter
            {
            private:
                /******* attributes ******/
                PositiveInteger n = 0;
                std::string specifier = "null";  // extra attribute

            public:
                /******* getter and setter *******/
                PositiveInteger getN(){return n;}
                std::string getSpecifier(){return specifier;}
                void setN(PositiveInteger _n){n = _n;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}

                /********** fundemental function *******/
                void parse(const rapidjson::Value& filter) 
                {                
                    if (filter.HasMember("n") && filter["n"].IsInt()) 
                    {
                        n = filter["n"].GetInt();
                    } 
                    else 
                    {
                        std::cerr << "n is missing or not an integer" << std::endl;
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
                        std::cout << "    -   Specifier: " <<specifier << "\n";
                        //std::cout << "    -   Kind: " << "EveryOneN Filter\n";
                        std::cout << "    -   n: " << n << "\n";
                    }
                    else if(identation == 1)
                    {
                        std::cout << "  -  Specifier: " <<specifier << "\n";
                        //std::cout << "  -  Kind: " << "EveryOneN Filter\n";
                        std::cout << "  -  n: " << n << "\n";
                    }
                    else
                    {
                        std::cout << "Specifier: " <<specifier << "\n";
                        //std::cout << "Kind: " << "EveryOneN Filter\n";
                        std::cout << "n: " << n << "\n";
                    }
                }
            };
        }
    }
}

#endif