#ifndef RCL_INTERFACES__MSG__PARAMETER_H_
#define RCL_INTERFACES__MSG__PARAMETER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rcl_interfaces/msg/parameter_value.h"

typedef rcl_interfaces__msg__ParameterValue ParameterValue;

typedef struct Parameter
{
  char * name;  // Name of the parameter
  ParameterValue value;  // Value of the parameter
} rcl_interfaces__msg__Parameter;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_H_