#ifndef BUILTIN_INTERFACES__MSG__DURATION_HPP_
#define BUILTIN_INTERFACES__MSG__DURATION_HPP_

#include <memory>

namespace builtin_interfaces
{

namespace msg
{


template<class ContainerAllocator>
struct Duration_
{
  int32_t sec;
  uint32_t nanosec;
};  

using Duration = Duration_<std::allocator<void>>;

}

}

#endif // BUILTIN_INTERFACES__MSG__DURATION_HPP_