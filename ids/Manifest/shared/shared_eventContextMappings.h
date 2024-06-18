#ifndef SHARED_EVENT_CONTEXT_MAPPINGS_H
#define SHARED_EVENT_CONTEXT_MAPPINGS_H

#include "../metadata/security_event_context_mapping.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventContextMapping> eventContextMappings;
        }
    }
}

#endif