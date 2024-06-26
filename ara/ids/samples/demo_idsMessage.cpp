#include <iostream>
#include "../ids_protocol/ids_message.h"
#include "../../core/initialization.h"

using namespace ara::idsm::ids;

#define EVENTFRAME 0
#define EVENTFRAME_TIMESTAMP 1
#define EVENTFRAME_CONTEXTDATAFRAME 2
#define EVENTFRAME_TIMESTAMP_CONTEXTDATAFRAME 3

#define EVENTFRAME_SIGNATURE 4
#define EVENTFRAME_TIMESTAMP_CONTEXTDATAFRAME_SIGNATURE 5

#define EXAMPLE EVENTFRAME_TIMESTAMP_CONTEXTDATAFRAME_SIGNATURE

int main()
{
    ara::core::Initialize();

    /******** protototypes ***********
    EventFrame( uint8_t protocolVersion,
                ProtocolHeader protocolHeader,
                uint16_t idsMInstanceID,
                uint8_t sensorInstanceID,
                uint16_t eventDefinationID,
                uint16_t count
              );
    
    ContextDataFrame( ContextDataSize frameType,
                      uint32_t lenght,
                      std::vector<uint8_t> data
                    );

    Timestamp( TimeStampSource source,
               uint32_t nanoseconds,
               uint32_t seconds
             );

    ************************************/

    std::vector<uint8_t> data = {1,2,3,4,5,6,7,14,9,10};
    
#if EXAMPLE == EVENTFRAME_TIMESTAMP_CONTEXTDATAFRAME  
    IDSMessage m1(
                    EventFrame (10, ProtocolHeader(0,1,1), 4, 5, 6, 7 ),
                    Timestamp (TimeStampSource::AUTOSAR, 0x2af0abcd, 0x12345678),
                    ContextDataFrame (ContextDataSize::SHORT,data.size(),data)
                 );
    
    m1.print();

    std::cout << "-----------------------\n";
    std::vector<uint8_t> message1_vec = m1.Payload();
    for(uint8_t byte : message1_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    } 
    std::cout << "-----------------------\n";
    
    IDSMessage m1_rec =  IDSMessage::Deserialize(message1_vec);
    m1_rec.print();
#endif

#if EXAMPLE == EVENTFRAME 
    IDSMessage m2(
                    EventFrame (10, ProtocolHeader(0,0,0), 4, 5, 6, 7 )
                 );
    
    m2.print();

    std::cout << "-----------------------\n";
    std::vector<uint8_t> message2_vec = m2.Payload();
    for(uint8_t byte : message2_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }
    std::cout << "-----------------------\n";
    
    IDSMessage m2_rec =  IDSMessage::Deserialize(message2_vec);
    m2_rec.print();
#endif

#if EXAMPLE == EVENTFRAME_TIMESTAMP 
    IDSMessage m3(
                    EventFrame (10, ProtocolHeader(0,1,0), 4, 5, 6, 7 ),
                    Timestamp (TimeStampSource::AUTOSAR, 0x2af0abcd, 0x12345678)
                 );
    
    m3.print();

    std::cout << "-----------------------\n";
    std::vector<uint8_t> message3_vec = m3.Payload();
    for(uint8_t byte : message3_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }
    std::cout << "-----------------------\n";
    
    IDSMessage m3_rec =  IDSMessage::Deserialize(message3_vec);
    m3_rec.print();
#endif

#if EXAMPLE == EVENTFRAME_CONTEXTDATAFRAME
    IDSMessage m4(
                    EventFrame (10, ProtocolHeader(0,0,1), 4, 5, 6, 7 ),
                    ContextDataFrame (ContextDataSize::SHORT,data.size(),data)
                 );
    
    m4.print();

    std::cout << "-----------------------\n";
    std::vector<uint8_t> message4_vec = m4.Payload();
    for(uint8_t byte : message4_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    } 
    std::cout << "-----------------------\n";
    
    message4_vec.push_back(3);
    message4_vec.push_back(3);
    message4_vec.push_back(3);
    IDSMessage m4_rec =  IDSMessage::Deserialize(message4_vec);
    m4_rec.print();
#endif

#if EXAMPLE == EVENTFRAME_SIGNATURE
    IDSMessage m2(
                    EventFrame (10, ProtocolHeader(1,0,0), 4, 5, 6, 7 )
                 );


    std::cout << "-------------print message-------------\n";    
    m2.print();

    std::cout << "--check if message is verified or not--\n";
    std::cout << static_cast<int>(m2.isVerified()) << "\n";

    std::cout << "-------------serialization-------------\n";
    std::vector<uint8_t> message2_vec = m2.Payload();
    for(uint8_t byte : message2_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    }

    std::cout << "-----------deserialization------------\n";    
    IDSMessage m2_rec =  IDSMessage::Deserialize(message2_vec);
    m2_rec.print();
#endif

#if EXAMPLE == EVENTFRAME_TIMESTAMP_CONTEXTDATAFRAME_SIGNATURE  
    IDSMessage m1(
                    EventFrame (10, ProtocolHeader(1,1,1), 4, 5, 6, 7 ),
                    Timestamp (TimeStampSource::AUTOSAR, 0x2af0abcd, 0x12345678),
                    ContextDataFrame (ContextDataSize::SHORT,data.size(),data)
                 );
    
    std::cout << "-------------print message-------------\n";    
    m1.print();

    std::cout << "--check if message is verified or not--\n";
    std::cout << static_cast<int>(m1.isVerified()) << "\n";

    std::cout << "-------------serialization-------------\n";
    std::vector<uint8_t> message1_vec = m1.Payload();
    for(uint8_t byte : message1_vec)
    {
        std::cout << static_cast<int>(byte) << "\n";
    } 
    
    std::cout << "-----------deserialization------------\n";    
    IDSMessage m1_rec =  IDSMessage::Deserialize(message1_vec);
    m1_rec.print();
#endif

    return 0;
}