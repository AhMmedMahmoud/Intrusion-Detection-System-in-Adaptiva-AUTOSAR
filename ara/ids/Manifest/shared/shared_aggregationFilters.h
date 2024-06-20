#ifndef SHARED_AGGREGATION_FILTERS_H
#define SHARED_AGGREGATION_FILTERS_H

#include "../metadata/security_event_aggregation_filter.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventAggregationFilter> aggregationFilters; 
        }
    }
}

#endif