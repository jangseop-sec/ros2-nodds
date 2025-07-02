// Copyright 2019 Robert Bosch GmbH
// Copyright 2020 Christophe Bedard
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tracetools/tracetools.h"
#include "rcl/node.h"
#include "rcl/init.h"

#ifndef TRACETOOLS_DISABLED

bool ros_trace_compile_status()
{
  return false;
}

void TRACEPOINT(rcl_init, const void * context_handle) {}

void TRACEPOINT(rcl_node_init, const void * node_handle, const void * rmw_handle, const char * node_name, const char * node_namespace) {}

void TRACEPOINT(rmw_publisher_init, const void * rmw_publisher_handle, const uint8_t * gid) {}

void TRACEPOINT(rcl_publisher_init, const void * publisher_handle, const void * node_handle, const void * rmw_publisher_handle, const char * topic_name, const size_t queue_depth) {}

void TRACEPOINT(rclcpp_publish, const void * publisher_handle, const void * message) {}

void TRACEPOINT(rcl_publish, const void * publisher_handle, const void * message) {}

void TRACEPOINT(rmw_publish, const void * message) {}

void TRACEPOINT(rmw_subscription_init, const void * rmw_subscription_handle, const uint8_t * gid) {}

void TRACEPOINT(rcl_subscription_init, const void * subscription_handle, const void * node_handle, const void * rmw_subscription_handle, const char * topic_name, const size_t queue_depth) {}

void TRACEPOINT(rclcpp_subscription_init, const void * subscription_handle, const void * subscription) {}

void TRACEPOINT(rclcpp_subscription_callback_added, const void * subscription, const void * callback) {}

void TRACEPOINT(rmw_take, const void * rmw_subscription_handle, const void * message, int64_t source_timestamp, const bool taken) {}

void TRACEPOINT(rcl_take, const void * message) {}

void TRACEPOINT(rclcpp_take, const void * message) {}

void TRACEPOINT(rcl_service_init, const void * service_handle, const void * node_handle, const void * rmw_service_handle, const char * service_name) {}

void TRACEPOINT(rclcpp_service_callback_added, const void * service_handle, const void * callback) {}

void TRACEPOINT(rcl_client_init, const void * client_handle, const void * node_handle, const void * rmw_client_handle, const char * service_name) {}

void TRACEPOINT(rcl_timer_init, const void * timer_handle, int64_t period) {}

void TRACEPOINT(rclcpp_timer_callback_added, const void * timer_handle, const void * callback) {}

void TRACEPOINT(rclcpp_timer_link_node, const void * timer_handle, const void * node_handle) {}

void TRACEPOINT(rclcpp_callback_register, const void * callback, const char * function_symbol) {}

void TRACEPOINT(callback_start, const void * callback, const bool is_intra_process) {}

void TRACEPOINT(callback_end, const void * callback) {}

void TRACEPOINT(rcl_lifecycle_state_machine_init, const void * node_handle, const void * state_machine) {}

void TRACEPOINT(rcl_lifecycle_transition, const void * state_machine, const char * start_label, const char * goal_label) {}

void TRACEPOINT(rclcpp_executor_get_next_ready) {}

void TRACEPOINT(rclcpp_executor_wait_for_work, const int64_t timeout) {}

void TRACEPOINT(rclcpp_executor_execute, const void * handle) {}


#ifndef _WIN32
# pragma GCC diagnostic pop
#else
# pragma warning(pop)
#endif

#endif  // TRACETOOLS_DISABLED
