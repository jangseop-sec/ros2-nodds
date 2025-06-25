#ifndef RMW_LOCALHOST_H_
#define RMW_LOCALHOST_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum rmw_localhost_only_e
{
  /// Uses ROS_LOCALHOST_ONLY environment variable.
  RMW_LOCALHOST_ONLY_DEFAULT = 0,
  /// Forces using only localhost.
  RMW_LOCALHOST_ONLY_ENABLED = 1,
  /// Forces disabling localhost only.
  RMW_LOCALHOST_ONLY_DISABLED = 2,
} rmw_localhost_only_t;

#ifdef __cplusplus
}
#endif

#endif  // RMW_LOCALHOST_H_