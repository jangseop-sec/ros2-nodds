#ifndef ROSIDL_RUNTIME_C__SERVICE_TYPE_SUPPORT_STRUCT_H_
#define ROSIDL_RUNTIME_C__SERVICE_TYPE_SUPPORT_STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

struct rosidl_service_type_support_t
{
  /// String identifier for the type_support.
  const char * typesupport_identifier;
  /// Pointer to the service type support library
  const void * data;
  /// Pointer to the service type support handler function
} rosidl_service_type_support_t;

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_RUNTIME_C__SERVICE_TYPE_SUPPORT_STRUCT_H_