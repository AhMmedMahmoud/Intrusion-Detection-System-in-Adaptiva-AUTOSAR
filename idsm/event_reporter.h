#ifndef IDSM_H
#define IDSM_H

#include "../core/instance_specifier.h"
#include "../com/network_binding/sockets/include/udp_client.h"
#include "common.h"

namespace ara
{
    namespace idsm
    {
        class EventReporter
        {
        private:
            /************* attributes ************/
            AsyncBsdSocketLib::UdpClient mUdpSocket;
            static const size_t cBufferSize{1300};
            
            uint16_t cInitialSessionId{1};

            std::vector<uint8_t> specifer;

        public:
            /************* constructor ***********/
	        EventReporter (const ara::core::InstanceSpecifier &eventType) noexcept;
            
            /********** fundemetal functions *****/
            void ReportEvent (const CountType count=1) noexcept;
            void ReportEvent (const TimestampType timestamp, const CountType count=1) noexcept;
            void ReportEvent (const ContextDataType &contextData, const CountType count=1) noexcept;
            void ReportEvent (const ContextDataType &contextData, const TimestampType timestamp, const CountType count=1) noexcept;
        };
    }
}

#endif