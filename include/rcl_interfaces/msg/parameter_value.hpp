#ifndef RCL_INTERFACES__MSG__PARAMETER_VALUE_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_VALUE_HPP_

namespace rcl_interfaces
{

namespace msg
{

#include <vector>
#include <string>

template<typename ContainerAllocator>
struct ParameterValue_
{
  bool bool_value;
  int64_t integer_value;
  double double_value;
  std::string string_value;
  std::vector<uint8_t> byte_array_value;
  std::vector<bool> bool_array_value;
  std::vector<int64_t> integer_array_value;
  std::vector<double> double_array_value;
  std::vector<std::string> string_array_value;
};

using ParameterValue = ParameterValue_<std::allocator<void>>;

}

}

#endif  // RCL_INTERFACES__MSG__PARAMETER_VALUE_HPP_