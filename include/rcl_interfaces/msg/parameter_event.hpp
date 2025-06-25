#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_HPP_

namespace rcl_interfaces
{

namespace msg
{

#include <vector>
#include <memory>

#include "builtin_interfaces/msg/time.hpp"
#include "rcl_interfaces/msg/parameter.hpp"

template<typename ContainerAllocator>
struct ParameterEvent_
{
  builtin_interfaces::msg::Time stamp;  // Timestamp of the event
  std::string node;  // Name of the node that generated the event
  std::vector<Parameter> new_parameters;  // Array of new parameters
  std::vector<Parameter> changed_parameters;  // Array of changed parameters
  std::vector<Parameter> deleted_parameters;  // Array of deleted parameters
};

using ParameterEvent = ParameterEvent_<std::allocator<void>>;

}

}

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_HPP_