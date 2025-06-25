#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_H_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "builtin_interfaces/msg/time.h"
#include "rcl_interfaces/msg/parameter.h"

typedef builtin_interfaces__msg__Time Time;
typedef rcl_interfaces__msg__Parameter Parameter;

typedef struct ParameterEvent
{
  Time stamp;  // Timestamp of the event
  char * node;  // Name of the node that generated the event  
  Parameter * new_parameters;  // Array of new parameters
  Parameter * changed_parameters;  // Array of changed parameters
  Parameter * deleted_parameters;  // Array of deleted parameters
} rcl_interfaces__msg__ParameterEvent;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_H_