#ifndef ACTION_MSGS__SRV__CANCEL_GOAL_H_
#define ACTION_MSGS__SRV__CANCEL_GOAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#define ERROR_NONE 0
#define ERROR_REJECTED 1
#define ERROR_UNKNOWN_GOAL_ID 2
#define ERROR_GOAL_TERMINATED 3

#include "action_msgs/msg/goal_info.h"

typedef action_msgs__msg__GoalInfo GoalInfo;

typedef struct CancelGoal_Request {
  GoalInfo goal_info;  // The goal to cancel
} action_msgs__srv__CancelGoal_Request;

typedef struct CancelGoal_Response {
  int8_t return_code;
  GoalInfo* goals_canceling;  // FIXME how flexible-size array declared? 
} action_msgs__srv__CancelGoal_Response;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_MSGS__SRV__CANCEL_GOAL_H_