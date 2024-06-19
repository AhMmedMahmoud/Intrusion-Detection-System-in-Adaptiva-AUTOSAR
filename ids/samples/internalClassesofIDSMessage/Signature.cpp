#include <iostream>
#include "../../ids_protocol/signature/signature.h"

using namespace ara::idsm::ids;

int main()
{
    std::cout << "hi signature\n";
    
    std::vector<uint8_t> data = {1,2,3,4,5,6,7,8};
    SignatureFrame s1(data.size(),data);

    std::cout << "---------------\n";
    s1.print();
    std::cout << "---------------\n";

    std::vector<uint8_t> s1_vec = s1.Payload();
    for(uint8_t byte : s1_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }

    SignatureFrame s2 = SignatureFrame::Deserialize(s1_vec);
    std::cout << "---------------\n";
    s2.print();
    std::cout << "---------------\n";
    
    return 0;
}