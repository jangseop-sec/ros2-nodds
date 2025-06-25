#ifndef RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_
#define RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "stddef.h"

#include "rmw/ret_types.h"
#include "rmw/topic_endpoint_info.h"

typedef struct RMW_PUBLIC_TYPE rmw_topic_endpoint_info_array_s
{
  /// Size of the array.
  size_t size;
  /// Contiguous storage for topic endpoint information elements.
  rmw_topic_endpoint_info_t * info_array;
} rmw_topic_endpoint_info_array_t;

inline 
rmw_topic_endpoint_info_array_t
rmw_get_zero_initialized_topic_endpoint_info_array(void)
{
#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif
  rmw_topic_endpoint_info_array_t zero = {0};
#ifdef __clang__
# pragma clang diagnostic pop
#endif
  return zero;
}

inline
rmw_ret_t
rmw_topic_endpoint_info_array_fini(
  rmw_topic_endpoint_info_array_t * topic_endpoint_info_array,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    RMW_SET_ERROR_MSG("allocator is null");
    return RMW_RET_INVALID_ARGUMENT;
  }

  if (!topic_endpoint_info_array) {
    RMW_SET_ERROR_MSG("topic_endpoint_info_array is null");
    return RMW_RET_INVALID_ARGUMENT;
  }

  rmw_ret_t ret;
  // free all const char * inside the topic_endpoint_info_t
  for (size_t i = 0u; i < topic_endpoint_info_array->size; i++) {
    ret = rmw_topic_endpoint_info_fini(&topic_endpoint_info_array->info_array[i], allocator);
    if (ret != RMW_RET_OK) {
      return ret;
    }
  }

  allocator->deallocate(topic_endpoint_info_array->info_array, allocator->state);
  topic_endpoint_info_array->info_array = NULL;
  topic_endpoint_info_array->size = 0;
  return RMW_RET_OK;
}

#ifdef __cplusplus
}
#endif

#endif  // RMW__TOPIC_ENDPOINT_INFO_ARRAY_H_