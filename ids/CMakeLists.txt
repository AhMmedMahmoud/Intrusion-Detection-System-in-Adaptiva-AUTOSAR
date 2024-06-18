cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(ids)

add_subdirectory(../com ${CMAKE_BINARY_DIR}/com)
add_subdirectory(../crypto ${CMAKE_BINARY_DIR}/crypto)

add_library(
   ids
   ##### idsm functional #######
   event_reporter.h
   event_reporter.cpp
   common.h

   ############ ids ############
   ids/ids_message.h
   ids/ids_message.cpp
   ### event_frame ###
   ids/event_frame/event_frame.h
   ids/event_frame/event_frame.cpp
   ids/event_frame/protocol_header.h
   ids/event_frame/protocol_header.cpp
   ### timestamp ###
   ids/timestamp/timestamp.h
   ids/timestamp/timestamp.cpp
   ### context_data ###
   ids/context_data/context_data.h
   ids/context_data/context_data.cpp
   ### signature ###
   ids/signature/signature.h
   ids/signature/signature.cpp

   ############# idsm ##########
   idsm/idsm.h
   idsm/idsm.cpp
   ############# idsr ##########
   idsr/idsr.h
   idsr/idsr.cpp

   ########### Manifest ########
   ### manager ###
   Manifest/manager/manifest_manager.h
   Manifest/manager/manifest_manager.cpp
   ### metadata ###
   Manifest/metadata/manifest_types.h
   Manifest/metadata/manifest_headers.h
   Manifest/metadata/security_event_aggregation_filter.h
   Manifest/metadata/security_event_context_mapping.h
   Manifest/metadata/security_event_context_props.h
   Manifest/metadata/security_event_definition.h
   Manifest/metadata/security_event_filter_chain.h
   Manifest/metadata/security_event_one_every_n_filter.h
   Manifest/metadata/security_event_state_filter.h
   Manifest/metadata/security_event_threshold_filter.h
   ### shared ###
   Manifest/shared/shared_events.h
   Manifest/shared/shared_events.cpp
   Manifest/shared/shared_filterchains.h
   Manifest/shared/shared_filterchains.cpp
   Manifest/shared/shared_eventContextMappings.h
   Manifest/shared/shared_eventContextMappings.cpp
   Manifest/shared/shared_stateFilters.h
   Manifest/shared/shared_stateFilters.cpp
   Manifest/shared/shared_thresholdFilters.h
   Manifest/shared/shared_thresholdFilters.cpp
   Manifest/shared/shared_aggregationFilters.h
   Manifest/shared/shared_aggregationFilters.cpp
   Manifest/shared/shared_everyOneNFilters.h
   Manifest/shared/shared_everyOneNFilters.cpp
)

################################################################################
##                                execuatables                                ##
################################################################################

add_executable(EventFrame samples/internalClassesofIDSMessage/EventFrame.cpp)
target_link_libraries(EventFrame ids)
target_link_libraries(EventFrame araCom)
target_link_libraries(EventFrame Core)
target_link_libraries(EventFrame Crypto)
target_link_libraries(EventFrame cryptopp)
target_include_directories(EventFrame PUBLIC /usr/include/cryptopp)

add_executable(Timestamp samples/internalClassesofIDSMessage/Timestamp.cpp)
target_link_libraries(Timestamp ids)
target_link_libraries(Timestamp araCom)
target_link_libraries(Timestamp Core)
target_link_libraries(Timestamp Crypto)
target_link_libraries(Timestamp cryptopp)
target_include_directories(Timestamp PUBLIC /usr/include/cryptopp)

add_executable(ContextData samples/internalClassesofIDSMessage/ContextData.cpp)
target_link_libraries(ContextData ids)
target_link_libraries(ContextData araCom)
target_link_libraries(ContextData Core)
target_link_libraries(ContextData Crypto)
target_link_libraries(ContextData cryptopp)
target_include_directories(ContextData PUBLIC /usr/include/cryptopp)

add_executable(Signature samples/internalClassesofIDSMessage/Signature.cpp)
target_link_libraries(Signature ids)
target_link_libraries(Signature araCom)
target_link_libraries(Signature Core)
target_link_libraries(Signature Crypto)
target_link_libraries(Signature cryptopp)
target_include_directories(Signature PUBLIC /usr/include/cryptopp)

add_executable(IDSMessage samples/demo_idsMessage.cpp)
target_link_libraries(IDSMessage ids)
target_link_libraries(IDSMessage araCom)
target_link_libraries(IDSMessage Core)
target_link_libraries(IDSMessage Crypto)
target_link_libraries(IDSMessage cryptopp)
target_include_directories(IDSMessage PUBLIC /usr/include/cryptopp)

add_executable(Manager samples/demo_manifest_manager.cpp)
target_link_libraries(Manager ids)
target_link_libraries(Manager araCom)
target_link_libraries(Manager Core)
target_link_libraries(Manager Crypto)
target_link_libraries(Manager cryptopp)
target_include_directories(Manager PUBLIC /usr/include/cryptopp)

add_executable(idsm samples/demo_idsm.cpp)
target_link_libraries(idsm ids)
target_link_libraries(idsm araCom)
target_link_libraries(idsm Core)
target_link_libraries(idsm Crypto)
target_link_libraries(idsm cryptopp)
target_include_directories(idsm PUBLIC /usr/include/cryptopp)

add_executable(idsr samples/demo_idsr.cpp)
target_link_libraries(idsr ids)
target_link_libraries(idsr araCom)
target_link_libraries(idsr Core)
target_link_libraries(idsr Crypto)
target_link_libraries(idsr cryptopp)
target_include_directories(idsr PUBLIC /usr/include/cryptopp)

add_executable(sensor samples/demo_sensor.cpp)
target_link_libraries(sensor ids)
target_link_libraries(sensor araCom)
target_link_libraries(sensor Core)
target_link_libraries(sensor Crypto)
target_link_libraries(sensor cryptopp)
target_include_directories(sensor PUBLIC /usr/include/cryptopp)