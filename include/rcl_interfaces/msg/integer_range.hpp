#ifndef RCL_INTERFACES__MSG__INTEGER_RANGE_HPP_
#define RCL_INTERFACES__MSG__INTEGER_RANGE_HPP_

#include <cstdint>
#include <ostream>

namespace rcl_interfaces
{
namespace msg
{

template<typename ContainerAllocator>
struct IntegerRange_
{
  int64_t from_value;
  int64_t to_value;
  uint64_t step;
};

using IntegerRange = IntegerRange_<std::allocator<void>>;

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__INTEGER_RANGE_HPP_