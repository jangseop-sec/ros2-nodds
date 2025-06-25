#ifndef RCL_INTERFACES__MSG__LOG_H_
#define RCL_INTERFACES__MSG__LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RCL_LOG_DEBUG 10
#define RCL_LOG_INFO 20
#define RCL_LOG_WARN 30
#define RCL_LOG_ERROR 40
#define RCL_LOG_FATAL 50

#include <stdint.h>

#include "builtin_interfaces/msg/time.h"

typedef builtin_interfaces__msg__Time Time;

typedef struct Log
{
  uint8_t level;  // Log level, e.g., RCL_LOG_DEBUG, RCL_LOG_INFO, etc.
  Time stamp;     // Timestamp of the log message
  char * name;    // Name of the logger
  char * msg;     // Log message content
  char * file;    // Source file where the log was generated
  uint32_t line;  // Line number in the source file

} rcl_interfaces__msg__Log;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__LOG_H_