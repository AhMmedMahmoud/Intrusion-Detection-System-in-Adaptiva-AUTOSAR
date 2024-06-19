#ifndef VERIFIER_H
#define VERIFIER_H

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
            class Verifier
            {
            public:
                static bool verify(CryptoAlgId id, std::vector<uint8_t> payload)
                {
                    /*********************************
                    *       call Initialize          *
                    *********************************/ 
                    auto res_Initialize = ara::core::Initialize();
                    if(!res_Initialize.HasValue())
                    {
                        std::cout << "--- error 1---\n";
                        ara::core::ErrorCode error = res_Initialize.Error();
                        std::cout << error.Message() << std::endl;
                        return false;
                    }

                    /****************************************
                    *       load a key storage provider     *
                    ****************************************/
                    auto myKeyStorageProvider = LoadKeyStorageProvider();
                    if(myKeyStorageProvider == nullptr)
                    {
                        std::cout << "failed to load crypto provider\n";
                        return false;
                    }

                    /**************************************************************
                    *    using loaded key storage provider to acess public key    *
                    **************************************************************/
                    InstanceSpecifier publicKeySpecifier("ecdsa_sha_256_public_key_1");
                    auto res_loadKeySlot2 = myKeyStorageProvider->LoadKeySlot(publicKeySpecifier);
                    if(!res_loadKeySlot2.HasValue())
                    {
                        std::cout << "--- error 2---\n";
                        ara::core::ErrorCode error = res_loadKeySlot2.Error();
                        std::cout << error.Message() << std::endl;
                        return false;
                    }

                    auto mySlot2 = std::move(res_loadKeySlot2).Value();
                    auto res_open2 = mySlot2->Open();
                    if(!res_open2.HasValue())
                    {
                        std::cout << "--- error 3---\n";
                        ara::core::ErrorCode error = res_open2.Error();
                        std::cout << error.Message() << std::endl;
                        return false;
                    }
                    auto myIoInterface2 = std::move(res_open2).Value();

                    /****************************************
                    *          load a crypto provider       *
                    ****************************************/
                    InstanceSpecifier crypoProviderSpecifier("cryptopp");
                    auto myCryptoProvider = LoadCryptoProvider(crypoProviderSpecifier);
                    if(myCryptoProvider == nullptr)
                    {
                        std::cout << "failed to load crypto provider\n";
                        return false;
                    }
                    
                    /**************************************************************
                    *    using loaded crypto provider to load public key         *
                    **************************************************************/
                    auto res_loadPUKey = myCryptoProvider->LoadPublicKey(*myIoInterface2);
                    if(!res_loadPUKey.HasValue())
                    {
                        std::cout << "--- error in loading public key---\n";
                        ara::core::ErrorCode error = res_loadPUKey.Error();
                        std::cout << error.Message() << std::endl;
                        return false;
                    }
                    auto myPublicKey = std::move(res_loadPUKey).Value();

                    /****************************************
                    *          create ecdsa contexts        *
                    ****************************************/
                    auto res_createMsgRecoveryPublicCtx = myCryptoProvider->CreateMsgRecoveryPublicCtx(ECDSA_SHA_256_ALG_ID);

                    if(!res_createMsgRecoveryPublicCtx.HasValue())
                    {
                        std::cout << "failed to create ecdsa contexts\n";
                        return false;
                    }
                    auto myMsgRecoveryPublicCtx = std::move(res_createMsgRecoveryPublicCtx).Value();

                    /****************************************
                    *       using  MsgRecoveryPublicCtx     *
                    ****************************************/  
                    myMsgRecoveryPublicCtx->SetKey(*myPublicKey);
                
                    auto _result2 = myMsgRecoveryPublicCtx->DecodeAndVerify(payload);   
                    if(_result2.HasValue())
                    {
                        //std::cout << "--- sucess ---\n";
          
                        // get recoveryMessage
                        auto recoveryMessage = _result2.Value();
                        //printHex(recoveryMessage, "Verified Message: ");  // vector
                        return true;
                    }
                    else
                    {
                        //std::cout << "--- error 4---\n";
                        ara::core::ErrorCode error = _result2.Error();
                        std::cout << error.Message() << std::endl;
                        return false;
                    }
                }
            };
        }
    }
}


#endif