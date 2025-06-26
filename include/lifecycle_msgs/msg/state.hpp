#ifndef LIFECYCLE_MSGS__MSG__STATE_HPP_
#define LIFECYCLE_MSGS__MSG__STATE_HPP_

#include <string>
#include <memory>

namespace lifecycle_msgs
{
namespace msg
{

// State ID constants


template<typename ContainerAllocator>
struct State_
{
  static constexpr uint8_t PRIMARY_STATE_UNKNOWN = 0;
  static constexpr uint8_t PRIMARY_STATE_UNCONFIGURED = 1;
  static constexpr uint8_t PRIMARY_STATE_INACTIVE = 2;
  static constexpr uint8_t PRIMARY_STATE_ACTIVE = 3;
  static constexpr uint8_t PRIMARY_STATE_FINALIZED = 4;

  static constexpr uint8_t TRANSITION_STATE_CONFIGURING = 10;
  static constexpr uint8_t TRANSITION_STATE_CLEANINGUP = 11;
  static constexpr uint8_t TRANSITION_STATE_SHUTTINGDOWN = 12;
  static constexpr uint8_t TRANSITION_STATE_ACTIVATING = 13;
  static constexpr uint8_t TRANSITION_STATE_DEACTIVATING = 14;
  static constexpr uint8_t TRANSITION_STATE_ERRORPROCESSING = 15;
  // State fields
  uint8_t id;
  std::string label;

};

using State = State_<std::allocator<void>>;

}  // namespace msg
}  // namespace lifecycles_msgs

#endif  // LIFECYCLE_MSGS__MSG__STATE_HPP_