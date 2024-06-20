#include "timestamp.h"
#include <iostream>
#include "../../../com/helper/payload_helper.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            /******** constructor *********/
            Timestamp::Timestamp( TimeStampSource source,
                                  uint32_t nanoseconds,
                                  uint32_t seconds) noexcept : mSource{source},
                                                               mNanoseconds{nanoseconds},
                                                               mSeconds{seconds}
            {}

            Timestamp::Timestamp( ) noexcept : mSource{TimeStampSource::AUTOSAR},
                                               mNanoseconds{0},
                                               mSeconds{0}
            {}


            /******** getter and setter ********/
            TimeStampSource Timestamp::getSource() noexcept
            {
                return mSource;
            }
            uint32_t Timestamp::getNanoseconds() noexcept
            {
                return mNanoseconds;
            }
            uint32_t Timestamp::getSeconds() noexcept
            {
                return mSeconds;
            }
            void Timestamp::setSource(TimeStampSource source) noexcept
            {
                mSource = source;
            }
            void Timestamp::setNanoseconds(uint32_t nanoseconds) noexcept
            {
                mNanoseconds = nanoseconds;
            }
            void Timestamp::setSeconds(uint32_t seconds) noexcept
            {
                mSeconds = seconds;
            }

            /********** helper functions **********/
            void Timestamp::print()
            {
                switch (mSource)
                {
                case TimeStampSource::AUTOSAR:
                    std::cout << "Source: Autosar Format" << std::endl; 
                break;
                
                case TimeStampSource::OEM:
                    std::cout << "Source: Autosar Format" << std::endl; 
                break;
                }

                std::cout << "Nanoseconds: " << mNanoseconds << std::endl;
                std::cout << "Seconds: "     << mSeconds << std::endl;
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> Timestamp::Payload() const
            {
                std::vector<uint8_t> _result;
                uint8_t byte_0 = (static_cast<uint8_t>(mSource) << 7) | 
                                 ((mNanoseconds & 0x3F000000) >> 24); 

                uint8_t byte_1 = ((mNanoseconds & 0x00FF0000) >> 16);
                uint16_t byte_2_3 = ((mNanoseconds & 0x0000FFFF));
                uint32_t byte_4_5_6_7 = mSeconds;

                _result.push_back(byte_0);
                _result.push_back(byte_1);
                ara::com::helper::Inject(_result, byte_2_3);
                ara::com::helper::Inject(_result, byte_4_5_6_7);
                
                return _result;
            }

            Timestamp Timestamp::Deserialize(
                    const std::vector<uint8_t> &payload)
            {
               // Set the offset at the beginning of the payload
               std::size_t _offset = 0;

               Timestamp _result;
               uint8_t byte_0 = payload[_offset];
               _result.mSource = static_cast<TimeStampSource>(byte_0 >> 7);
               _offset++;

               uint8_t byte_1 = payload[_offset++];
               uint16_t byte_2_3 = ara::com::helper::ExtractShort(payload, _offset);
               _result.mNanoseconds = (uint32_t)byte_2_3 |
                                      ((uint32_t)byte_1 << 16)  |
                                      ((uint32_t)(byte_0 & 0x3F) << 24); 
               _result.mSeconds = ara::com::helper::ExtractInteger(payload, _offset);

               return _result;
            }

            /**************** move constructor and move assigment operator **************/
            Timestamp::Timestamp(Timestamp&& other) noexcept :  
                                    mSource{other.mSource},
                                    mNanoseconds{other.mNanoseconds},
                                    mSeconds{other.mSeconds}
            {}
            Timestamp& Timestamp::operator=(Timestamp&& other)
            {
                mSource = other.mSource;
                mNanoseconds = other.mNanoseconds;
                mSeconds = other.mSeconds;
                return *this;
            }
        }
    }
}