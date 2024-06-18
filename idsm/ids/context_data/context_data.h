#ifndef CONTEXT_DATA_H
#define CONTEXT_DATA_H

#include <cstdint>
#include <vector>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            enum class ContextDataSize
            {
                SHORT,
                LONG
            };
            class ContextDataFrame
            {
            private:
                /******** attributes ********/
                ContextDataSize mFrameType;
                uint32_t mLenght;
                std::vector<uint8_t> mData;

            public:
                /******** constructor  ******/
                ContextDataFrame(ContextDataSize frameType, uint32_t lenght, std::vector<uint8_t> data);
                ContextDataFrame() noexcept;

                /******** getter and setter *******/
                ContextDataSize getFrameType() noexcept;
                uint32_t getLenght() noexcept;
                std::vector<uint8_t> getData();
                void setLenght(uint32_t lenght) noexcept;
                void setData(std::vector<uint8_t> data);
                void setFrameType(ContextDataSize frameType);

                /********** helper functions **********/
                void print();

                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload() const;
                static ContextDataFrame Deserialize(const std::vector<uint8_t> &payload);

                /**************** move constructor and move assigment operator **************/
                ContextDataFrame(ContextDataFrame&& other) noexcept;
                ContextDataFrame& operator=(ContextDataFrame&& other);
            };

        }
    }
}

# endif