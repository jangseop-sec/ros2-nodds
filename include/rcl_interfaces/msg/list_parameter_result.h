#ifndef RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_H_
#define RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct ListParameterResult
{
  char ** names;
  char ** prefixes;
} rcl_interfaces__msg__ListParameterResult;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_H_