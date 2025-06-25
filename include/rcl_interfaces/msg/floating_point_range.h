#ifndef RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_H_
#define RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

// Structure definition for FloatingPointRange message
typedef struct FloatingPointRange
{
  double from_value;
  double to_value;
  double step;
} rcl_interfaces__msg__FloatingPointRange;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_H_