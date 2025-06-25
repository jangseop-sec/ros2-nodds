#ifndef RCL_INTERFACES_MSG_PARAMETER_TYPE_H
#define RCL_INTERFACES_MSG_PARAMETER_TYPE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PARAMETER_NOT_SET        0
#define PARAMETER_BOOL           1
#define PARAMETER_INTEGER        2
#define PARAMETER_DOUBLE         3
#define PARAMETER_STRING         4
#define PARAMETER_BYTE_ARRAY     5
#define PARAMETER_BOOL_ARRAY     6
#define PARAMETER_INTEGER_ARRAY  7
#define PARAMETER_DOUBLE_ARRAY   8
#define PARAMETER_STRING_ARRAY   9

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES_MSG_PARAMETER_TYPE_H