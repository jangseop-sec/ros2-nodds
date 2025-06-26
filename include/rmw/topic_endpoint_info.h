#ifndef RMW_TOPIC_ENDPOINT_INFO_H_
#define RMW_TOPIC_ENDPOINT_INFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/types.h"
#include "rcutils/allocator.h"

typedef struct rmw_topic_endpoint_info_s
{
  /// Name of the node
  const char * node_name;
  /// Namespace of the node
  const char * node_namespace;
  /// The associated topic type
  const char * topic_type;
  /// The endpoint type
  rmw_endpoint_type_t endpoint_type;
  /// The GID of the endpoint
  uint8_t endpoint_gid[RMW_GID_STORAGE_SIZE];
  /// QoS profile of the endpoint
  rmw_qos_profile_t qos_profile;
} rmw_topic_endpoint_info_t;

rmw_topic_endpoint_info_t
rmw_get_zero_initialized_topic_endpoint_info(void);

rmw_ret_t
_rmw_topic_endpoint_info_fini_str(
  const char ** topic_endpoint_info_str,
  rcutils_allocator_t * allocator);

rmw_ret_t
_rmw_topic_endpoint_info_fini_node_name(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  rcutils_allocator_t * allocator);

rmw_ret_t
_rmw_topic_endpoint_info_fini_node_namespace(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  rcutils_allocator_t * allocator);

rmw_ret_t
_rmw_topic_endpoint_info_fini_topic_type(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_fini(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  rcutils_allocator_t * allocator);

rmw_ret_t
_rmw_topic_endpoint_info_copy_str(
  const char ** topic_endpoint_info_str,
  const char * str,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_set_topic_type(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  const char * topic_type,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_set_node_name(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  const char * node_name,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_set_node_namespace(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  const char * node_namespace,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_set_endpoint_type(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  rmw_endpoint_type_t type);

rmw_ret_t
rmw_topic_endpoint_info_set_gid(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  const uint8_t * gid,
  size_t size);

rmw_ret_t
rmw_topic_endpoint_info_set_qos_profile(
  rmw_topic_endpoint_info_t * topic_endpoint_info,
  const rmw_qos_profile_t * qos_profile);

#ifdef __cplusplus
}
#endif

#endif  // RMW_TOPIC_ENDPOINT_INFO_H_