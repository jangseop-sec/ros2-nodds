#ifndef RMW__VALIDATE_NODE_NAME_H_
#define RMW__VALIDATE_NODE_NAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/macros.h"
#include "rmw/types.h"

#define RMW_NODE_NAME_VALID 0
#define RMW_NODE_NAME_INVALID_IS_EMPTY_STRING 1
#define RMW_NODE_NAME_INVALID_CONTAINS_UNALLOWED_CHARACTERS 2
#define RMW_NODE_NAME_INVALID_STARTS_WITH_NUMBER 3
#define RMW_NODE_NAME_INVALID_TOO_LONG 4

#define RMW_NODE_NAME_MAX_NAME_LENGTH 255 /* arbitrary constraint */

rmw_ret_t
rmw_validate_node_name(
  const char * node_name,
  int * validation_result,
  size_t * invalid_index);


rmw_ret_t
rmw_validate_node_name_with_size(
  const char * node_name,
  size_t node_name_length,
  int * validation_result,
  size_t * invalid_index);

const char *
rmw_node_name_validation_result_string(int validation_result);

#ifdef __cplusplus
}
#endif

#endif  // RMW__VALIDATE_NODE_NAME_H_