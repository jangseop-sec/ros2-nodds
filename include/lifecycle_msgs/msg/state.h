#ifndef LIFECYCLE_MSGS__MSG__STATE_H_
#define LIFECYCLE_MSGS__MSG__STATE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

uint8_t lifecycle_msgs__msg__State__PRIMARY_STATE_UNKNOWN = 0;
uint8_t lifecycle_msgs__msg__State__PRIMARY_STATE_UNCONFIGURED = 1;
uint8_t lifecycle_msgs__msg__State__PRIMARY_STATE_INACTIVE = 2;
uint8_t lifecycle_msgs__msg__State__PRIMARY_STATE_ACTIVE = 3;
uint8_t lifecycle_msgs__msg__State__PRIMARY_STATE_FINALIZED = 4;

uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_CONFIGURING = 10;
uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_CLEANINGUP = 11;
uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_SHUTTINGDOWN = 12;
uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_ACTIVATING = 13;
uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_DEACTIVATING = 14;
uint8_t lifecycle_msgs__msg__State__TRANSITION_STATE_ERRORPROCESSING = 15;

// Message definition for lifecycles_msgs/msg/State
typedef struct State
{
  // TODO how define static constants for state IDs?
  uint8_t id;
  char label[32];   // how size is determined by the maximum length of the label?
} lifecycle_msgs__msg__State;

#ifdef __cplusplus
}
#endif

#endif  // LIFECYCLE_MSGS__MSG__STATE_H_