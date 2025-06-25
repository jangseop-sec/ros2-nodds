#ifndef RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_HPP_
#define RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_HPP_

#include <memory>
#include <vector>

#include "rcl_interfaces/msg/parameter.hpp"
#include "rcl_interfaces/msg/set_parameter_result.hpp"

namespace rcl_interfaces
{

namespace srv
{

using namespace rcl_interfaces::msg;

template<typename ContainerAllocator>
struct SetParametersAtomically_
{
  std::vector<Parameter> parameters;  // Array of parameters to set
  SetParameterResult result;  // Result of the atomic set operation
};

using SetParametersAtomically = SetParametersAtomically_<std::allocator<void>>;

}

}

#endif  // RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY_HPP_