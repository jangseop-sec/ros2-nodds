#ifndef RCL_INTERFACES__SRV__GET_PARAMETERS_H_
#define RCL_INTERFACES__SRV__GET_PARAMETERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl_interfaces/msg/parameter_value.h"

typedef rcl_interfaces__msg__ParameterValue ParameterValue;

typedef struct GetParameters
{
  char ** names;  // Array of parameter names to get
  ParameterValue * values;  // Array of parameter values corresponding to the names
} rcl_interfaces__srv__GetParameters;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__GET_PARAMETERS_H_