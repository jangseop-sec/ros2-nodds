#ifndef BUILTIN_INTERFACES__MSG__DURATION_H_
#define BUILTIN_INTERFACES__MSG__DURATION_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct Duration
{
  int32_t sec;
  uint32_t nanosec;
} builtin_interfaces__msg__Duration;

#ifdef __cplusplus
}
#endif

#endif // BUILTIN_INTERFACES__MSG__DURATION_H_