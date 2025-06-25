#ifndef ROSIDL_RUNTIME_C__MESSAGE_TYPE_SUPPORT_STRUCT_H_
#define ROSIDL_RUNTIME_C__MESSAGE_TYPE_SUPPORT_STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct rosidl_message_type_support_t
{
  /// String identifier for the type_support.
  const char * typesupport_identifier;
  /// Pointer to the message type support library
  const void * data;
  /// Pointer to the message type support handler function
  // rosidl_message_typesupport_handle_function func;
} rosidl_message_type_support_t;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__MESSAGE_TYPE_SUPPORT_STRUCT_H_