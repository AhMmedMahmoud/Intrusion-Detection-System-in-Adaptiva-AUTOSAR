#ifndef MANIFEST_TYPES_H
#define MANIFEST_TYPES_H

#include "manifest_headers.h"

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            typedef int PositiveInteger;
            typedef std::string SymbolProps;
            typedef bool Boolean;
            enum class SecurityEventReportingModeEnum
            {
                OFF,
                BRIEF,
                DETAILED,
                BRIEF_BYPASSING_FILTERS,
                DETAILED_BYPASSING_FILTERS
            };
            enum class SecurityEventContextDataSourceEnum
            {
                NOT_REPORTER,
                REPORTER
            };
            typedef std::string SecurityEventContextData;
            typedef std::vector<std::string> ModeDeclaration;
            typedef int TimeValue;
            typedef uint16_t IdsmInstance;
        }
    }
}

#endif