#ifndef RMW_VALIDATE_NAMESPACE_H_
#define RMW_VALIDATE_NAMESPACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/macros.h"
#include "rmw/types.h"
#include "rmw/validate_full_topic_name.h"

#define RMW_NAMESPACE_VALID 0
#define RMW_NAMESPACE_INVALID_IS_EMPTY_STRING 1
#define RMW_NAMESPACE_INVALID_NOT_ABSOLUTE 2
#define RMW_NAMESPACE_INVALID_ENDS_WITH_FORWARD_SLASH 3
#define RMW_NAMESPACE_INVALID_CONTAINS_UNALLOWED_CHARACTERS 4
#define RMW_NAMESPACE_INVALID_CONTAINS_REPEATED_FORWARD_SLASH 5
#define RMW_NAMESPACE_INVALID_NAME_TOKEN_STARTS_WITH_NUMBER 6
#define RMW_NAMESPACE_INVALID_TOO_LONG 7

// An additional 2 characters are reserved for the shortest possible topic, e.g. '/X'.
#define RMW_NAMESPACE_MAX_LENGTH (RMW_TOPIC_MAX_NAME_LENGTH - 2U)

rmw_ret_t
rmw_validate_namespace(
  const char * namespace_,
  int * validation_result,
  size_t * invalid_index);

rmw_ret_t
rmw_validate_namespace_with_size(
  const char * namespace_,
  size_t namespace_length,
  int * validation_result,
  size_t * invalid_index);

const char *
rmw_namespace_validation_result_string(int validation_result);

#ifdef __cplusplus
}
#endif

#endif  // RMW_VALIDATE_NAMESPACE_H_