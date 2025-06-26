#ifndef ACTION_MSGS__SRV__CANCEL_GOAL_H_
#define ACTION_MSGS__SRV__CANCEL_GOAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "action_msgs/msg/goal_info.h"

typedef action_msgs__msg__GoalInfo GoalInfo;

const int8_t action_msgs__srv__CancelGoal_Response__ERROR_NONE=0;
const int8_t action_msgs__srv__CancelGoal_Response__ERROR_REJECTED=1;
const int8_t action_msgs__srv__CancelGoal_Response__ERROR_UNKNOWN_GOAL_ID=2;
const int8_t action_msgs__srv__CancelGoal_Response__ERROR_GOAL_TERMINATED=3;

typedef struct CancelGoal_Request {
  GoalInfo goal_info;  // The goal to cancel
} action_msgs__srv__CancelGoal_Request;

struct GoalInfoList {
  GoalInfo* data;  // Pointer to an array of GoalInfo
  size_t size;     // Number of elements in the array
};

typedef struct CancelGoal_Response {
  int8_t return_code;
  struct GoalInfoList goals_canceling;  // FIXME how flexible-size array declared? 
} action_msgs__srv__CancelGoal_Response;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_MSGS__SRV__CANCEL_GOAL_H_