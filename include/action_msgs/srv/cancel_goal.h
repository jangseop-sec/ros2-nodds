#ifndef ACTION_MSGS__SRV__CANCEL_GOAL_H_
#define ACTION_MSGS__SRV__CANCEL_GOAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "action_msgs/msg/goal_info.h"

typedef action_msgs__msg__GoalInfo GoalInfo;

typedef struct CancelGoal {
  // TODO set default value of 'CancelGoal' service
  // int8_t ERROR_NONE=0;
  // int8_t ERROR_REJECTED=1;
  // int8_t ERROR_UNKNOWN_GOAL_ID=2;
  // int8_t ERROR_GOAL_TERMINATED=3;

  int8_t return_code;
  GoalInfo* goals_canceling;  // FIXME how flexible-size array declared? 
} action_msgs__srv__CancelGoal;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_MSGS__SRV__CANCEL_GOAL_H_