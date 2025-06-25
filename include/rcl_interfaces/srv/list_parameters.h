#ifndef RCL_INTERFACES__SRV__LIST_PARAMETERS_H_
#define RCL_INTERFACES__SRV__LIST_PARAMETERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "rcl_interfaces/msg/list_parameter_result.h"

typedef rcl_interfaces__msg__ListParameterResult ListParameterResult;

typedef struct ListParameters
{
  // Array of prefixes to search for parameters
  char ** prefixes;

  // Depth of the search, 0 for recursive
  uint64_t depth;

  // Result of the list parameters operation
  ListParameterResult result;
} rcl_interfaces__srv__ListParameters;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__LIST_PARAMETERS_H_