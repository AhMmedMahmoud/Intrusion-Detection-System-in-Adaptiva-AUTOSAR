#ifndef SECURITY_EVENT_STATE_FILTER_H
#define SECURITY_EVENT_STATE_FILTER_H

#include "manifest_types.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            class SecurityEventStateFilter
            {
            private:
                /********* attributes *******/
                ModeDeclaration blockIfStateActiveAp;
                std::string specifier = "null";  // extra attribute

            public: 
                /****** getter and setter  ******/
                ModeDeclaration getBlockIfStateActiveAp(){return blockIfStateActiveAp;}
                std::string getSpecifier(){return specifier;}
                void setBlockIfStateActiveAp(ModeDeclaration _blockIfStateActiveAp){blockIfStateActiveAp = _blockIfStateActiveAp;}
                void setSpecifier(std::string _specifier){specifier =_specifier;}

                /********** fundemental function *******/
                void parse(const rapidjson::Value& filter) 
                {
                    if (filter.HasMember("blockIfStateActiveAp") && filter["blockIfStateActiveAp"].IsArray()) 
                    {
                        const rapidjson::Value& stateArray = filter["blockIfStateActiveAp"];
                        for (rapidjson::SizeType j = 0; j < stateArray.Size(); j++) 
                        {
                            if (stateArray[j].IsString()) 
                            {
                                blockIfStateActiveAp.push_back(stateArray[j].GetString());
                            } 
                            else 
                            {
                                std::cerr << "blockIfStateActiveAp element is not a string" << std::endl;
                            }
                        }
                    } 
                    else 
                    {
                        std::cerr << "blockIfStateActiveAp is missing or not an array" << std::endl;
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
                        //std::cout << "    -   Kind: " << "State Filter\n";
                        std::cout << "    -   Blocking State: ";
                        for(std::string _state : blockIfStateActiveAp)
                        {
                            std::cout << _state << "\t";
                        }
                        std::cout << "\n";
                    }
                    else if(identation == 1)
                    {      
                        std::cout << "  -  Specifier: " <<specifier << "\n";
                        //std::cout << "  -  Kind: " << "State Filter\n";
                        std::cout << "  -  Blocking State: ";
                        for(std::string _state : blockIfStateActiveAp)
                        {
                            std::cout << _state << "\t";
                        }
                        std::cout << "\n";
                    }
                    else
                    {
                        std::cout << "Specifier: " <<specifier << "\n";
                        //std::cout << "Kind: " << "State Filter\n";
                        std::cout << "Blocking State: ";
                        for(std::string _state : blockIfStateActiveAp)
                        {
                            std::cout << _state << "\t";
                        }
                        std::cout << "\n";
                    }
                }
            };
        }
    }
}

#endif