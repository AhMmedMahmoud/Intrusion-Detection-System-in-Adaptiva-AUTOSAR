#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <cstdint>
#include <vector>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            class SignatureFrame
            {
            private:
                /********** attributes ******/
                uint16_t mLenght;
                std::vector<uint8_t> mData;

            public:
                /******** constructor *******/
                SignatureFrame(uint16_t lenght, std::vector<uint8_t> data);
                SignatureFrame();

                /******** getter and setter ******/
                uint16_t getLenght() noexcept;
                std::vector<uint8_t> getData() noexcept;
                void setLenght(uint8_t lenght) noexcept;
                void setData(std::vector<uint8_t> data);

                 /********** helper functions **********/
                void print();

                /************ static functions *********/
                static bool signByECDSA(std::vector<uint8_t> instr, std::vector<uint8_t> &signature);

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