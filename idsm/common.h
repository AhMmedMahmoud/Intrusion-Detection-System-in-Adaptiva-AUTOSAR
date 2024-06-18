#ifndef COMMON_H
#define COMMON_H

#include <cstdint>
#include "../core/Span.h"


namespace ara
{
    namespace idsm
    {
        using CountType = uint16_t;
        using TimestampType = uint64_t;
        using ContextDataType = ara::core::Span<std::uint8_t>;
    }
}


#endif
