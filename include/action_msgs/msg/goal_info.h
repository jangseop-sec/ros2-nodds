#ifndef ACTION_MSGS__MSG__GOAL_INFO_H_
#define ACTION_MSGS__MSG__GOAL_INFO_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "unique_identifier_msgs/msg/UUID.h"
#include "builtin_interfaces/msg/time.h"

typedef unique_identifier_msgs__msg__UUID UUID;
typedef builtin_interfaces__msgs__Time Time;

typedef struct GoalInfo {
  UUID goal_id;
  Time stamp;
} action_msgs__msg__GoalInfo;


#ifdef __cplusplus
}
#endif

#endif  // ACTION_MSGS__MSG__GOAL_INFO_H_