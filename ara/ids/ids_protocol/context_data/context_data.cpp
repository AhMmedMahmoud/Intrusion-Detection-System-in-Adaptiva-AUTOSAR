#include "context_data.h"
#include <iostream>
#include "../../../com/helper/payload_helper.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            /******** constructor  ******/
            ContextDataFrame::ContextDataFrame( ContextDataSize frameType, 
                                      uint32_t lenght,
                                      std::vector<uint8_t> data) : mFrameType{frameType},
                                                                   mLenght{lenght},
                                                                   mData{data}
            {}
            ContextDataFrame::ContextDataFrame() noexcept : mFrameType{ContextDataSize::SHORT},
                                                  mLenght{0},
                                                  mData{{}}
            {}

            /******** getter and setter *******/
            ContextDataSize ContextDataFrame::getFrameType() noexcept
            {
                return mFrameType;
            }
            uint32_t ContextDataFrame::getLenght() noexcept
            {
                return mLenght;
            }
            std::vector<uint8_t> ContextDataFrame::getData()
            {
                return mData;
            }
            void ContextDataFrame::setLenght(uint32_t lenght) noexcept
            {
                mLenght = lenght;
            }
            void ContextDataFrame::setData(std::vector<uint8_t> data)
            {
                mData = data;
            }
            void ContextDataFrame::setFrameType(ContextDataSize frameType)
            {
                mFrameType = frameType;
            }

            /********** helper functions **********/
            void ContextDataFrame::print()
            {
                switch (mFrameType)
                {
                case ContextDataSize::SHORT :
                    std::cout << "short frame\n";
                break;
                
                case ContextDataSize::LONG :
                    std::cout << "long frame\n";
                break;
                }

                std::cout << "lenght: " << mLenght << std::endl;
                std::cout << "data:\t";
                for(uint8_t byte: mData)
                {
                    std::cout << static_cast<int>(byte) << "\t";
                }
                std::cout << "\n";
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> ContextDataFrame::Payload() const
            {
                std::vector<uint8_t> _result;

                if(mFrameType == ContextDataSize::SHORT)
                {
                    uint8_t lenght = 0;
                    if( mData.size() <= 127)
                    {
                        lenght = mData.size();
                        _result.push_back(lenght);
                        _result.insert( _result.end(), mData.cbegin(), mData.cend());
                    }
                    else
                    {
                        std::cout << "serialization fails as lenght of Data is bigger than 127 byte\n";
                    }                    
                    return _result;
                }
                else
                {
                    uint32_t lenght = (1 << 31);
                    if( mData.size() <= ((2<<31)-1) )
                    {
                        lenght |= mData.size();
                        ara::com::helper::Inject(_result, lenght);
                        _result.insert( _result.end(), mData.cbegin(), mData.cend());
                    }
                    else
                    {
                        std::cout << "serializiton fails as lenght of Data is bigger than 2^31 - 1 bytes\n";
                    }    
                    return _result;
                } 
            }
            ContextDataFrame ContextDataFrame::Deserialize(const std::vector<uint8_t> &payload)
            {
                ContextDataFrame _result;
                if(payload[0] >> 7)
                {
                    _result.setFrameType(ContextDataSize::LONG);

                    // Set the offset at the beginning of the payload
                    std::size_t _offset = 0;
                    uint32_t _lenght = ara::com::helper::ExtractInteger(payload, _offset) & 0x7fffffff; 
                   
                    _result.setLenght(_lenght);
                    _result.setData(std::vector<uint8_t>(payload.begin() + 4, payload.begin()+4+_lenght));
                    return _result;
                }
                else
                {
                    _result.setFrameType(ContextDataSize::SHORT);
                    _result.setLenght(payload[0]);
                    _result.setData(std::vector<uint8_t>(payload.begin() + 1, payload.begin()+1+payload[0]));
                    return _result;
                }
            }

            /**************** move constructor and move assigment operator **************/
            ContextDataFrame::ContextDataFrame(ContextDataFrame&& other) noexcept :  
                                    mFrameType{other.mFrameType},
                                    mLenght{std::move(other.mLenght)},
                                    mData{other.mData}
            {}
            ContextDataFrame& ContextDataFrame::operator=(ContextDataFrame&& other)
            {
                mFrameType = other.mFrameType;
                mLenght = std::move(other.mLenght);
                mData = other.mData;
                return *this;
            }
        }
    }
}