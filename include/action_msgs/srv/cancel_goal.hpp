#ifndef ACTION_MSGS__SRV__CANCEL_GOAL_HPP_
#define ACTION_MSGS__SRV__CANCEL_GOAL_HPP_

#include <memory>
#include <vector>

namespace action_msgs
{

namespace srv
{

using namespace action_msgs::msg;

template<class ContainerAllocator>
struct CancelGoal_
{
  int8_t ERROR_NONE=0;
  int8_t ERROR_REJECTED=1;
  int8_t ERROR_UNKNOWN_GOAL_ID=2;
  int8_t ERROR_GOAL_TERMINATED=3;

  int8_t return_code;
  std::vector<GoalInfo> goals_canceling;
};

using CancelGoal = CancelGoal_<std::allocator<void>>;

}

}

#endif // ACTION_MSGS__SRV__CANCEL_GOAL_HPP_
