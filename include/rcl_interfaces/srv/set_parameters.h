#ifndef RCL_INTERFACES__SRV__SET_PARAMETERS_H_
#define RCL_INTERFACES__SRV__SET_PARAMETERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl_interfaces/msg/parameter.h";
#include "rcl_interfaces/msg/set_parameter_result.h"

typedef rcl_interfaces__msg__Parameter Parameter;
typedef rcl_interfaces__msg__SetParameterResult SetParameterResult;

typedef struct rcl_interfaces__srv__SetParameters
{
  Parameter * parameters;  // Array of parameters to set
  SetParameterResult * results;  // Array of results corresponding to each parameter
} rcl_interfaces__srv__SetParameters;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__SET_PARAMETERS_H_