#ifndef ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_
#define ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <action_msgs/msg/goal_status.h>

typedef action_msgs__msg__GoalStatus GoalStatus;

typedef struct GoalStatusArray {
  GoalStatus* status_list;    // TODO how to declare no-fixed-size array? (in C99, 'arr[]' is supported)
} action_msgs__msg__GoalStatusArray;

#ifdef __cplusplus
}
#endif

#endif // ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_
