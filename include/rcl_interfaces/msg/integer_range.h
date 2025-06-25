#ifndef RCL_INTERFACES__MSG__INTEGER_RANGE_H_
#define RCL_INTERFACES__MSG__INTEGER_RANGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct IntegerRange
{
  int64_t from_value;  // The lower bound of the range
  int64_t to_value;    // The upper bound of the range
  int64_t step;        // The step size for the range
} rcl_interfaces__msg__IntegerRange;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__INTEGER_RANGE_H_