#ifndef SHARED_FILTERS_CHAINS_H
#define SHARED_FILTERS_CHAINS_H

#include "../metadata/security_event_filter_chain.h" 

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventFilterChain> filterchains;
        }
    }
}

#endif