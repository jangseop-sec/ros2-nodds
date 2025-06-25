#ifndef RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_HPP_
#define RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_HPP_

namespace rcl_interfaces
{
namespace msg
{

#include <string>
#include <vector>

template<typename ContainerAllocator>
struct ListParameterResult_
{
  std::vector<std::string> names;
  std::vector<std::string> prefixes;  
};

using ListParameterResult = ListParameterResult_<std::allocator<void>>;

}

}

#endif  // RCL_INTERFACES__MSG__LIST_PARAMETER_RESULT_HPP_