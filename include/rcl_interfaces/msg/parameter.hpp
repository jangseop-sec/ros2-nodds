#ifndef RCL_INTERFACES__MSG__PARAMETER_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_HPP_

// Example parameter structure
namespace rcl_interfaces
{
namespace msg
{

#include "rcl_interfaces/msg/parameter_value.hpp"

template<typename ContainerAllocator>
struct Parameter_
{
  std::string name;
  ParameterValue value;
};

using Parameter = Parameter_<std::allocator<void>>;

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__PARAMETER_HPP_