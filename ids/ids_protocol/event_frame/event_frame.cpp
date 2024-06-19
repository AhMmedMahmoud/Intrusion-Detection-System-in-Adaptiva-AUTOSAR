#include "event_frame.h"
#include <utility>
#include <iostream>
#include "../../../com/helper/payload_helper.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            /******** constructor *******/
            EventFrame::EventFrame( uint8_t protocolVersion,
                                    ProtocolHeader protocolHeader,
                                    uint16_t idsMInstanceID,
                                    uint8_t sensorInstanceID,
                                    uint16_t eventDefinationID,
                                    uint16_t count
                                  ) noexcept : 
                                    mProtocolVersion{protocolVersion},
                                    mProtocolHeader{std::move(protocolHeader)},
                                    mIdsMInstanceID{idsMInstanceID},
                                    mSensorInstanceID{sensorInstanceID},
                                    mEventDefinationID{eventDefinationID},
                                    mCount{count}
            {}
            
            EventFrame::EventFrame() noexcept : 
                                    mProtocolVersion{0},
                                    mProtocolHeader{std::move(ProtocolHeader(0,0,0))},
                                    mIdsMInstanceID{0},
                                    mSensorInstanceID{0},
                                    mEventDefinationID{0},
                                    mCount{0}
            {}

            /******** getters and setters *********/
            uint8_t EventFrame::getProtocolVersion() noexcept
            {
                return mProtocolVersion;
            }
            ProtocolHeader EventFrame::getProtocolHeader() noexcept
            {
                return std::move(mProtocolHeader);
            }
            uint16_t EventFrame::getIdsMInstanceID() noexcept
            {
                return mIdsMInstanceID;
            }
            uint8_t EventFrame::getSensorInstanceID() noexcept
            {
                return mSensorInstanceID;
            }
            uint16_t EventFrame::getEventDefinationID() noexcept
            {
                return mEventDefinationID;
            }
            uint16_t EventFrame::getCount() noexcept
            {
                return mCount;
            }
            void EventFrame::setProtocolVersion(uint8_t protocolVersion) noexcept
            {
                mProtocolVersion = protocolVersion;
            }
            void EventFrame::setProtocolHeader(ProtocolHeader protocolHeader) noexcept
            {
                mProtocolHeader = std::move(protocolHeader);
            }
            void EventFrame::setIdsMInstanceID(uint16_t idsMInstanceID) noexcept
            {
                mIdsMInstanceID = idsMInstanceID;
            }
            void EventFrame::setSensorInstanceID(uint8_t sensorInstanceID) noexcept
            {
                mSensorInstanceID = sensorInstanceID;
            }
            void EventFrame::setEventDefinationID(uint16_t eventDefinationID) noexcept
            {
                mEventDefinationID = eventDefinationID;
            }
            void EventFrame::setCount(uint16_t count) noexcept
            {
                mCount = count;
            }

            /********** helper functions **********/
            void EventFrame::print()
            {
                std::cout << "ProtocolVersion: "   << static_cast<int>(mProtocolVersion) << std::endl;
                mProtocolHeader.print();
                std::cout << "IdsMInstanceID: "    << mIdsMInstanceID << std::endl;
                std::cout << "SensorInstanceID: "  << static_cast<int>(mSensorInstanceID) << std::endl;
                std::cout << "EventDefinationID: " << mEventDefinationID << std::endl;
                std::cout << "Count: "             << mCount << std::endl;
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> EventFrame::Payload() const
            {
                std::vector<uint8_t> _result;
                uint8_t byte_0 = ((mProtocolVersion & 0x0f) << 4) | mProtocolHeader.Payload();
                uint16_t byte_1_2 = (mIdsMInstanceID << 6) | (uint16_t)(mSensorInstanceID & 0x3F);
                uint16_t byte_3_4 = mEventDefinationID;
                uint16_t byte_5_6 = mCount;
                uint8_t byte_7 = 0;

                _result.push_back(byte_0); 
                ara::com::helper::Inject(_result, byte_1_2);
                ara::com::helper::Inject(_result, byte_3_4);
                ara::com::helper::Inject(_result, byte_5_6);
                _result.push_back(byte_7); 

                return _result;
            }

            EventFrame EventFrame::Deserialize(
                    const std::vector<uint8_t> &payload)
            {  
               // Set the offset at the beginning of the payload
               std::size_t _offset = 0;

               EventFrame _result;
               _result.mProtocolVersion = payload[_offset] >> 4;
               _result.mProtocolHeader.setFlags(payload[_offset] & 0x0f);
               _offset++;
               uint16_t byte_1_2 = ara::com::helper::ExtractShort(payload, _offset);
               _result.mIdsMInstanceID = byte_1_2 >> 6;
               _result.mSensorInstanceID = byte_1_2 & 0x3F;
               _result.mEventDefinationID = ara::com::helper::ExtractShort(payload, _offset);
               _result.mCount = ara::com::helper::ExtractShort(payload, _offset);

               return _result;
            }

            /**************** move constructor and move assigment operator **************/
            EventFrame::EventFrame(EventFrame&& other) noexcept :  
                                    mProtocolVersion{other.mProtocolVersion},
                                    mProtocolHeader{std::move(other.mProtocolHeader)},
                                    mIdsMInstanceID{other.mIdsMInstanceID},
                                    mSensorInstanceID{other.mSensorInstanceID},
                                    mEventDefinationID{other.mEventDefinationID},
                                    mCount{other.mCount}
            {}
            EventFrame& EventFrame::operator=(EventFrame&& other)
            {
                mProtocolVersion = other.mProtocolVersion;
                mProtocolHeader = std::move(other.mProtocolHeader);
                mIdsMInstanceID = other.mIdsMInstanceID;
                mSensorInstanceID = other.mSensorInstanceID;
                mEventDefinationID = other.mEventDefinationID;
                mCount = other.mCount;
                return *this;
            }
        }
    }
}