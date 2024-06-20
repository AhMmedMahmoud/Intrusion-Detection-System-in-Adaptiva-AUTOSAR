#include "initialization.h"

#include "../crypto/private/common/crypto_error_domain.h"
#include "../crypto/Manifest/manifestOperations.h"
#include "../ids/Manifest/manager/manifest_manager.h"

namespace ara
{
    namespace core
    {
        ara::core::Result<void> Initialize () noexcept
        {
            bool _result =  crypto::manifest::parseManifest();
            if(_result)
            {
                idsm::manifest::ManifestManager manager("../Manifest/manifest.json");
                manager.parseJSON();
                return ara::core::Result<void>::FromValue();
            }
            else 
            {
                std::cout << "parsing failed\n";
                return ara::core::Result<void>::FromError(ara::crypto::MakeErrorCode(ara::crypto::CryptoErrorDomain::Errc::kResourceFault, NoSupplementaryDataForErrorDescription));
            }

            
        }
    }
}