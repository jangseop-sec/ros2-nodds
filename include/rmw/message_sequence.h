#ifndef RMW__MESSAGE_SEQUENCE_H_
#define RMW__MESSAGE_SEQUENCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rcutils/allocator.h"

#include "rmw/types.h"

/// Structure to hold a sequence of ROS messages.
typedef struct rmw_message_sequence_s
{
  /// Array of pointers to ROS messages.
  void ** data;
  /// The number of valid entries in `data`.
  size_t size;
  /// The total allocated capacity of the data array.
  size_t capacity;
  /// The allocator used to allocate the data array.
  rcutils_allocator_t * allocator;
} rmw_message_sequence_t;

/// Structure to hold a sequence of message infos.
typedef struct rmw_message_info_sequence_s
{
  /// Array of message info.
  rmw_message_info_t * data;
  /// The number of valid entries in data.
  size_t size;
  /// The total allocated capacity of the data array.
  size_t capacity;
  /// The allocator used to allocate the data array.
  rcutils_allocator_t * allocator;
} rmw_message_info_sequence_t;

rmw_message_sequence_t
rmw_get_zero_initialized_message_sequence(void);

rmw_ret_t
rmw_message_sequence_init(
  rmw_message_sequence_t * sequence,
  size_t size,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_message_sequence_fini(rmw_message_sequence_t * sequence);

rmw_message_info_sequence_t
rmw_get_zero_initialized_message_info_sequence(void);

rmw_ret_t
rmw_message_info_sequence_init(
  rmw_message_info_sequence_t * sequence,
  size_t size,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_message_info_sequence_fini(rmw_message_info_sequence_t * sequence);

#ifdef __cplusplus
}
#endif

#endif  // RMW__MESSAGE_SEQUENCE_H_