#ifndef LIFECYCLE_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_
#define LIFECYCLE_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_

// Add your includes and code here
#include "lifecycle_msgs/msg/transition.hpp"
#include "lifecycle_msgs/msg/state.hpp"

namespace lifecycle_msgs
{
namespace msg
{

template<typename ContainerAllocator>
struct TransitionDescription_
{
  Transition transition;
  State start_state;
  State goal_state;
};

using TransitionDescription = TransitionDescription_<std::allocator<void>>;

}

}  // namespace lifecycles_msgs

#endif  // LIFECYCLE_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_