#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_H_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl_interfaces/msg/parameter_descriptor.h"

typedef rcl_interfaces__msg__ParameterDescriptor ParameterDescriptor;

typedef struct ParameterEventDescriptors
{
  ParameterDescriptor * new_parameters;  // Array of new parameter descriptors
  ParameterDescriptor * changed_parameters;  // Array of changed parameter descriptors
  ParameterDescriptor * deleted_parameters;  // Array of deleted parameter descriptors
} rcl_interfaces__msg__ParameterEventDescriptors;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_H_