#include <iostream>
#include "../event_reporter.h"
// for delay
#include <thread>
#include <chrono>

using namespace ara::idsm;
using namespace ara::core;
int main()
{
    InstanceSpecifier specifier("BSW_1");
    EventReporter reporter(specifier);
    
    /*
    for(;;){
    reporter.ReportEvent();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    */
    
    uint64_t time = 0x4012345678abcdef;
    /*
    for(;;){
    reporter.ReportEvent(time);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    */
    
    std::vector<uint8_t> data = {10,20,30}; 
    /*
    for(;;){
    reporter.ReportEvent(data);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    */

    for(;;)
    {
    reporter.ReportEvent(data, time);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    for(;;);
    
    return 0;
}