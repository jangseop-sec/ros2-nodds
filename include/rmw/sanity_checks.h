#ifndef RMW__SANITY_CHECKS_H_
#define RMW__SANITY_CHECKS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/ret_types.h"
#include "rcutils/types/string_array.h"

rmw_ret_t
rmw_check_zero_rmw_string_array(
  rcutils_string_array_t * array);

#ifdef __cplusplus
}
#endif

#endif  // RMW__SANITY_CHECKS_H_