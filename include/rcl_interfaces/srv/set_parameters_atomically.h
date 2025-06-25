#ifndef RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_H_
#define RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl_interfaces/msg/parameter.h"
#include "rcl_interfaces/msg/set_parameter_result.h"

typedef rcl_interfaces__msg__Parameter Parameter;
typedef rcl_interfaces__msg__SetParameterResult SetParameterResult;

typedef struct SetParametersAtomically
{
  Parameter * parameters;  // Array of parameters to set
  SetParameterResult result;  // Result of the atomic set operation
} rcl_interfaces__srv__SetParametersAtomically;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_H_