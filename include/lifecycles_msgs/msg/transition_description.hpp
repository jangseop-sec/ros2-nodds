#ifndef LIFECYCLES_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_
#define LIFECYCLES_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_

// Add your includes and code here
#include "lifecycles_msgs/msg/transition.hpp"
#include "lifecycles_msgs/msg/state.hpp"

namespace lifecycles_msgs
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

#endif  // LIFECYCLES_MSGS__MSG__TRANSITION_DESCRIPTION_HPP_