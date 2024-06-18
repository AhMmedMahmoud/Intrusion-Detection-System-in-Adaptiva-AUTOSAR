#include <iostream>
#include "../../ids/timestamp/timestamp.h"

using namespace ara::idsm::ids;

int main()
{
    std::cout << "timestamp\n";
    Timestamp t1(TimeStampSource::AUTOSAR, 0x2af0abcd, 0x12345678);
    
    std::cout << "-----------\n";
    t1.print();
    std::cout << "-----------\n";

    std::vector<uint8_t> t1_vector = t1.Payload();
    for(uint8_t byte : t1_vector)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }

    Timestamp t2 = Timestamp::Deserialize(t1_vector);  
    std::cout << "-----------\n";
    t2.print();
    std::cout << "-----------\n";

    return 0;
}