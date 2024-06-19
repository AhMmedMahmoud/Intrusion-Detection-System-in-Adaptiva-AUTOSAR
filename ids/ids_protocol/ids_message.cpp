#include "ids_message.h"
#include <utility>
#include "../../com/helper/payload_helper.h"
#include "../../crypto/public/cryp/cryptopp_crypto_provider.h"
#include <iostream>
#include "signature/signer.h"
#include "signature/verifier.h"

namespace ara
{
    namespace idsm
    {
        namespace ids
        {
            IDSMessage::IDSMessage(EventFrame eventFrame) noexcept : mEventFrame{std::move(eventFrame)}
            {
                if(eventFrame.getProtocolHeader().getSignatureFlag())
                {
                    mSignatureFrame = security::Signer::sign(ECDSA_SHA_256_ALG_ID, Payload(false));
                }
            }

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    Timestamp timestamp) noexcept : mEventFrame{std::move(eventFrame)},
                                                                    mTimestamp{std::move(timestamp)}
            {
                if(eventFrame.getProtocolHeader().getSignatureFlag())
                {
                    mSignatureFrame = security::Signer::sign(ECDSA_SHA_256_ALG_ID, Payload(false));
                }
            }

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    ContextDataFrame contextDataFrame) noexcept : mEventFrame{std::move(eventFrame)},
                                                                                  mContextDataFrame{std::move(contextDataFrame)}
            {
                if(eventFrame.getProtocolHeader().getSignatureFlag())
                {
                    mSignatureFrame = security::Signer::sign(ECDSA_SHA_256_ALG_ID, Payload(false));
                }
            }

            IDSMessage::IDSMessage( EventFrame eventFrame,
                                    Timestamp timestamp,
                                    ContextDataFrame contextDataFrame) noexcept : mEventFrame{std::move(eventFrame)},
                                                                                  mTimestamp{std::move(timestamp)},
                                                                                  mContextDataFrame{std::move(contextDataFrame)}
            {
                if(eventFrame.getProtocolHeader().getSignatureFlag())
                {
                    mSignatureFrame = security::Signer::sign(ECDSA_SHA_256_ALG_ID, Payload(false));
                }
            }

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
            SignatureFrame IDSMessage::getSignatureFrame()
            {
                return std::move(mSignatureFrame);
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
            void IDSMessage::setSignatureFrame(SignatureFrame signatureFrame)
            {
                mSignatureFrame = std::move(signatureFrame);
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

            SignatureState IDSMessage::isVerified()
            {
                SignatureState _state;

                if(!mEventFrame.getProtocolHeader().getSignatureFlag())
                    _state = SignatureState::SIFNATURE_NOT_SUPPORTED;
                else
                {
                    bool _result = security::Verifier::verify(ECDSA_SHA_256_ALG_ID,Payload(true,false));
                    switch(_result)
                    {
                        case 1:
                            _state = SignatureState::VERIFIED;
                            break;
                        case 0:
                            _state = SignatureState::NOT_VERIFIED;
                            break;
                    }
                }
                return _state;
            }

            /********** serializate and deserialize functions ********/
            std::vector<uint8_t> IDSMessage::Payload(bool considerSignature,bool considerSignatureLenght)
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
                if(mEventFrame.getProtocolHeader().getSignatureFlag() & considerSignature)
                {
                    if(considerSignatureLenght)
                        ara::com::helper::Concat(_result, mSignatureFrame.Payload());
                    else
                        ara::com::helper::Concat(_result, mSignatureFrame.getData());
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