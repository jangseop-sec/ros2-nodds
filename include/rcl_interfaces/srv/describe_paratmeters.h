#ifndef RCL_INTERFACES__SRV__DESCRIBE_PARATMETERS_H_
#define RCL_INTERFACES__SRV__DESCRIBE_PARATMETERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl_interfaces/msg/parameter_descriptor.h"

typedef rcl_interfaces__msg__ParameterDescriptor ParameterDescriptor;

typedef struct rcl_interfaces__srv__DescribeParameters_Request
{
  char ** names;  // Array of parameter names to describe
  ParameterDescriptor * descriptors;  // Array of parameter descriptors
} rcl_interfaces__srv__DescribeParameters_Request;


#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__DESCRIBE_PARATMETERS_H_