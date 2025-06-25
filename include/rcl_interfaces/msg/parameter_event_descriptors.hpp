#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_HPP_

#include <vector>
#include <memory>

#include "rcl_interfaces/msg/parameter_descriptor.hpp"


namespace rcl_interfaces
{
namespace msg
{

template<typename ContainerAllocator>
struct ParameterEventDescriptors_
{
  std::vector<ParameterDescriptor> new_parameters;
  std::vector<ParameterDescriptor> changed_parameters;
  std::vector<ParameterDescriptor> deleted_parameters;
};

using ParameterEventDescriptors = ParameterEventDescriptors_<std::allocator<void>>;

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS_HPP_