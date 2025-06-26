#ifndef RMW__CONVERT_RCUTILS_RET_TO_RMW_RET_H_
#define RMW__CONVERT_RCUTILS_RET_TO_RMW_RET_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rmw/types.h"
#include "rmw/ret_types.h"

rmw_ret_t
rmw_convert_rcutils_ret_to_rmw_ret(rcutils_ret_t rcutils_ret);

#ifdef __cplusplus
}
#endif

#endif  // RMW__CONVERT_RCUTILS_RET_TO_RMW_RET_H_