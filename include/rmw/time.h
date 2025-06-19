#ifndef RMW__TIME_H_
#define RMW__TIME_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct rmw_time_s
{
  /// Seconds component
  uint64_t sec;

  /// Nanoseconds component
  uint64_t nsec;
} rmw_time_t;

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // RMW__TIME_H_