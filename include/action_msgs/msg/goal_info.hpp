#ifndef ACTION_MSGS__MSG__GOAL_INFO_HPP_
#define ACTION_MSGS__MSG__GOAL_INFO_HPP_

#include <memory>

#include "unique_identifier_msgs/msg/UUID.hpp"
#include "builtin_interfaces/msg/time.hpp"

namespace action_msgs 
{

namespace msg
{

using namespace unique_identifier_msgs::msg;
using namespace builtin_interfaces::msg;

template<class ContainerAllocator>
struct GoalInfo_
{
  UUID goal_id;
  Time stamp;
};

using GoalInfo = GoalInfo_<std::allocator<void>>;

}

}

#endif // ACTION_MSGS__MSG__GOAL_INFO_HPP_
