#ifndef RMW__SECURITY_OPTIONS_H
#define RMW__SECURITY_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rcutils/allocator.h"

#include "rmw/ret_types.h"

typedef enum rmw_security_enforcement_policy_e
{
  RMW_SECURITY_ENFORCEMENT_PERMISSIVE,
  RMW_SECURITY_ENFORCEMENT_ENFORCE,
} rmw_security_enforcement_policy_t;

typedef struct rmw_security_options_s
{
  rmw_security_enforcement_policy_t enforce_security;
  char * security_root_path;
} rmw_security_options_t;

rmw_security_options_t
rmw_get_zero_initialized_security_options();

rmw_security_options_t
rmw_get_default_security_options();

rmw_ret_t
rmw_security_options_copy(
  const rmw_security_options_t * src,
  const rcutils_allocator_t * allocator,
  rmw_security_options_t * dst);

rmw_ret_t
rmw_security_options_set_root_path(
  const char * security_root_path,
  const rcutils_allocator_t * allocator,
  rmw_security_options_t * security_options);

rmw_ret_t
rmw_security_options_fini(
  rmw_security_options_t * security_options,
  const rcutils_allocator_t * allocator);


#ifdef __cplusplus
}
#endif

#endif // RMW__SECURITY_OPTIONS_H