#ifndef RMW__NAMES_AND_TYPES_H_
#define RMW__NAMES_AND_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcutils/types/string_array.h"

typedef struct rmw_names_and_types_s
{
  /// Array of names
  rcutils_string_array_t names;

  /// Dynamic array of arrays of type names, with the same length as `names`
  rcutils_string_array_t * types;
} rmw_names_and_types_t;


#ifdef __cplusplus
}
#endif

#endif  // RMW__NAMES_AND_TYPES_H_