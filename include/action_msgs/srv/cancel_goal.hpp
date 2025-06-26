#ifndef ACTION_MSGS__SRV__CANCEL_GOAL_HPP_
#define ACTION_MSGS__SRV__CANCEL_GOAL_HPP_

#include <memory>
#include <vector>

#include "action_msgs/msg/goal_info.hpp"

namespace action_msgs
{

namespace srv
{

using namespace action_msgs::msg;

template<class ContainerAllocator>
struct CancelGoal_Request_
{
  GoalInfo goal_info;  // The goal to cancel
};

template<class ContainerAllocator>
struct CancelGoal_Response_
{
  static constexpr int8_t ERROR_NONE=0;
  static constexpr int8_t ERROR_REJECTED=1;
  static constexpr int8_t ERROR_UNKNOWN_GOAL_ID=2;
  static constexpr int8_t ERROR_GOAL_TERMINATED=3;

  int8_t return_code;
  std::vector<GoalInfo> goals_canceling;
};

using CancelGoal_Response = CancelGoal_<std::allocator<void>>;

}

}

#endif // ACTION_MSGS__SRV__CANCEL_GOAL_HPP_
