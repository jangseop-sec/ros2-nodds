#ifndef RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS_HPP_
#define RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS_HPP_

#include <memory>
#include <vector>

#include "rcl_interfaces/msg/parameter_descriptor.hpp"

namespace rcl_interfaces
{

namespace srv
{

using namespace rcl_interfaces::msg;

template <typename ContainerAllocator>
struct DescribeParameters_
{
  std::vector<std::string> names;
  std::vector<ParameterDescriptor> descriptors;
};

using DescribeParameters = DescribeParameters_<std::allocator<void>>;

}

}

#endif  // RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS_HPP_