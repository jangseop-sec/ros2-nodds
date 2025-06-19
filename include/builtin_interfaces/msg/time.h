#ifndef BUILTIN_INTEFACES__MSG__TIME_H_
#define BUILTIN_INTEFACES__MSG__TIME_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct Time
{
  int32_t sec;
  uint32_t nanosec;
} builtin_interfaces__msg__Time;

#ifdef __cplusplus
}
#endif

#endif // BUILTIN_INTEFACES__MSG__TIME_H_