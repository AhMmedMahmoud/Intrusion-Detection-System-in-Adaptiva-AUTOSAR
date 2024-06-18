#ifndef EVENT_FRAME_H
#define EVENT_FRAME_H

#include <cstdint>
#include <vector>
#include "protocol_header.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            class EventFrame
            {
            private:
                /******* attributes ********/
                uint8_t mProtocolVersion;
                ProtocolHeader mProtocolHeader;
                uint16_t mIdsMInstanceID;
                uint8_t mSensorInstanceID;
                uint16_t mEventDefinationID;
                uint16_t mCount;

            public:
                /******** constructor *******/
                EventFrame( uint8_t protocolVersion,
                            ProtocolHeader protocolHeader,
                            uint16_t idsMInstanceID,
                            uint8_t sensorInstanceID,
                            uint16_t eventDefinationID,
                            uint16_t count
                          ) noexcept;
                
                EventFrame() noexcept;
                
                /******** getters and setters *********/
                uint8_t getProtocolVersion() noexcept;
                ProtocolHeader getProtocolHeader() noexcept;
                uint16_t getIdsMInstanceID() noexcept;
                uint8_t getSensorInstanceID() noexcept;
                uint16_t getEventDefinationID() noexcept;
                uint16_t getCount() noexcept;
                void setProtocolVersion(uint8_t protocolVersion) noexcept;
                void setProtocolHeader(ProtocolHeader protocolHeader) noexcept;
                void setIdsMInstanceID(uint16_t idsMInstanceID) noexcept;
                void setSensorInstanceID(uint8_t sensorInstanceID) noexcept;
                void setEventDefinationID(uint16_t eventDefinationID) noexcept;
                void setCount(uint16_t count) noexcept;

                /********** helper functions **********/
                void print();

                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload() const;
                static EventFrame Deserialize(const std::vector<uint8_t> &payload);
                
                /**************** move constructor and move assigment operator **************/
                EventFrame(EventFrame&& other) noexcept;
                EventFrame& operator=(EventFrame&& other);
            };
        }
    }
}



#endif