#ifndef RMW__NAMES_AND_TYPES_H_
#define RMW__NAMES_AND_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcutils/types/string_array.h"
#include "rcutils/allocator.h"

#include "rmw/ret_types.h"

typedef struct rmw_names_and_types_s
{
  /// Array of names
  rcutils_string_array_t names;

  /// Dynamic array of arrays of type names, with the same length as `names`
  rcutils_string_array_t * types;
} rmw_names_and_types_t;

rmw_names_and_types_t
rmw_get_zero_initialized_names_and_types(void);

rmw_ret_t
rmw_names_and_types_check_zero(rmw_names_and_types_t * names_and_types);

rmw_ret_t
rmw_names_and_types_init(
  rmw_names_and_types_t * names_and_types,
  size_t size,
  rcutils_allocator_t * allocator);

rmw_ret_t
rmw_names_and_types_fini(rmw_names_and_types_t * names_and_types);

#ifdef __cplusplus
}
#endif

#endif  // RMW__NAMES_AND_TYPES_H_