#include "event_reporter.h"
#include "../com/network_binding/someip/someipRpcMsg/someip_rpc_message.h"
#include "../com/helper/payload_helper.h"

namespace ara
{
    namespace idsm
    {
        const std::string cNicIpAddress{"127.0.0.1"};
        const std::string cMulticastGroup{"239.0.0.1"};
        const std::string cAnyIpAddress{"0.0.0.0"};
        const uint16_t cPort(6666);

        const uint16_t cServiceId = 10;
        const uint16_t cInstanceId = 3;
        const uint8_t cMajorVersion = 10;
        const uint8_t cMinorVersion = 4;
        const uint8_t cProtocolVersion = 20;
        const uint16_t cInterfaceVersion = 2;
        const uint16_t cClientId = 1;

        const uint16_t cMethodReportEventCountType = 1;
        const uint16_t cMethodReportEventTimestampTypeCountType = 2;
        const uint16_t cMethodReportEventContextDataTypeCountType = 3;
        const uint16_t cMethodReportEventContextDataTypeTimestampTypeCountType = 4;

        EventReporter::EventReporter(const ara::core::InstanceSpecifier &eventType) noexcept
            :mUdpSocket(cNicIpAddress, cPort, cNicIpAddress, cMulticastGroup) 
        {
            bool _successful{mUdpSocket.TrySetup()};
            if (!_successful)
            {
                std::cout << ("UDP socket setup failed.");
            }

            // Calculate the length of the input string
            uint8_t length = eventType.ToString().length();
            // Add the length to the specifer vector
            specifer.push_back(length);
            // Add each character of string value of eventType  to the specifier vector
            for (char c : eventType.ToString()) {
                specifer.push_back(c);
            }
        }

        void EventReporter::ReportEvent(const CountType count) noexcept
        {
            std::vector<uint8_t> data = specifer;
            data.push_back(count);
            
            ara::com::someip::rpc::SomeIpRpcMessage message(
                                            ( (((uint32_t)cServiceId)<<16) | ((uint32_t)cMethodReportEventCountType)),
                                            cClientId,
                                            cInitialSessionId++,
                                            cProtocolVersion,
                                            cInterfaceVersion,
                                            data
                                          );
            

            std::vector<uint8_t> _payload = message.Payload();
            std::array<uint8_t, cBufferSize> _buffer;
            std::copy_n(
                std::make_move_iterator(_payload.begin()),
                _payload.size(),
                _buffer.begin());

            mUdpSocket.Send(_buffer, cMulticastGroup, cPort);
            message.print();
        }
        
        void EventReporter::ReportEvent(const TimestampType timestamp,
                        const CountType count) noexcept
        {
            std::vector<uint8_t> data = specifer;
            ara::com::helper::Inject(data, (uint32_t)(timestamp>>32)); 
            ara::com::helper::Inject(data, (uint32_t)timestamp);
            data.push_back(count);
            
            ara::com::someip::rpc::SomeIpRpcMessage message(
                                            ( (((uint32_t)cServiceId)<<16) | ((uint32_t)cMethodReportEventTimestampTypeCountType)),
                                            cClientId,
                                            cInitialSessionId++,
                                            cProtocolVersion,
                                            cInterfaceVersion,
                                            data
                                          );
            

            std::vector<uint8_t> _payload = message.Payload();
            std::array<uint8_t, cBufferSize> _buffer;
            std::copy_n(
                std::make_move_iterator(_payload.begin()),
                _payload.size(),
                _buffer.begin());

            mUdpSocket.Send(_buffer, cMulticastGroup, cPort);
            message.print();
        }

        void EventReporter::ReportEvent(const ContextDataType &contextData,
                         const CountType count) noexcept
        {
            std::vector<uint8_t> data = specifer;
            data.insert(data.end(), contextData.begin(), contextData.end());
            data.push_back(count);

            ara::com::someip::rpc::SomeIpRpcMessage message(
                                            ( (((uint32_t)cServiceId)<<16) | ((uint32_t)cMethodReportEventContextDataTypeCountType)),
                                            cClientId,
                                            cInitialSessionId++,
                                            cProtocolVersion,
                                            cInterfaceVersion,
                                            data
                                          );
            

            std::vector<uint8_t> _payload = message.Payload();
            std::array<uint8_t, cBufferSize> _buffer;
            std::copy_n(
                std::make_move_iterator(_payload.begin()),
                _payload.size(),
                _buffer.begin());

            mUdpSocket.Send(_buffer, cMulticastGroup, cPort);
            message.print();
        }

        void EventReporter::ReportEvent(const ContextDataType &contextData,
                         const TimestampType timestamp,
                         const CountType count) noexcept
        {
            std::vector<uint8_t> data = specifer;
            ara::com::helper::Inject(data, (uint32_t)(timestamp>>32)); 
            ara::com::helper::Inject(data, (uint32_t)timestamp);
            data.insert(data.end(), contextData.begin(), contextData.end());
            data.push_back(count);
            
            ara::com::someip::rpc::SomeIpRpcMessage message(
                                            ( (((uint32_t)cServiceId)<<16) | ((uint32_t)cMethodReportEventContextDataTypeTimestampTypeCountType)),
                                            cClientId,
                                            cInitialSessionId++,
                                            cProtocolVersion,
                                            cInterfaceVersion,
                                            data
                                          );
            

            std::vector<uint8_t> _payload = message.Payload();
            std::array<uint8_t, cBufferSize> _buffer;
            std::copy_n(
                std::make_move_iterator(_payload.begin()),
                _payload.size(),
                _buffer.begin());

            mUdpSocket.Send(_buffer, cMulticastGroup, cPort);
            message.print();
        }
    }
}