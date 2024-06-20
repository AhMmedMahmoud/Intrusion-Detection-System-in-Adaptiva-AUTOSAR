cmake_minimum_required(VERSION 3.14)
project(CommunicationManager)
set(CMAKE_CXX_STANDARD 14)

add_library(
   araCom

   ############################### helper #################################
   helper/abstract_state_machine.h
   helper/concurrent_queue.h
   helper/state.h
   helper/fsm.h
   helper/ipv4_address.h
   helper/payload_helper.h
   helper/payload_helper.cpp
   helper/instance_id.h
   
   ######################## network_binding ###############################
   ## sockets ##
   network_binding/sockets/include/communicator.h
   network_binding/sockets/src/communicator.cpp
   network_binding/sockets/include/network_socket.h
   network_binding/sockets/src/network_socket.cpp
   network_binding/sockets/include/poller.h
   network_binding/sockets/src/poller.cpp
   network_binding/sockets/include/tcp_client.h
   network_binding/sockets/src/tcp_client.cpp
   network_binding/sockets/include/tcp_listener.h
   network_binding/sockets/src/tcp_listener.cpp
   network_binding/sockets/include/udp_client.h
   network_binding/sockets/src/udp_client.cpp

   ## serialization
   network_binding/serialization/serializer.cpp
   network_binding/serialization/serializer.h
   network_binding/serialization/deserializer.cpp
   network_binding/serialization/deserializer.h

   ## someip message ##
   network_binding/someip/someipMsg/someip_message.h
   network_binding/someip/someipMsg/someip_message.cpp

   ## someip_rpc_message ##
   network_binding/someip/someipRpcMsg/someip_rpc_message.cpp
   network_binding/someip/someipRpcMsg/someip_rpc_message.h

   ## rpcs ##
   network_binding/someip/rpc/rpcs_responser.h
   network_binding/someip/rpc/rpcs_responser.cpp
   network_binding/someip/rpc/socket_rpc_server.h
   network_binding/someip/rpc/socket_rpc_server.cpp
   network_binding/someip/rpc/rpcs_requester.h
   network_binding/someip/rpc/rpcs_requester.cpp
   network_binding/someip/rpc/socket_rpc_client.h
   network_binding/someip/rpc/socket_rpc_client.cpp

   ## events ##
   network_binding/someip/events/fsm/notsubscribed_state.h
   network_binding/someip/events/fsm/service_down_state.h
   network_binding/someip/events/fsm/subscribed_state.h
   network_binding/someip/events/event_requester.cpp
   network_binding/someip/events/event_requester.h
   network_binding/someip/events/socket_event_client.cpp
   network_binding/someip/events/socket_event_client.h
   network_binding/someip/events/socket_event_server.cpp
   network_binding/someip/events/socket_event_server.h
   network_binding/someip/events/event_provider.cpp
   network_binding/someip/events/event_provider.h

   ## fields ##
   network_binding/someip/fields/field_requester.cpp
   network_binding/someip/fields/field_requester.h
   network_binding/someip/fields/socket_field_client.cpp
   network_binding/someip/fields/socket_field_client.h
   network_binding/someip/fields/socket_field_server.cpp
   network_binding/someip/fields/socket_field_server.h
   network_binding/someip/fields/field_provider.cpp
   network_binding/someip/fields/field_provider.h

   ## someip_sd message ##
   network_binding/someip/someipSdMsg/someip_sd_message.cpp
   network_binding/someip/someipSdMsg/someip_sd_message.h

   ## entry ##
   network_binding/someip/someipSdMsg/entry/entry_deserializer.h
   network_binding/someip/someipSdMsg/entry/entry.cpp
   network_binding/someip/someipSdMsg/entry/entry.h
   network_binding/someip/someipSdMsg/entry/eventgroup_entry.cpp
   network_binding/someip/someipSdMsg/entry/eventgroup_entry.h
   network_binding/someip/someipSdMsg/entry/service_entry.cpp
   network_binding/someip/someipSdMsg/entry/service_entry.h

   ## option ##
   network_binding/someip/someipSdMsg/option/ipv4_endpoint_option.cpp
   network_binding/someip/someipSdMsg/option/ipv4_endpoint_option.h
   network_binding/someip/someipSdMsg/option/loadbalancing_option.cpp
   network_binding/someip/someipSdMsg/option/loadbalancing_option.h
   network_binding/someip/someipSdMsg/option/option_deserializer.h
   network_binding/someip/someipSdMsg/option/option.cpp
   network_binding/someip/someipSdMsg/option/option.h
 
   ## DiscoveryProcess ##
   network_binding/someip/DiscoveryProcess/Process.h
   network_binding/someip/DiscoveryProcess/Process.cpp   

   ## service which is an event with rpcs ##
   network_binding/someip/service/event_rpcs/provider.h
   network_binding/someip/service/event_rpcs/provider.cpp
   network_binding/someip/service/event_rpcs/requester.h
   network_binding/someip/service/event_rpcs/requester.cpp
   network_binding/someip/service/event_rpcs/methods.h
 
   ## service which is an event only ##
   network_binding/someip/service/event_Only/event_service_provider.h
   network_binding/someip/service/event_Only/event_service_provider.cpp
   network_binding/someip/service/event_Only/event_service_requester.h
   network_binding/someip/service/event_Only/event_service_requester.cpp

   ## service which is an field only ##
   network_binding/someip/service/field_Only/field_service_provider.h
   network_binding/someip/service/field_Only/field_service_provider.cpp
   network_binding/someip/service/field_Only/field_service_requester.h
   network_binding/someip/service/field_Only/field_service_requester.cpp

   ## service which is an rpcs only ##
   network_binding/someip/service/rpcs_Only/sm_rpcs_service_provider.h
   network_binding/someip/service/rpcs_Only/sm_rpcs_service_provider.cpp
   network_binding/someip/service/rpcs_Only/sm_rpcs_service_requester.h
   network_binding/someip/service/rpcs_Only/sm_rpcs_service_requester.cpp
   network_binding/someip/service/rpcs_Only/ucmMaster_ucm_rpcs_service_provider.h
   network_binding/someip/service/rpcs_Only/ucmMaster_ucm_rpcs_service_provider.cpp
   network_binding/someip/service/rpcs_Only/ucmMaster_ucm_rpcs_service_requester.h
   network_binding/someip/service/rpcs_Only/ucmMaster_ucm_rpcs_service_requester.cpp
   network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_provider.h
   network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_provider.cpp
   network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_requester.h
   network_binding/someip/service/rpcs_Only/ucmMaster_ota_rpcs_service_requester.cpp

   ## config ##
   network_binding/config.h

   ######################### language_binding #############################
   ## proxy_skeleton ##
   language_binding/Proxy_Skeleton/Proxy.h
   language_binding/Proxy_Skeleton/Proxy.cpp
   language_binding/Proxy_Skeleton/Skeleton.h
   language_binding/Proxy_Skeleton/Skeleton.cpp

   ## sm_interfaces ##
   language_binding/sm_interfaces/TriggerInProxy.h
   language_binding/sm_interfaces/TriggerInProxy.cpp
   language_binding/sm_interfaces/TriggerInSkeleton.h
   language_binding/sm_interfaces/TriggerInSkeleton.cpp
   language_binding/sm_interfaces/TriggerOutProxy.h
   language_binding/sm_interfaces/TriggerOutProxy.cpp
   language_binding/sm_interfaces/TriggerOutSkeleton.h
   language_binding/sm_interfaces/TriggerOutSkeleton.cpp
   language_binding/sm_interfaces/TriggerInOutProxy.h
   language_binding/sm_interfaces/TriggerInOutProxy.cpp
   language_binding/sm_interfaces/TriggerInOutSkeleton.h
   language_binding/sm_interfaces/TriggerInOutSkeleton.cpp
   language_binding/sm_interfaces/SM_RPCSProxy.h
   language_binding/sm_interfaces/SM_RPCSProxy.cpp
   language_binding/sm_interfaces/SM_RPCSSkeleton.h
   language_binding/sm_interfaces/SM_RPCSSkeleton.cpp

   ## V2X_interfaces ##
   language_binding/V2X_interfaces/POTI_Management_Proxy.h
   language_binding/V2X_interfaces/POTI_Management_Proxy.cpp
   language_binding/V2X_interfaces/POTI_Management_Skeleton.h
   language_binding/V2X_interfaces/POTI_Management_Skeleton.cpp
   language_binding/V2X_interfaces/CAM_VDP_Proxy.h
   language_binding/V2X_interfaces/CAM_VDP_Proxy.cpp
   language_binding/V2X_interfaces/CAM_VDP_Skeleton.h
   language_binding/V2X_interfaces/CAM_VDP_Skeleton.cpp
   language_binding/V2X_interfaces/DENM_VDP_Proxy.h
   language_binding/V2X_interfaces/DENM_VDP_Proxy.cpp
   language_binding/V2X_interfaces/DENM_VDP_Skeleton.h
   language_binding/V2X_interfaces/DENM_VDP_Skeleton.cpp
   language_binding/V2X_interfaces/DENM_Control_Proxy.h
   language_binding/V2X_interfaces/DENM_Control_Proxy.cpp
   language_binding/V2X_interfaces/DENM_Control_Skeleton.h
   language_binding/V2X_interfaces/DENM_Control_Skeleton.cpp
   language_binding/V2X_interfaces/POTI_VDP_Proxy.h
   language_binding/V2X_interfaces/POTI_VDP_Proxy.cpp
   language_binding/V2X_interfaces/POTI_VDP_Skeleton.h
   language_binding/V2X_interfaces/POTI_VDP_Skeleton.cpp
   language_binding/V2X_interfaces/CAM_Control_Proxy.h
   language_binding/V2X_interfaces/CAM_Control_Proxy.cpp
   language_binding/V2X_interfaces/CAM_Control_Skeleton.h
   language_binding/V2X_interfaces/CAM_Control_Skeleton.cpp
   language_binding/V2X_interfaces/Event_DENM_Proxy.h
   language_binding/V2X_interfaces/Event_DENM_Proxy.cpp
   language_binding/V2X_interfaces/Event_DENM_Skeleton.h
   language_binding/V2X_interfaces/Event_DENM_Skeleton.cpp

   ## ucm_interfaces ##
   language_binding/ucm_interfaces/ucmMaster_ucm_proxy.h
   language_binding/ucm_interfaces/ucmMaster_ucm_proxy.cpp
   language_binding/ucm_interfaces/ucmMaster_ucm_skeleton.h
   language_binding/ucm_interfaces/ucmMaster_ucm_skeleton.cpp
   language_binding/ucm_interfaces/ucmMaster_ota_proxy.h
   language_binding/ucm_interfaces/ucmMaster_ota_proxy.cpp
   language_binding/ucm_interfaces/ucmMaster_ota_skeleton.h
   language_binding/ucm_interfaces/ucmMaster_ota_skeleton.cpp
   language_binding/ucm_interfaces/PackageManagementProxy.h
   language_binding/ucm_interfaces/PackageManagementProxy.cpp
   language_binding/ucm_interfaces/PackageManagementSkeleton.h
   language_binding/ucm_interfaces/PackageManagementSkeleton.cpp
   language_binding/ucm_interfaces/TransferStateProxy.h
   language_binding/ucm_interfaces/TransferStateProxy.cpp
   language_binding/ucm_interfaces/TransferStateSkeleton.h
   language_binding/ucm_interfaces/TransferStateSkeleton.cpp
   language_binding/ucm_interfaces/CampaignStateProxy.h
   language_binding/ucm_interfaces/CampaignStateProxy.cpp
   language_binding/ucm_interfaces/CampaignStateSkeleton.h
   language_binding/ucm_interfaces/CampaignStateSkeleton.cpp
   language_binding/ucm_interfaces/SwNameVersionProxy.h
   language_binding/ucm_interfaces/SwNameVersionProxy.cpp
   language_binding/ucm_interfaces/SwNameVersionSkeleton.h
   language_binding/ucm_interfaces/SwNameVersionSkeleton.cpp
)

################################################################################
##                                execuatables                                ##
################################################################################

#### execuatables for SOMEIP_Rpc ####
add_executable(someip samples/demo_someipRpc.cpp)
target_link_libraries(someip araCom)


#### execuatables for rpc ####
#add_executable(server_rpc samples/demo_rpc_server.cpp)
#target_link_libraries(server_rpc araCom)
#add_executable(client_rpc samples/demo_rpc_client.cpp)
#target_link_libraries(client_rpc araCom)


#### executables for fields ####
add_executable(client_field samples/demo_field_client.cpp)
target_link_libraries(client_field araCom)
add_executable(server_field samples/demo_field_server.cpp)
target_link_libraries(server_field araCom)


#### execuatables for ServiceDiscoveryProcess ####
add_executable(process samples/demo_process.cpp)
target_link_libraries(process araCom)


#### execuatables for service provider ####
#add_executable(provider samples/demo_service_provider.cpp)
#target_link_libraries(provider araCom)


#### execuatables for service requester ####
#add_executable(requester samples/demo_service_requester.cpp)
#target_link_libraries(requester araCom)


#### executables for proxy ####
add_executable(proxy samples/demo_proxy.cpp)
target_link_libraries(proxy araCom)

#### executables for skeleton ####
add_executable(skeleton samples/demo_skeleton.cpp)
target_link_libraries(skeleton araCom)

#### serialization ####
add_executable(serialization_test samples/serialization_test.cpp)
target_link_libraries(serialization_test araCom)

#####################################################################################
##                                  SM excutables                                  ##
#####################################################################################

#### executables for TriggerInSkeleton ####
add_executable(TriggerInSkeleton samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp)
target_link_libraries(TriggerInSkeleton araCom)

#### executables for TriggerInProxy ####
add_executable(TriggerInProxy samples/sm_interfaces_demos/demo_TriggerInProxy.cpp)
target_link_libraries(TriggerInProxy araCom)

#### executables for TriggerOutSkeleton ####
add_executable(TriggerOutSkeleton samples/sm_interfaces_demos/demo_TriggerOutSkeleton.cpp)
target_link_libraries(TriggerOutSkeleton araCom)

#### executables for TriggerOutProxy ####
add_executable(TriggerOutProxy samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp)
target_link_libraries(TriggerOutProxy araCom)


#####################################################################################
##                                  V2X excutables                                 ##
#####################################################################################

#### executables for CAM_VDP_Skeleton ####
add_executable(CAM_VDP_Skeleton samples/V2X_interfaces_demos/demo_CAM_VDP_Skeleton.cpp)
target_link_libraries(CAM_VDP_Skeleton araCom)

#### executables for CAM_VDP_Proxy ####
add_executable(CAM_VDP_Proxy samples/V2X_interfaces_demos/demo_CAM_VDP_Proxy.cpp)
target_link_libraries(CAM_VDP_Proxy araCom)

#### executables for CAM_VDP_Proxy showing EventDriven approach ####
add_executable(eventDriven_CAM_VDP_Proxy samples/V2X_interfaces_demos/demo_eventDriven_CAM_VDP_Proxy.cpp)
target_link_libraries(eventDriven_CAM_VDP_Proxy araCom)


#### executables for DENM_VDP_Skeleton ####
add_executable(DENM_VDP_Skeleton samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp)
target_link_libraries(DENM_VDP_Skeleton araCom)

#### executables for DENM_VDP_Proxy ####
add_executable(DENM_VDP_Proxy samples/V2X_interfaces_demos/demo_DENM_VDP_Proxy.cpp)
target_link_libraries(DENM_VDP_Proxy araCom)


#### executables for DENM_VDP_Server ####
add_executable(DENM_Server samples/V2X_interfaces_demos/demo_DENM_Server.cpp)
target_link_libraries(DENM_Server araCom)

#### executables for DENM_VDP_Client ####
add_executable(DENM_Client samples/V2X_interfaces_demos/demo_DENM_Client.cpp)
target_link_libraries(DENM_Client araCom)

#### executables for proxy ####
add_executable(rpcs_proxy samples/sm_interfaces_demos/demo_sm_rpcs_proxy.cpp)
target_link_libraries(rpcs_proxy araCom)

#### executables for skeleton ####
add_executable(rpcs_skeleton samples/sm_interfaces_demos/demo_sm_rpcs_skeleton.cpp)
target_link_libraries(rpcs_skeleton araCom)

#####################################################################################
##                                  ucm excutables                                 ##
#####################################################################################

#### executables for proxy ####
add_executable(demo_ucmMaster_ucm_proxy samples/ucm_interfaces_demos/demo_ucmMaster_ucm_proxy.cpp)
target_link_libraries(demo_ucmMaster_ucm_proxy araCom)

#### executables for skeleton ####
add_executable(demo_ucmMaster_ucm_skeleton samples/ucm_interfaces_demos/demo_ucmMaster_ucm_skeleton.cpp)
target_link_libraries(demo_ucmMaster_ucm_skeleton araCom)


#### executables for proxy ####
add_executable(demo_ucmMaster_ota_proxy samples/ucm_interfaces_demos/demo_ucmMaster_ota_proxy.cpp)
target_link_libraries(demo_ucmMaster_ota_proxy araCom)

#### executables for skeleton ####
add_executable(demo_ucmMaster_ota_skeleton samples/ucm_interfaces_demos/demo_ucmMaster_ota_skeleton.cpp)
target_link_libraries(demo_ucmMaster_ota_skeleton araCom)