#ifndef CRYPTOPRIMITIVEID_H
#define CRYPTOPRIMITIVEID_H

#include <memory>
#include "../../../../core/StringView.h"
#include "../../common/base_id_types.h"

namespace ara
{
    namespace crypto
    {
        namespace cryp
        {
            class CryptoPrimitiveId 
            {
            public:
                using Uptrc = std::unique_ptr<const CryptoPrimitiveId>;
                using Uptr = std::unique_ptr<CryptoPrimitiveId>;
                using AlgId = CryptoAlgId;

                virtual AlgId GetPrimitiveId () const noexcept=0;
                
                virtual const ara::core::StringView GetPrimitiveName () const noexcept=0;

                /******************* default assigment operators *********************/
                CryptoPrimitiveId& operator= (const CryptoPrimitiveId &other)=default;

                CryptoPrimitiveId& operator= (CryptoPrimitiveId &&other)=default;
                    
                /********** tell compiler to generate default deconstructor **********/
                virtual ~CryptoPrimitiveId () noexcept=default;
            };
        }
    }
}

#endif