#ifndef RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_H_
#define RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>

// Message struct definition
typedef struct rcl_interfaces__msg__SetParameterResult
{
  bool successful;
  char * reason;
} rcl_interfaces__msg__SetParameterResult;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_H_