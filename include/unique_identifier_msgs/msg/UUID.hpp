#ifndef __UNIQUE_IDENTIFIER_MSGS__MSG__UUID_HPP_
#define __UNIQUE_IDENTIFIER_MSGS__MSG__UUID_HPP_

#include <memory>

namespace unique_identifier_msgs 
{

namespace msg 
{

template<class ContainerAllocator>
struct UUID_ {
  uint8_t uuid[16];
};

using UUID = UUID_<std::allocator<void>>;

}

}

#endif // __UNIQUE_IDENTIFIER_MSGS__MSG__UUID_HPP_
