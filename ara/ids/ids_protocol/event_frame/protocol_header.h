#ifndef IDS_PROTOCOL_HEADER_H
#define IDS_PROTOCOL_HEADER_H

#include <cstdint>

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            class ProtocolHeader
            {
            private:
                /********** attributes *******/
                bool mSignatureFlag = false;
                bool mTimestampFlag = false;
                bool mContextDataFlag = false;

            public:
                /********** constructor ******/
                ProtocolHeader(bool signatureFlag, bool timestampFlag, bool contextDataFlag) noexcept;

                /******** getters and setters *****/
                bool getSignatureFlag() noexcept;
                bool getTimestampFlag() noexcept;
                bool getContextDataFlag() noexcept;
                void setSignatureFlag(bool signatuerFlag) noexcept;
                void setTimestampFlag(bool timestampFlag) noexcept;
                void setContextDataFlag(bool contextDataFlag) noexcept;
                void setFlags(uint8_t mask) noexcept;

                /********* helper functions *******/
                void print();

                /********** serialize and deserialize functions *******/
                uint8_t Payload() const;
                
                /**************** move constructor and move assigment operator **************/
                ProtocolHeader(ProtocolHeader&& other) noexcept;
                ProtocolHeader& operator=(ProtocolHeader&& other);

                /****************** tell compiler to generate default desctructor  ********************/
                //~ProtocolHeader() noexcept = default;
            };
        }
    }
}

#endif