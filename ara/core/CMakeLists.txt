cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(Core)

add_library(
   Core

   error_code.h
   error_domain.h
   exception.h
   initialization.h
   initialization.cpp
   instance_id.h
   instance_specifier.cpp
   instance_specifier.h
   optional.h
   result.h
   Span.h
   string.h
   StringView.h
   utility.h
   vector.h

   ########### Manifest ########
   ### manager ###
   ../ids/Manifest/manager/manifest_manager.h
   ../ids/Manifest/manager/manifest_manager.cpp
   ### metadata ###
   ../ids/Manifest/metadata/manifest_types.h
   ../ids/Manifest/metadata/manifest_headers.h
   ../ids/Manifest/metadata/security_event_aggregation_filter.h
   ../ids/Manifest/metadata/security_event_context_mapping.h
   ../ids/Manifest/metadata/security_event_context_props.h
   ../ids/Manifest/metadata/security_event_definition.h
   ../ids/Manifest/metadata/security_event_filter_chain.h
   ../ids/Manifest/metadata/security_event_one_every_n_filter.h
   ../ids/Manifest/metadata/security_event_state_filter.h
   ../ids/Manifest/metadata/security_event_threshold_filter.h
   ### shared ###
   ../ids/Manifest/shared/shared_events.h
   ../ids/Manifest/shared/shared_events.cpp
   ../ids/Manifest/shared/shared_filterchains.h
   ../ids/Manifest/shared/shared_filterchains.cpp
   ../ids/Manifest/shared/shared_eventContextMappings.h
   ../ids/Manifest/shared/shared_eventContextMappings.cpp
   ../ids/Manifest/shared/shared_stateFilters.h
   ../ids/Manifest/shared/shared_stateFilters.cpp
   ../ids/Manifest/shared/shared_thresholdFilters.h
   ../ids/Manifest/shared/shared_thresholdFilters.cpp
   ../ids/Manifest/shared/shared_aggregationFilters.h
   ../ids/Manifest/shared/shared_aggregationFilters.cpp
   ../ids/Manifest/shared/shared_everyOneNFilters.h
   ../ids/Manifest/shared/shared_everyOneNFilters.cpp
)