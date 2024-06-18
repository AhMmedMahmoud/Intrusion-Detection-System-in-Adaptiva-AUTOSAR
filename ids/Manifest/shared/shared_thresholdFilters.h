#ifndef SHARED_THRESHOLD_FILTERS_H
#define SHARED_THRESHOLD_FILTERS_H

#include "../metadata/security_event_threshold_filter.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventThresholdFilter> thresholdFilters;
        }
    }
}

#endif