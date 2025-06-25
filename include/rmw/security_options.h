#ifndef RMW__SECURITY_OPTIONS_H
#define RMW__SECURITY_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif // RMW__SECURITY_OPTIONS_H