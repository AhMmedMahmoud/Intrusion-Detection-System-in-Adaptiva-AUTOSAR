#include <iostream>
#include "../idsm/idsm.h"
// for delay
#include <thread>
#include <chrono>
#include "../../core/initialization.h"

using namespace ara::idsm::someip;
using namespace ara::com::helper;
using namespace AsyncBsdSocketLib;


/************************************ constants ******************************/
const int cTimeoutMs = 100;
const std::string cNicIpAddress{"127.0.0.1"};
const std::string cMulticastGroup{"239.0.0.1"};
const uint16_t cPort_Sensors_IDSM{6666};
const uint16_t cPort_IDSM_IDSR{7777};
const uint16_t cServiceId = 10;
const uint16_t cInstanceId = 3;
const uint8_t cMajorVersion = 10;
const uint8_t cMinorVersion = 4;
const uint16_t cEventgroupId = 5;
const uint8_t cProtocolVersion = 20;
const uint16_t cInterfaceVersion = 2;
const uint16_t cClientId = 1;

int main()
{
    ara::core::Initialize();

    Poller* poller;
    poller = new Poller();
  
    IDSM manager( cServiceId,
                  cInstanceId,
                  cMajorVersion,
                  cEventgroupId,
                  poller,
                  cNicIpAddress,
                  cMulticastGroup,
                  cPort_Sensors_IDSM,
                  cPort_IDSM_IDSR,
                  cProtocolVersion,
                  cInterfaceVersion
                );
    
    // Create thread using a lambda expression
    std::thread t1([poller]()
    {
        while(1)
        {
        poller->TryPoll(cTimeoutMs);
        }
    });
   
    t1.join();
    return 0;
}