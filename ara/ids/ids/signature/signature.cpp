#include "signature.h"
#include <iostream>
#include "../../../com/helper/payload_helper.h"

/*
#include "../../../crypto/helper/print.h"
#include "../../../core/initialization.h"
#include "../../../crypto/private/common/entry_point.h"

using namespace ara::crypto::cryp;
using namespace ara::crypto::helper;
using namespace ara::core;
using namespace ara::crypto;
*/

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            /******** constructor *******/
            SignatureFrame::SignatureFrame(uint16_t lenght, std::vector<uint8_t> data) : mLenght{lenght},
                                                                                         mData{data}
            {}
            SignatureFrame::SignatureFrame() : mLenght{0},
                                               mData{}
            {}

            /******** getter and setter ******/
            uint16_t SignatureFrame::getLenght() noexcept
            {
                return mLenght;
            }
            std::vector<uint8_t> SignatureFrame::getData() noexcept
            {
                return mData;
            }
            void SignatureFrame::setLenght(uint8_t lenght) noexcept
            {
                mLenght = lenght;
            }
            void SignatureFrame::setData(std::vector<uint8_t> data)
            {
                mData = data;
            }

            /********** helper functions **********/
            void SignatureFrame::print()
            {
                std::cout << "Signature Lenght: " << mLenght << "\n";
                std::cout << "Signature Data: ";
                for(uint8_t byte : mData)
                {
                    std::cout << static_cast<int>(byte) << "\t";
                }
                std::cout << "\n";
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> SignatureFrame::Payload() const
            {
                std::vector<uint8_t> _result;
                ara::com::helper::Inject(_result, mLenght);
                _result.insert( _result.end(), mData.cbegin(), mData.cend());

                return _result;
            }
            SignatureFrame SignatureFrame::Deserialize(const std::vector<uint8_t> &payload)
            {
                // Set the offset at the beginning of the payload
                std::size_t _offset = 0;

                SignatureFrame _result;
                _result.mLenght = ara::com::helper::ExtractShort(payload, _offset);
                _result.mData = std::vector<uint8_t>(payload.begin()+_offset, payload.end());    

                return _result;
            }

            /**************** move constructor and move assigment operator **************/
            SignatureFrame::SignatureFrame(SignatureFrame&& other) noexcept :  mLenght{other.mLenght},
                                                                               mData{other.mData}
                                    
            {}
            SignatureFrame& SignatureFrame::operator=(SignatureFrame&& other)
            {
                mLenght = other.mLenght;
                mData = other.mData;
                return *this;
            }

            /************ static functions *********/
            bool SignatureFrame::signByECDSA( std::vector<uint8_t> instr,
                                              std::vector<uint8_t> &signature)
            {
                // signature = signature of instr
                return true;   
            }
        }
    }
}