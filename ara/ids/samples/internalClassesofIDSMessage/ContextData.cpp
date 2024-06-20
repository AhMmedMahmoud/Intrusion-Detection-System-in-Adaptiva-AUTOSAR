#include <iostream>
#include "../../ids_protocol/context_data/context_data.h"

using namespace ara::idsm::ids;

int main()
{
    std::cout << "context data\n";

    std::vector<uint8_t> data = {1,2,3,4,5,6,7,8,9,10};
    ContextDataFrame c1(ContextDataSize::SHORT,data.size(),data);

    std::cout << "------------\n";
    c1.print();
    std::cout << "------------\n";

    std::vector<uint8_t> c1_vector = c1.Payload();
    std::cout << "#########\n";
    for(uint8_t byte : c1_vector)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }
    std::cout << "#########\n";

    ContextDataFrame d2 = ContextDataFrame::Deserialize(c1_vector);
    std::cout << "------------\n";
    d2.print();
    std::cout << "------------\n";

    return 0;
}