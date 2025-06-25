#ifndef ROSIDL_RUNTIME_C__ACTION_TYPE_SUPPORT_STRUCT_H_
#define ROSIDL_RUNTIME_C__ACTION_TYPE_SUPPORT_STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

typedef struct rosidl_action_type_support_t
{
  const char * typesupport_identifier;
  const void * data;
} rosidl_action_type_support_t;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__ACTION_TYPE_SUPPORT_STRUCT_H_