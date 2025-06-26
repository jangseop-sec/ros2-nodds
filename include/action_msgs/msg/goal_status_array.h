#ifndef ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_
#define ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

#include <action_msgs/msg/goal_status.h>

typedef action_msgs__msg__GoalStatus GoalStatus;

struct GoalStatusList {
  GoalStatus * data;
  size_t size;
};
typedef struct GoalStatusArray {
  struct GoalStatusList status_list;  // Array of goal statuses
} action_msgs__msg__GoalStatusArray;

#ifdef __cplusplus
}
#endif

#endif // ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_H_
