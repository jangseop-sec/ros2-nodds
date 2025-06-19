#ifndef BUILTIN_INTEFACES__MSG__TIME_HPP_
#define BUILTIN_INTEFACES__MSG__TIME_HPP_

#include <memory>

namespace builtin_interfaces
{

namespace msg
{

template<class ContainerAllocator>
struct Time_
{
  int32_t sec;
  uint32_t nanosec;
};

using Time = Time_<std::allocator<void>>;

}

}

#endif // BUILTIN_INTEFACES__MSG__TIME_HPP_