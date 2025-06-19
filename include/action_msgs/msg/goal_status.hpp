#ifndef ACTION_MSGS__MSG__GOAL_STATUS_HPP_
#define ACTION_MSGS__MSG__GOAL_STATUS_HPP_

#include <memory>

#include "action_msgs/msg/goal_info.hpp";

namespace action_msgs
{

namespace msg 
{

template <class ContainerAllocator>
struct GoalStatus_
{
  int8_t STATUS_UNKNOWN     = 0;
  int8_t STATUS_ACCEPTED    = 1;
  int8_t STATUS_EXECUTING   = 2;
  int8_t STATUS_CANCELING   = 3;
  int8_t STATUS_SUCCEEDED   = 4;
  int8_t STATUS_CANCELED    = 5;
  int8_t STATUS_ABORTED     = 6;

  GoalInfo goal_info;
  int8_t status;

};

using GoalStatus = GoalStatus_<std::allocator<void>>;

}

}

#endif // ACTION_MSGS__MSG__GOAL_STATUS_HPP_