#ifndef RCL_INTERFACES__MSG__PARAMETER_DESCRIPTOR_H_
#define RCL_INTERFACES__MSG__PARAMETER_DESCRIPTOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

#include "rcl_interfaces/msg/integer_range.h"
#include "rcl_interfaces/msg/floating_point_range.h"

typedef rcl_interfaces__msg__IntegerRange IntegerRange;
typedef rcl_interfaces__msg__FloatingPointRange FloatingPointRange;

typedef struct ParameterDescriptor
{
  char * name;  // Name of the parameter
  uint8_t type;  // Type of the parameter (e.g., "int", "double", "string")
  char * description;  // Description of the parameter
  char * additional_constraints;  // Additional constraints for the parameter
  bool read_only;  // Indicates if the parameter is read-only
  bool dynamic_typing;  // Indicates if the parameter supports dynamic typing
  IntegerRange * integer_range;  // Optional integer range for the parameter
  FloatingPointRange * floating_point_range;  // Optional floating point range for the parameter
} rcl_interfaces__msg__ParameterDescriptor;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_DESCRIPTOR_H_