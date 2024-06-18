#ifndef IDS_MESSAGE_H
#define IDS_MESSAGE_H

#include "event_frame/event_frame.h"
#include "context_data/context_data.h"
#include "timestamp/timestamp.h"
//#include "signature/signature.h"

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
                //SignatureFrame mSignatureFrame;

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
                void setEventFrame(EventFrame eventFrame);
                void setTimestamp(Timestamp timestamp);
                void setContextDataFrame(ContextDataFrame contextDataFrame);

                /*********** helper functions *******/
                void print();
               
                /********** serializate and deserialize functions ********/
                std::vector<uint8_t> Payload();
                static IDSMessage Deserialize(const std::vector<uint8_t> &payload);
            };
        }
    }
}

#endif