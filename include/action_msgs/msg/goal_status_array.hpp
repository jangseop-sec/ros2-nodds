#ifndef ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_HPP_
#define ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_HPP_

#include <memory>
#include <vector>

#include "action_msgs/msg/goal_status.hpp"

namespace action_msgs
{

namespace msg
{

template<class ContainerAllocator>
struct GoalStatusArray_
{
  std::vector<GoalStatus> status_list;
};

using GoalStatusArray = GoalStatusArray_<std::allocator<void>>;

}

}


#endif // ACTION_MSGS__MSG__GOAL_STATUS_ARRAY_HPP_