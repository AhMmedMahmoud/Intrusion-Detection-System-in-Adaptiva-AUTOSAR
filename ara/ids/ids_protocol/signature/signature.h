#ifndef IDS_SIGNATURE_H
#define IDS_SIGNATURE_H

#include <cstdint>
#include <vector>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            enum class SignatureState
            {
                SIFNATURE_NOT_SUPPORTED,
                NOT_VERIFIED,
                VERIFIED,
            };
            class SignatureFrame
            {
            private:
                /********** attributes ******/
                uint16_t mLenght;
                std::vector<uint8_t> mData;
                bool mIsUsed = false;

            public:
                /******** constructor *******/
                SignatureFrame(uint16_t lenght, std::vector<uint8_t> data);
                SignatureFrame();

                /******** getter and setter ******/
                uint16_t getLenght() noexcept;
                std::vector<uint8_t> getData() noexcept;
                bool getIsUsed() noexcept;
                void setLenght(uint8_t lenght) noexcept;
                void setData(std::vector<uint8_t> data);
                void setIsUsed(bool isUsed) noexcept;

                /********** helper functions **********/
                void print();

                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload() const;
                static SignatureFrame Deserialize(const std::vector<uint8_t> &payload);

                /**************** move constructor and move assigment operator **************/
                SignatureFrame(SignatureFrame&& other) noexcept;
                SignatureFrame& operator=(SignatureFrame&& other);
            };
        }
    }
}

#endif