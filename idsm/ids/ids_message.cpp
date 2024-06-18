#include "ids_message.h"
#include <utility>
#include "../../com/helper/payload_helper.h"
#include <iostream>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            IDSMessage::IDSMessage(EventFrame eventFrame) noexcept : mEventFrame{std::move(eventFrame)}
            {}

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    Timestamp timestamp) noexcept : mEventFrame{std::move(eventFrame)},
                                                                    mTimestamp{std::move(timestamp)}
            {}

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    ContextDataFrame contextDataFrame) noexcept : mEventFrame{std::move(eventFrame)},
                                                                                  mContextDataFrame{std::move(contextDataFrame)}
            {}

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    Timestamp timestamp,
                                    ContextDataFrame contextDataFrame) noexcept : mEventFrame{std::move(eventFrame)},
                                                                                  mTimestamp{std::move(timestamp)},
                                                                                  mContextDataFrame{std::move(contextDataFrame)}
            {}

            IDSMessage::IDSMessage() noexcept : mEventFrame{},
                                                mTimestamp{},
                                                mContextDataFrame{}
            {}

            /********** getter and setter ******/
            EventFrame IDSMessage::getEventFrame()
            {
                return std::move(mEventFrame);
            }
            Timestamp IDSMessage::getTimestamp()
            {
                return std::move(mTimestamp);
            }
            ContextDataFrame IDSMessage::getContextDataFrame()
            {
                return std::move(mContextDataFrame);
            }
            void IDSMessage::setEventFrame(EventFrame eventFrame)
            {
                mEventFrame = std::move(eventFrame);
            }
            void IDSMessage::setTimestamp(Timestamp timestamp)
            {
                mTimestamp = std::move(timestamp);
            }
            void IDSMessage::setContextDataFrame(ContextDataFrame contextDataFrame)
            {
                mContextDataFrame = std::move(contextDataFrame);
            }

            /*********** helper functions *******/
            void IDSMessage::print()
            {
                mEventFrame.print();
                
                if(mEventFrame.getProtocolHeader().getTimestampFlag())
                {
                    mTimestamp.print();
                }
                if(mEventFrame.getProtocolHeader().getContextDataFlag())
                {
                    mContextDataFrame.print();
                }
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> IDSMessage::Payload()
            {
                std::vector<uint8_t> _result;

                ara::com::helper::Concat(_result, mEventFrame.Payload());

                if(mEventFrame.getProtocolHeader().getTimestampFlag())
                {
                    ara::com::helper::Concat(_result, mTimestamp.Payload());
                }
                if(mEventFrame.getProtocolHeader().getContextDataFlag())
                {
                    ara::com::helper::Concat(_result, mContextDataFrame.Payload());
                }

                return _result;
            }
            IDSMessage IDSMessage::Deserialize(const std::vector<uint8_t> &payload)
            {
                uint8_t _offset = 8;
                IDSMessage _result;
                _result.mEventFrame = std::move(EventFrame::Deserialize(std::vector<uint8_t>(payload.begin(),payload.begin()+_offset)));

                if(_result.mEventFrame.getProtocolHeader().getTimestampFlag())
                {
                    _result.mTimestamp = std::move(Timestamp::Deserialize(std::vector<uint8_t>(payload.begin()+_offset,payload.begin()+_offset*2)));
                    _offset *= 2;
                }
                if(_result.mEventFrame.getProtocolHeader().getContextDataFlag())
                {
                    _result.mContextDataFrame = std::move(ContextDataFrame::Deserialize(std::vector<uint8_t>(payload.begin()+_offset,payload.end())));
                }

                return _result;
            }


        }
    }
}