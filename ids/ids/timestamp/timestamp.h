#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <cstdint>
#include <vector>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            enum class TimeStampSource
            {
                AUTOSAR,
                OEM
            };

            class Timestamp
            {
            private:
                /*********** attributes *******/
                TimeStampSource mSource;
                uint32_t mNanoseconds;
                uint32_t mSeconds;

            public:
                /******** constructor *********/
                Timestamp(TimeStampSource source, uint32_t nanoseconds, uint32_t seconds) noexcept;
                Timestamp() noexcept;
                
                /******** getter and setter ********/
                TimeStampSource getSource() noexcept;
                uint32_t getNanoseconds() noexcept;
                uint32_t getSeconds() noexcept;
                void setSource(TimeStampSource source) noexcept;
                void setNanoseconds(uint32_t nanoseconds) noexcept;
                void setSeconds(uint32_t seconds) noexcept;
                
                /********** helper functions **********/
                void print();

                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload() const;
                static Timestamp Deserialize(const std::vector<uint8_t> &payload);

                /**************** move constructor and move assigment operator **************/
                Timestamp(Timestamp&& other) noexcept;
                Timestamp& operator=(Timestamp&& other);
            };
        }    
    }   
}

#endif