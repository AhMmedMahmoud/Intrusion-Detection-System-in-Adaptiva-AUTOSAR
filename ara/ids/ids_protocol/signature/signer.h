#ifndef SIGNER_H
#define SIGNER_H

#include "signature.h"

#include "../../../crypto/helper/print.h"
#include "../../../core/initialization.h"
#include "../../../crypto/private/common/entry_point.h"
#include "../../../crypto/Manifest/sharedSlotsInterface.h"

using namespace ara::crypto::cryp;
using namespace ara::crypto::helper;
using namespace ara::core;
using namespace ara::crypto;

namespace ara
{
    namespace idsm
    {
        namespace security
        {
            class Signer
            {
            public:
                static ids::SignatureFrame sign(CryptoAlgId id, std::vector<uint8_t> payload)
                {
                    ids::SignatureFrame s;

                    /****************************************
                    *       load a key storage provider     *
                    ****************************************/
                    auto myKeyStorageProvider = LoadKeyStorageProvider();
                    if(myKeyStorageProvider == nullptr)
                    {
                        std::cout << "failed to load crypto provider\n";
                        return s;
                    }

                    /**************************************************************
                    *    using loaded key storage provider to acess private key   *
                    **************************************************************/
                    InstanceSpecifier privateKeySpecifier("ecdsa_sha_256_private_key_1");
                    auto res_loadKeySlot = myKeyStorageProvider->LoadKeySlot(privateKeySpecifier);
                    if(!res_loadKeySlot.HasValue())
                    {
                        std::cout << "--- error 2---\n";
                        ara::core::ErrorCode error = res_loadKeySlot.Error();
                        std::cout << error.Message() << std::endl;
                        return s;
                    }
                    auto mySlot = std::move(res_loadKeySlot).Value();
                    auto res_open = mySlot->Open();
                    if(!res_open.HasValue())
                    {
                        std::cout << "--- error 3---\n";
                        ara::core::ErrorCode error = res_open.Error();
                        std::cout << error.Message() << std::endl;
                        return s;
                    }
                    auto myIoInterface = std::move(res_open).Value();

                    /****************************************
                    *          load a crypto provider       *
                    ****************************************/
                    InstanceSpecifier crypoProviderSpecifier("cryptopp");
                    auto myCryptoProvider = LoadCryptoProvider(crypoProviderSpecifier);
                    if(myCryptoProvider == nullptr)
                    {
                        std::cout << "failed to load crypto provider\n";
                        return s;
                    }
                    
                    /**************************************************************
                    *    using loaded crypto provider to load private key         *
                    **************************************************************/
                    auto res_loadPrKey = myCryptoProvider->LoadPrivateKey(*myIoInterface);
                    if(!res_loadPrKey.HasValue())
                    {
                        std::cout << "--- error in loading private key ---\n";
                        ara::core::ErrorCode error = res_loadPrKey.Error();
                        std::cout << error.Message() << std::endl;
                        return s;
                    }
                    auto myPrivateKey = std::move(res_loadPrKey).Value();

                    /****************************************
                    *          create ecdsa contexts        *
                    ****************************************/
                    auto res_createSigEncodePrivateCtx = myCryptoProvider->CreateSigEncodePrivateCtx(id);

                    if(!res_createSigEncodePrivateCtx.HasValue())
                    {
                        std::cout << "failed to create ecdsa contexts\n";
                        return s;
                    }
                    
                    auto mySigEncodePrivateCtx = std::move(res_createSigEncodePrivateCtx).Value();

                    /****************************************
                    *        using SigEncodePrivateCtx      *
                    ****************************************/
                    mySigEncodePrivateCtx->SetKey(*myPrivateKey);

                    auto _result = mySigEncodePrivateCtx->SignAndEncode(payload);
                    if(_result.HasValue())
                    {
                        //std::cout << "--- sucess ---\n";
                        
                        // get messagePlusSignature
                        auto messagePlusSignature = _result.Value();
                        
                        std::vector<uint8_t>signature = std::vector<uint8_t>( messagePlusSignature.begin()+payload.size(), messagePlusSignature.end());

                        //printHex(payload, "Message: ");                 
                        //printHex(signature, "Signature: ");  

                        s.setData(signature);
                        s.setLenght(signature.size());
                        s.setIsUsed(true);
                        return s;
                    }
                    else
                    {
                        std::cout << "--- error 4---\n";
                        ara::core::ErrorCode error = _result.Error();
                        std::cout << error.Message() << std::endl;
                        return s;
                    }
                }
            };
        }
    }
}


#endif