#ifndef RMW__VALIDATE_FULL_TOPIC_NAME_H_
#define RMW__VALIDATE_FULL_TOPIC_NAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

#include "rmw/ret_types.h"
#include "rmw/macros.h"

#define RMW_TOPIC_VALID 0
#define RMW_TOPIC_INVALID_IS_EMPTY_STRING 1
#define RMW_TOPIC_INVALID_NOT_ABSOLUTE 2
#define RMW_TOPIC_INVALID_ENDS_WITH_FORWARD_SLASH 3
#define RMW_TOPIC_INVALID_CONTAINS_UNALLOWED_CHARACTERS 4
#define RMW_TOPIC_INVALID_CONTAINS_REPEATED_FORWARD_SLASH 5
#define RMW_TOPIC_INVALID_NAME_TOKEN_STARTS_WITH_NUMBER 6
#define RMW_TOPIC_INVALID_TOO_LONG 7

#define RMW_TOPIC_MAX_NAME_LENGTH 255U /* impl constraint */ - 8U /* reserved for prefixes */

rmw_ret_t
rmw_validate_full_topic_name(
  const char * topic_name,
  int * validation_result,
  size_t * invalid_index);

rmw_ret_t
rmw_validate_full_topic_name_with_size(
  const char * topic_name,
  size_t topic_name_length,
  int * validation_result,
  size_t * invalid_index);

const char *
rmw_full_topic_name_validation_result_string(int validation_result);



#ifdef __cplusplus
}
#endif

#endif  // RMW__VALIDATE_FULL_TOPIC_NAME_H_