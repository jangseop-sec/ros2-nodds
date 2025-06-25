#ifndef RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_HPP_
#define RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_HPP_

#include <memory>
#include <vector>

namespace rcl_interfaces
{

namespace srv
{

template<typename ContainerAllocator>
struct GetParameterTypes_
{
  std::vector<std::string> names;
  std::vector<uint8_t> types;
};

using GetParameterTypes = GetParameterTypes_<std::allocator<void>>;

}

}
#endif  // RCL_INTERFACES__SRV__GET_PARAMETER_TYPES_HPP_