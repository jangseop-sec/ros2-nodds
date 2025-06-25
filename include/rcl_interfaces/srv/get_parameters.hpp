#ifndef RCL_INTERFACES__SRV__GET_PARAMETERS_HPP_
#define RCL_INTERFACES__SRV__GET_PARAMETERS_HPP_

#include <memory>
#include <vector>

#include "rcl_interfaces/msg/parameter_value.hpp"

namespace rcl_interfaces
{

namespace srv
{

using namespace rcl_interfaces::msg;

template<typename ContainerAllocator>
struct GetParameters_
{
  std::vector<std::string> names;
  std::vector<ParameterValue> values;
};

using GetParameters = GetParameters_<std::allocator<void>>;

}

}
#endif  // RCL_INTERFACES__SRV__GET_PARAMETERS_HPP_