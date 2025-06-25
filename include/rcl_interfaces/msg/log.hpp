#ifndef RCL_INTERFACES__MSG__LOG_HPP_
#define RCL_INTERFACES__MSG__LOG_HPP_

#include <string>
#include <vector>
#include <cstdint>

#define RCL_LOG_DEBUG 10
#define RCL_LOG_INFO 20
#define RCL_LOG_WARN 30
#define RCL_LOG_ERROR 40
#define RCL_LOG_FATAL 50

namespace rcl_interfaces
{
namespace msg
{

template<typename ContainerAllocator>
struct Log_
{

  uint8_t level;
  std::string name;
  std::string msg;
  std::string file;
  std::string function;
  uint32_t line;
};

using Log = Log_<std::allocator<void>>;

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__LOG_HPP_