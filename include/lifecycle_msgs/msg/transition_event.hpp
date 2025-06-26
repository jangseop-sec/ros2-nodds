#ifndef LIFECYCLE_MSGS__MSG__TRANSITION_EVENT_HPP_
#define LIFECYCLE_MSGS__MSG__TRANSITION_EVENT_HPP_

#include <memory>

#include "lifecycle_msgs/msg/state.hpp";
#include "lifecycle_msgs/msg/transition.hpp"

namespace lifecycle_msgs
{
namespace msg
{

template<typename ContainerAllocator>
struct TransitionEvent_
{
  uint64_t timestamp;  // Timestamp of the event
  Transition transition;  // The transition being described 
  State start_state;  // The state before the transition
  State goal_state;  // The state after the transition
};

using TransitionEvent = TransitionEvent_<std::allocator<void>>;

}

}


#endif  // LIFECYCLES_MSG__MSG__TRANSITION_EVENT_HPP_