#ifndef RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_H_
#define RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct GetParameterTypes
{
  char ** names;
  uint8_t ** types;
} rcl_interfaces__srv__GetParameterTypes;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_H_