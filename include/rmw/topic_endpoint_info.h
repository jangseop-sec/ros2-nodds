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


#ifdef __cplusplus
}
#endif

#endif  // RMW_TOPIC_ENDPOINT_INFO_H_