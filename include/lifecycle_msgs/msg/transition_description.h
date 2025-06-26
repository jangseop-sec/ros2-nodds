#ifndef LIFECYCLES_MSG__MSG__TRANSITION_DESCRIPTION_H_
#define LIFECYCLES_MSG__MSG__TRANSITION_DESCRIPTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "lifecycle_msgs/msg/state.h"
#include "lifecycle_msgs/msg/transition.h"

typedef lifecycles_msgs__msg__State State;
typedef lifecycles_msgs__msg__Transition Transition;

typedef struct TransitionDescription
{
  Transition transition;  // The transition being described
  State start_state;       // The state before the transition
  State goal_state;        // The state after the transition
} lifecycles_msg__msg__TransitionDescription;

#ifdef __cplusplus
}
#endif

#endif  // LIFECYCLES_MSGS__MSG__TRANSITION_DESCRIPTION_H_