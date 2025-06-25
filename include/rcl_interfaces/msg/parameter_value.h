#ifndef RCL_INTERFACES__MSG__PARAMETER_VALUE_H_
#define RCL_INTERFACES__MSG__PARAMETER_VALUE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct ParameterValue
{
  bool bool_value;
  int64_t integer_value;
  double double_value;
  char * string_value;
  uint8_t * byte_array_value;
  bool * bool_array_value;
  int64_t * integer_array_value;
  double * double_array_value;
  char ** string_array_value;
} rcl_interfaces__msg__ParameterValue;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_VALUE_H_