#ifndef RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_HPP_
#define RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_HPP_

#include <cstdint>
#include <string>

namespace rcl_interfaces
{
namespace msg
{

struct SetParameterResult
{
  bool successful;
  std::string reason;
};

}  // namespace msg
}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__SET_PARAMETER_RESULT_HPP_