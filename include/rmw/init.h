#ifndef RMW__INIT_H_
#define RMW__INIT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stddef.h>

#include "rmw/init_options.h"
#include "rmw/macros.h"
#include "rmw/ret_types.h"

// FIXME 'rmw_context_impl_s'가 구현 안되어 있어도 문제 없나? -> 실제로는 DDS layer에서 구현
typedef struct rmw_context_impl_s rmw_context_impl_t;

typedef struct rmw_context_s
{
  /// Locally (process local) unique ID that represents this init/shutdown cycle.
  uint64_t instance_id;
  /// Implementation identifier, used to ensure two different implementations are not being mixed.
  const char * implementation_identifier;
  /// Options used to initialize the context.
  rmw_init_options_t options;
  /// Domain id that is being used.
  size_t actual_domain_id;
  /// Implementation defined context information.
  /** May be NULL if there is no implementation defined context information. */
  rmw_context_impl_t * impl;
} rmw_context_t;

rmw_context_t
rmw_get_zero_initialized_context(void);

#ifdef __cplusplus
}
#endif

#endif  // RMW__INIT_H_