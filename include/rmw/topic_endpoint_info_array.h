#ifndef RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_
#define RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "stddef.h"

#include "rmw/ret_types.h"
#include "rmw/topic_endpoint_info.h"

typedef struct rmw_topic_endpoint_info_array_s
{
  /// Size of the array.
  size_t size;
  /// Contiguous storage for topic endpoint information elements.
  rmw_topic_endpoint_info_t * info_array;
} rmw_topic_endpoint_info_array_t;

rmw_topic_endpoint_info_array_t
rmw_get_zero_initialized_topic_endpoint_info_array(void);

rmw_ret_t
rmw_topic_endpoint_info_array_check_zero(
  rmw_topic_endpoint_info_array_t * topic_endpoint_info_array);


rmw_ret_t
rmw_topic_endpoint_info_array_init_with_size(
  rmw_topic_endpoint_info_array_t * topic_endpoint_info_array,
  size_t size,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_topic_endpoint_info_array_fini(
  rmw_topic_endpoint_info_array_t * topic_endpoint_info_array,
  rcutils_allocator_t * allocator);

#ifdef __cplusplus
}
#endif

#endif  // RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_