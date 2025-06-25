#ifndef RCL_INTERFACES__MSG__PARMETER_DESCRIPTOR_HPP_
#define RCL_INTERFACES__MSG__PARMETER_DESCRIPTOR_HPP_

namespace rcl_interfaces
{

namespace msg
{

#include <memory>

#include "rcl_interfaces/msg/integer_range.hpp"
#include "rcl_interfaces/msg/floating_point_range.hpp"

template<typename ContainerAllocator>
struct ParameterDescriptor_
{
  char * name;  // Name of the parameter
  uint8_t type;  // Type of the parameter (e.g., "int", "double", "string")
  char * description;  // Description of the parameter
  char * additional_constraints;  // Additional constraints for the parameter
  bool read_only;  // Indicates if the parameter is read-only
  bool dynamic_typing;  // Indicates if the parameter supports dynamic typing
  IntegerRange * integer_range;  // Optional integer range for the parameter
  FloatingPointRange * floating_point_range;  // Optional floating point range for the parameter
};

using ParameterDescriptor = ParameterDescriptor_<std::allocator<void>>;

}  // namespace msg

}

#endif  // RCL_INTERFACES__MSG__PARMETER_DESCRIPTOR_HPP_