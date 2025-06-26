#ifndef LIFECYCLE_MSGS__MSG__TRANSITION_H_
#define LIFECYCLE_MSGS__MSG__TRANSITION_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CREATE = 0;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CONFIGURE = 1;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CLEANUP = 2;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ACTIVATE = 3;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_DEACTIVATE = 4;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_UNCONFIGURED_SHUTDOWN = 5;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_INACTIVE_SHUTDOWN = 6;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ACTIVE_SHUTDOWN = 7;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_DESTROY = 8;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CONFIGURE_SUCCESS = 10;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CONFIGURE_FAILURE = 11;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CONFIGURE_ERROR = 12;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CLEANUP_SUCCESS = 20;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CLEANUP_FAILURE = 21;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_CLEANUP_ERROR = 22;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ACTIVATE_SUCCESS = 30;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ACTIVATE_FAILURE = 31;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ACTIVATE_ERROR = 32;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_DEACTIVATE_SUCCESS = 40;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_DEACTIVATE_FAILURE = 41;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_DEACTIVATE_ERROR = 42;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_SHUTDOWN_SUCCESS = 50;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_SHUTDOWN_FAILURE = 51;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_SHUTDOWN_ERROR = 52;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ERROR_SUCCESS = 60;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ERROR_FAILURE = 61;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_ON_ERROR_ERROR = 62;

uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CALLBACK_SUCCESS = 97;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CALLBACK_FAILURE = 98;
uint8_t lifecycle_msgs__msg__Transition__TRANSITION_CALLBACK_ERROR = 99;

typedef struct Transition
{
  uint8_t id;
  char label[32];  // Size determined by the maximum length of the label
} lifecycle_msgs__msg__Transition;

#ifdef __cplusplus
} // extern "C" 
#endif

#endif  // LIFECYCLES_MSG__MSG__TRANSITION_H_