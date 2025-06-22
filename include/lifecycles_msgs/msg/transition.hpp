#ifndef LIFECYCLES_MSGS__MSG__TRANSITION_HPP_
#define LIFECYCLES_MSGS__MSG__TRANSITION_HPP_

#include <cstdint>
#include <string>

namespace lifecycles_msgs
{
namespace msg
{

// Transition constants
constexpr uint8_t TRANSITION_CREATE = 0;
constexpr uint8_t TRANSITION_CONFIGURE = 1;
constexpr uint8_t TRANSITION_CLEANUP = 2;
constexpr uint8_t TRANSITION_ACTIVATE = 3;
constexpr uint8_t TRANSITION_DEACTIVATE = 4;
constexpr uint8_t TRANSITION_UNCONFIGURED_SHUTDOWN = 5;
constexpr uint8_t TRANSITION_INACTIVE_SHUTDOWN = 6;
constexpr uint8_t TRANSITION_ACTIVE_SHUTDOWN = 7;
constexpr uint8_t TRANSITION_DESTROY = 8;

constexpr uint8_t TRANSITION_ON_CONFIGURE_SUCCESS = 10;
constexpr uint8_t TRANSITION_ON_CONFIGURE_FAILURE = 11;
constexpr uint8_t TRANSITION_ON_CONFIGURE_ERROR = 12;

constexpr uint8_t TRANSITION_ON_CLEANUP_SUCCESS = 20;
constexpr uint8_t TRANSITION_ON_CLEANUP_FAILURE = 21;
constexpr uint8_t TRANSITION_ON_CLEANUP_ERROR = 22;

constexpr uint8_t TRANSITION_ON_ACTIVATE_SUCCESS = 30;
constexpr uint8_t TRANSITION_ON_ACTIVATE_FAILURE = 31;
constexpr uint8_t TRANSITION_ON_ACTIVATE_ERROR = 32;

constexpr uint8_t TRANSITION_ON_DEACTIVATE_SUCCESS = 40;
constexpr uint8_t TRANSITION_ON_DEACTIVATE_FAILURE = 41;
constexpr uint8_t TRANSITION_ON_DEACTIVATE_ERROR = 42;

constexpr uint8_t TRANSITION_ON_SHUTDOWN_SUCCESS = 50;
constexpr uint8_t TRANSITION_ON_SHUTDOWN_FAILURE = 51;
constexpr uint8_t TRANSITION_ON_SHUTDOWN_ERROR = 52;

constexpr uint8_t TRANSITION_ON_ERROR_SUCCESS = 60;
constexpr uint8_t TRANSITION_ON_ERROR_FAILURE = 61;
constexpr uint8_t TRANSITION_ON_ERROR_ERROR = 62;

constexpr uint8_t TRANSITION_CALLBACK_SUCCESS = 97;
constexpr uint8_t TRANSITION_CALLBACK_FAILURE = 98;
constexpr uint8_t TRANSITION_CALLBACK_ERROR = 99;

template<typename ContainerAllocator>
struct Transition_
{
  uint8_t id;
  std::string label;
};

using Transition = Transition_<std::allocator<void>>;

}  // namespace msg
}  // namespace lifecycles_msgs

#endif  // LIFECYCLES_MSGS__MSG__TRANSITION_HPP_