#ifndef RMW__INIT_OPTIONS_H_
#define RMW__INIT_OPTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#include "rcutils/allocator.h"

#include "rmw/allocator.h"
#include "rmw/localhost.h"
#include "rmw/security_options.h"

typedef struct rmw_init_options_impl_s rmw_init_options_impl_t;

/// Options structure used during rmw_init().
typedef struct rmw_init_options_s
{
  /// Locally (process local) unique ID that represents this init/shutdown cycle.
  /**
   * This should be set by the caller of `rmw_init()` to a number that is
   * unique within this process.
   * It is designed to be used with `rcl_init()` and `rcl_get_instance_id()`.
   */
  uint64_t instance_id;
  /// Implementation identifier, used to ensure two different implementations are not being mixed.
  const char * implementation_identifier;
  /// ROS domain id
  size_t domain_id;
  /// Security options
  rmw_security_options_t security_options;
  /// Enable localhost only
  rmw_localhost_only_t localhost_only;
  /// Enclave, name used to find security artifacts in a sros2 keystore.
  char * enclave;

  // TODO(wjwwood): replace with rmw_allocator_t when that refactor happens
  /// Allocator used during internal allocation of init options, if needed.
  rcutils_allocator_t allocator;
  /// Implementation defined init options.
  /** May be NULL if there are no implementation defined options. */
  rmw_init_options_impl_t * impl;
} rmw_init_options_t;

#ifdef __cplusplus
}
#endif

#endif  // RMW__INIT_OPTIONS_H_