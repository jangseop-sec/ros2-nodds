#ifndef RMW__QOS_STRING_CONVERSIONS_H_
#define RMW__QOS_STRING_CONVERSIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/types.h"
#include "rmw/qos_policy_kind.h"

const char *
rmw_qos_policy_kind_to_str(rmw_qos_policy_kind_t kind);

const char *
rmw_qos_durability_policy_to_str(enum rmw_qos_durability_policy_e value);

const char *
rmw_qos_history_policy_to_str(enum rmw_qos_history_policy_e value);

const char *
rmw_qos_liveliness_policy_to_str(enum rmw_qos_liveliness_policy_e value);

const char *
rmw_qos_reliability_policy_to_str(enum rmw_qos_reliability_policy_e value);

rmw_qos_policy_kind_t
rmw_qos_policy_kind_from_str(const char * str);

enum rmw_qos_durability_policy_e
rmw_qos_durability_policy_from_str(const char * str);

enum rmw_qos_history_policy_e
rmw_qos_history_policy_from_str(const char * str);

enum rmw_qos_liveliness_policy_e
rmw_qos_liveliness_policy_from_str(const char * str);

enum rmw_qos_reliability_policy_e
rmw_qos_reliability_policy_from_str(const char * str);

#ifdef __cplusplus
}
#endif

#endif  // RMW__QOS_STRING_CONVERSIONS_H_