#ifndef RCL_INTERFACES__SRV__LIST_PARAMETERS_HPP_
#define RCL_INTERFACES__SRV__LIST_PARAMETERS_HPP_

#include <memory>
#include <vector>

#include "rcl_interfaces/msg/list_parameter_result.hpp"

#define DEPTH_RECURSIVE 0

namespace rcl_interfaces
{

namespace srv
{

template<typename ContainerAllocator>
struct ListParameters_
{
  std::vector<std::string> prefixes;
  uint64_t depth;

  ListParameterResult result;
};

using ListParameters = ListParameters_<std::allocator<void>>;

}

#endif  // RCL_INTERFACES__SRV__LIST_PARAMETERS_HPP_