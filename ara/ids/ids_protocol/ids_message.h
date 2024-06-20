#ifndef IDS_MESSAGE_H
#define IDS_MESSAGE_H

#include "event_frame/event_frame.h"
#include "context_data/context_data.h"
#include "timestamp/timestamp.h"
#include "signature/signature.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            class IDSMessage
            {
            private:
                /********** attributes ***********/
                EventFrame mEventFrame;
                Timestamp mTimestamp;
                ContextDataFrame mContextDataFrame;
                SignatureFrame mSignatureFrame;

            public:
                /********** constructors **********/
                IDSMessage(EventFrame eventFrame) noexcept;
                IDSMessage(EventFrame eventFrame, Timestamp timestamp) noexcept;
                IDSMessage(EventFrame eventFrame, ContextDataFrame contextDataFrame) noexcept;
                IDSMessage(EventFrame eventFrame, Timestamp timestamp, ContextDataFrame contextDataFrame) noexcept;
                IDSMessage() noexcept;

                /********** getter and setter ******/
                EventFrame getEventFrame();
                Timestamp getTimestamp();
                ContextDataFrame getContextDataFrame();
                SignatureFrame getSignatureFrame();
                void setEventFrame(EventFrame eventFrame);
                void setTimestamp(Timestamp timestamp);
                void setContextDataFrame(ContextDataFrame contextDataFrame);
                void setSignatureFrame(SignatureFrame signatureFrame);

                /*********** helper functions *******/
                void print();
                SignatureState isVerified();
               
                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload(bool considerSignature = true,
                                             bool considerSignatureLenght = true);
                static IDSMessage Deserialize(const std::vector<uint8_t> &payload);
            };
        }
    }
}

#endif