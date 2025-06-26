#ifndef RMW__TIME_H_
#define RMW__TIME_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

#include "rcutils/time.h"

#define RMW_DURATION_INFINITE {9223372036LL, 854775807LL}
#define RMW_DURATION_UNSPECIFIED {0LL, 0LL}

typedef rcutils_time_point_value_t rmw_time_point_value_t;
typedef rcutils_duration_value_t rmw_duration_t;

typedef struct rmw_time_s
{
  /// Seconds component
  uint64_t sec;

  /// Nanoseconds component
  uint64_t nsec;
} rmw_time_t;

bool
rmw_time_equal(const rmw_time_t left, const rmw_time_t right);

rmw_time_t
rmw_time_from_nsec(const rmw_duration_t nanoseconds);

rmw_duration_t
rmw_time_total_nsec(const rmw_time_t time);

rmw_time_t
rmw_time_normalize(const rmw_time_t time);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // RMW__TIME_H_