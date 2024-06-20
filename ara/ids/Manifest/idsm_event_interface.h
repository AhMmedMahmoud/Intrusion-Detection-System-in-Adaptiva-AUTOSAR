#ifndef IDSM_EVENT_INTERFACE_H
#define IDSM_EVENT_INTERFACE_H

#include <string>

namespace ara
{
    namespace idsm
    {
        namespace manifest
        {
            /*
            "EventTypeSpecifier" : "BSW_2",
            "EventSymbolName" : "",
            "EventID" : 2,
            "SensorInstanceID" : 2,
            "ReportingMode" : "OFF",
            "FilterChain" : "idsMFilterChain2",
            "Severity" : 0,
            "PersistentStorage" : true,
            "ContextData" : ""
            */

            class IdsmEventInterface
            {
            private:
                /***** attributes ******/
                std::string mSpecifier;
                std::string mSymbolName;
                uint16_t mId;
                uint8_t mSensorInstanceID;
                std::string mReportingMode;
                std::string mFilterChain;
                uint8_t mSeverity;
                bool mPersistentStorage;
                std::string mContextData;
                
            public:
                /******** constructor ********/
                IdsmEventInterface(){}

                /******** getter and setter ******/
                std::string getSpecifer(){return mSpecifier;}
                std::string getSymbolName(){return mSymbolName;}
                uint16_t getID(){return mId;}
                uint8_t getSensorInstanceID(){return mSensorInstanceID;}
                std::string getReportingMode(){return mReportingMode;}
                std::string getFilterChain(){return mFilterChain;}
                uint8_t getSeverity(){return mSeverity;}
                bool getPersistentStorage(){return mPersistentStorage;}
                std::string getContextData(){return mContextData;}
                void setSpecifer(std::string specifer){mSpecifier = specifer;}
                void setSymbolName(std::string symbolName){mSymbolName = symbolName;}
                void setID(uint16_t id){ mId = id;}
                void setSensorInstanceID(uint8_t sensorInstanceID){ mSensorInstanceID = sensorInstanceID;}
                void setReportingMode(std::string reportingMode){mReportingMode = reportingMode;}
                void setFilterChain(std::string filterChain){mFilterChain = filterChain;}
                void setSeverity(uint8_t severity) {mSeverity = severity;}
                void setPersistentStorage(bool persistentStorage) {mPersistentStorage = persistentStorage;}
                void setContextData(std::string contextData) {mContextData = contextData;}
            };
        }
    }
}

#endif