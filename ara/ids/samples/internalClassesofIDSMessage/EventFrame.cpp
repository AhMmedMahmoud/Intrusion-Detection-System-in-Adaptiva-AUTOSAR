#include <iostream>
#include "../../ids_protocol/event_frame/event_frame.h"

using namespace ara::idsm::ids;

int main()
{
    /*
     EventFrame( uint8_t protocolVersion,
                 ProtocolHeader protocolHeader,
                 uint16_t idsMInstanceID,
                 uint8_t sensorInstanceID,
                 uint16_t eventDefinationID,
                 uint16_t count
               ) noexcept;
    */

    EventFrame e1( 10,  // Protocol Version
                   ProtocolHeader(0,0,1),
                   4,   // IDSM InstanceID
                   5,   // Sensor Instance ID
                   6,   // Event Defination ID
                   7    // count
                 );

    /*
    EventFrame e2(std::move(e1));

    EventFrame e3(2, ProtocolHeader(0,0,0), 40, 50, 60, 70);

    std::cout << "------------------------\n";
    e1.print();
    std::cout << "------------------------\n";

    std::cout << "------------------------\n";
    e2.print();
    std::cout << "------------------------\n";

    std::cout << "------------------------\n";
    e3.print();
    std::cout << "------------------------\n";

    e3 = std::move(e1);

    std::cout << "------------------------\n";
    e1.print();
    std::cout << "------------------------\n";

    std::cout << "------------------------\n";
    e2.print();
    std::cout << "------------------------\n";

    std::cout << "------------------------\n";
    e3.print();
    std::cout << "------------------------\n";
    */
    
    std::cout << "------------------------\n";
    e1.print();
    std::cout << "------------------------\n";

    /*
    std::vector<uint8_t> e1_vector = e1.Payload();
    for(uint8_t byte : e1_vector)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }

    e1_vector[0] = 229;
    std::cout << "#############\n";
    EventFrame e4 = EventFrame::Deserialize(e1_vector);
    e4.print();
    std::cout << "#############\n";
    */
    return 0;
}