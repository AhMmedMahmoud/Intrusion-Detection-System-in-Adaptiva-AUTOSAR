#include "protocol_header.h"
#include <iostream>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            /********** constructor ******/
            ProtocolHeader::ProtocolHeader(bool signatureFlag,
                                           bool timestamp,
                                           bool contextDataFlag) noexcept : mSignatureFlag{signatureFlag},
                                                                            mTimestampFlag{timestamp},
                                                                            mContextDataFlag{contextDataFlag}
            {}

            /******** getters and setters *****/
            bool ProtocolHeader::getSignatureFlag() noexcept
            {
                return mSignatureFlag;
            }
            bool ProtocolHeader::getTimestampFlag() noexcept
            {
                return mTimestampFlag;
            }
            bool ProtocolHeader::getContextDataFlag() noexcept
            {
                return mContextDataFlag;
            }
            void ProtocolHeader::setSignatureFlag(bool signatuerFlag) noexcept
            {
                mSignatureFlag = signatuerFlag;
            }
            void ProtocolHeader::setTimestampFlag(bool timestampFlag) noexcept
            {
                mTimestampFlag = timestampFlag;
            }
            void ProtocolHeader::setContextDataFlag(bool contextDataFlag) noexcept
            {
                mContextDataFlag = contextDataFlag;
            }
            void ProtocolHeader::setFlags(uint8_t mask) noexcept
            {
                mSignatureFlag = (mask & 0x04) >> 2;
                mTimestampFlag = (mask & 0x02) >> 1;
                mContextDataFlag = mask & 1;
            }

            /********* helper functions *******/
            void ProtocolHeader::print()
            {
                std::cout << "SigatureFlag: " << mSignatureFlag << std::endl;
                std::cout << "TimestampFlag: " << mTimestampFlag << std::endl;
                std::cout << "ContextDataFlag: " << mContextDataFlag << std::endl;
            }

            /********** serialize and deserialize functions *******/
            uint8_t ProtocolHeader::Payload() const
            {
                uint8_t _result = 0;
                _result =  (uint8_t)(mSignatureFlag << 2) |
                           (uint8_t)(mTimestampFlag << 1) |
                           (uint8_t)mContextDataFlag;
                return _result;
            }

            /**************** move constructor and move assigment ************/
            ProtocolHeader::ProtocolHeader(ProtocolHeader&& other) noexcept : 
                                                            mSignatureFlag{other.mSignatureFlag},
                                                            mTimestampFlag{other.mTimestampFlag},
                                                            mContextDataFlag{other.mContextDataFlag}
            {}
            ProtocolHeader& ProtocolHeader::operator=(ProtocolHeader &&other)
            {
                mSignatureFlag = other.mSignatureFlag;
                mTimestampFlag = other.mTimestampFlag;
                mContextDataFlag = other.mContextDataFlag;
                return *this;
            }
        }
    }
}