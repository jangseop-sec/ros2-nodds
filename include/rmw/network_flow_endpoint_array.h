#ifndef RMW__NETWORK_FLOW_ENDPOINT_ARRAY_H_
#define RMW__NETWORK_FLOW_ENDPOINT_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcutils/allocator.h"

#include "rmw/network_flow_endpoint.h"
#include "rmw/types.h"

/// Structure to hold an arrary of network_flow_endpoint_t
typedef struct rmw_network_flow_endpoint_array_s
{
  /// Size of the array
  size_t size;
  /// Array of rmw_network_flow_endpoint_t
  rmw_network_flow_endpoint_t * network_flow_endpoint;
  /// Allocator
  rcutils_allocator_t * allocator;
} rmw_network_flow_endpoint_array_t;

rmw_network_flow_endpoint_array_t
rmw_get_zero_initialized_network_flow_endpoint_array(void);

rmw_ret_t
rmw_network_flow_endpoint_array_check_zero(
  const rmw_network_flow_endpoint_array_t * network_flow_endpoint_array);

rmw_ret_t
rmw_network_flow_endpoint_array_init(
  rmw_network_flow_endpoint_array_t * network_flow_endpoint_array,
  size_t size,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_network_flow_endpoint_array_fini(
  rmw_network_flow_endpoint_array_t * network_flow_endpoint_array);


#ifdef __cplusplus
}
#endif

#endif  // RMW__NETWORK_FLOW_ENDPOINT_ARRAY_H_