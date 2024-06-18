#ifndef SHARED_STATE_FILTERS_H
#define SHARED_STATE_FILTERS_H

#include "../metadata/security_event_state_filter.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventStateFilter> stateFilters;
        }
    }
}

#endif