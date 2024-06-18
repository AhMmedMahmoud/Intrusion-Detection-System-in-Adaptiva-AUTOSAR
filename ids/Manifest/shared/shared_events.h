#ifndef SHARED_EVENTS_H
#define SHARED_EVENTS_H

#include "../metadata/security_event_context_props.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            extern std::vector<SecurityEventContextProps> events; 
        }
    }
}

#endif