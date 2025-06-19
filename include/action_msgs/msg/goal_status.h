#ifndef ACTION_MSGS__MSG__GOAL_STATUS_H_
#define ACTION_MSGS__MSG__GOAL_STATUS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "action_msgs/msg/goal_info.h"

typedef action_msgs__msg__GoalInfo GoalInfo;

typedef struct GaolStatus {

  // how to set default value of .msg/.srv file?? to use custom idl?
  // int8_t STATUS_UNKNOWN     = 0;
  // int8_t STATUS_ACCEPTED    = 1;
  // int8_t STATUS_EXECUTING   = 2;
  // int8_t STATUS_CANCELING   = 3;
  // int8_t STATUS_SUCCEEDED   = 4;
  // int8_t STATUS_CANCELED    = 5;
  // int8_t STATUS_ABORTED     = 6;

  GoalInfo goal_info;
  int8_t status;

} action_msgs__msg__GoalStatus;


#ifdef __cplusplus
}
#endif

#endif  // ACTION_MSGS__MSG__GOAL_STATUS_H_
