#ifndef LIFECYCLES_MSGS__MSG__STATE_H_
#define LIFECYCLES_MSGS__MSG__STATE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

// Message definition for lifecycles_msgs/msg/State
typedef struct State
{
  // TODO how define static constants for state IDs?
  uint8_t id;
  char label[32];   // how size is determined by the maximum length of the label?
} lifecycles_msgs__msg__State;

#ifdef __cplusplus
}
#endif

#endif  // LIFECYCLES_MSGS__MSG__STATE_H_