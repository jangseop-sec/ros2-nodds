#ifndef RMW__QOS_POLICY_KIND_H
#define RMW__QOS_POLICY_KIND_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum rmw_qos_policy_kind_e
{
  RMW_QOS_POLICY_INVALID = 1 << 0,
  RMW_QOS_POLICY_DURABILITY = 1 << 1,
  RMW_QOS_POLICY_DEADLINE = 1 << 2,
  RMW_QOS_POLICY_LIVELINESS = 1 << 3,
  RMW_QOS_POLICY_RELIABILITY = 1 << 4,
  RMW_QOS_POLICY_HISTORY = 1 << 5,
  RMW_QOS_POLICY_LIFESPAN = 1 << 6,
  RMW_QOS_POLICY_DEPTH = 1 << 7,
  RMW_QOS_POLICY_LIVELINESS_LEASE_DURATION = 1 << 8,
  RMW_QOS_POLICY_AVOID_ROS_NAMESPACE_CONVENTIONS = 1 << 9,
} rmw_qos_policy_kind_t;

#ifdef __cplusplus
}
#endif

#endif // RMW__QOS_POLICY_KIND_H