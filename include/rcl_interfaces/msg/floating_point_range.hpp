#ifndef RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_HPP_
#define RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_HPP_

#include <cstdint>
#include <string>

namespace rcl_interfaces
{
namespace msg
{

template<typename ContainerAllocator>
struct FloatingPointRange_
{
  double from_value;
  double to_value;
  double step;
};

using FloatingPointRange = FloatingPointRange_<std::allocator<void>>;

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__FLOATING_POINT_RANGE_HPP_