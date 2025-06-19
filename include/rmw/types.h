#ifndef RMW__TYPES_H_
#define RMW__TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <stdbool.h>

#include <rmw/time.h>
#define RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_NODE_DEPRECATED_MSG \
  "RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_NODE is deprecated. " \
  "Use RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_TOPIC if manually asserted liveliness is needed."

#ifndef _WIN32
# define RMW_DECLARE_DEPRECATED(name, msg) name __attribute__((deprecated(msg)))
#else
# define RMW_DECLARE_DEPRECATED(name, msg) name __pragma(deprecated(name))
#endif

typedef enum rmw_qos_durability_policy_e
{
  /// Impplementation specific default
  RMW_QOS_POLICY_DURABILITY_SYSTEM_DEFAULT,

  /// The rmw publisher is responsible for persisting samples for “late-joining” subscribers
  RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL,

  /// Samples are not persistent
  RMW_QOS_POLICY_DURABILITY_VOLATILE,

  /// Durability policy has not yet been set
  RMW_QOS_POLICY_DURABILITY_UNKNOWN
} rmw_qos_durability_policy_t;

typedef enum rmw_qos_reliability_policy_e
{
  /// Implementation specific default
  RMW_QOS_POLICY_RELIABILITY_SYSTEM_DEFAULT,

  /// Guarantee that samples are delivered, may retry multiple times.
  RMW_QOS_POLICY_RELIABILITY_RELIABLE,

  /// Attempt to deliver samples, but some may be lost if the network is not robust
  RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT,

  /// Reliability policy has not yet been set
  RMW_QOS_POLICY_RELIABILITY_UNKNOWN
} rmw_qos_reliability_policy_t;

typedef enum rmw_qos_history_policy_e
{
  /// Implementation default for history policy
  RMW_QOS_POLICY_HISTORY_SYSTEM_DEFAULT,

  /// Only store up to a maximum number of samples, dropping oldest once max is exceeded
  RMW_QOS_POLICY_HISTORY_KEEP_LAST,

  /// Store all samples, subject to resource limits
  RMW_QOS_POLICY_HISTORY_KEEP_ALL,

  /// History policy has not yet been set
  RMW_QOS_POLICY_HISTORY_UNKNOWN
} rmw_qos_history_policy_t;

typedef enum rmw_qos_liveliness_policy_e
{
  /// Implementation specific default
  RMW_QOS_POLICY_LIVELINESS_SYSTEM_DEFAULT = 0,

  /// The signal that establishes a Topic is alive comes from the ROS rmw layer.
  RMW_QOS_POLICY_LIVELINESS_AUTOMATIC = 1,

  /// Explicitly asserting node liveliness is required in this case.
  /// This option is deprecated, use RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_TOPIC if your application
  /// requires to assert liveliness manually.
  RMW_DECLARE_DEPRECATED(
    RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_NODE,
    RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_NODE_DEPRECATED_MSG) = 2,

  /// The signal that establishes a Topic is alive is at the Topic level. Only publishing a message
  /// on the Topic or an explicit signal from the application to assert liveliness on the Topic
  /// will mark the Topic as being alive.
  // Using `3` for backwards compatibility.
  RMW_QOS_POLICY_LIVELINESS_MANUAL_BY_TOPIC = 3,

  /// Liveliness policy has not yet been set
  RMW_QOS_POLICY_LIVELINESS_UNKNOWN = 4
} rmw_qos_liveliness_policy_t;

/// ROS MiddleWare quality of service profile.
typedef struct rmw_qos_profile_s
{
  enum rmw_qos_history_policy_e history;
  /// Size of the message queue.
  size_t depth;
  /// Reliabiilty QoS policy setting
  enum rmw_qos_reliability_policy_e reliability;
  /// Durability QoS policy setting
  enum rmw_qos_durability_policy_e durability;
  /// The period at which messages are expected to be sent/received
  /**
    * RMW_DURATION_UNSPEFICIED will use the RMW implementation's default value,
    *   which may or may not be infinite.
    * RMW_DURATION_INFINITE explicitly states that messages never miss a deadline expectation.
    */
  struct rmw_time_s deadline;
  /// The age at which messages are considered expired and no longer valid
  /**
    * RMW_DURATION_UNSPEFICIED will use the RMW implementation's default value,
    *   which may or may not be infinite.
    * RMW_DURATION_INFINITE explicitly states that messages do not expire.
    */
  struct rmw_time_s lifespan;
  /// Liveliness QoS policy setting
  enum rmw_qos_liveliness_policy_e liveliness;
  /// The time within which the RMW node or publisher must show that it is alive
  /**
    * RMW_DURATION_UNSPEFICIED will use the RMW implementation's default value,
    *   which may or may not be infinite.
    * RMW_DURATION_INFINITE explicitly states that liveliness is not enforced.
    */
  struct rmw_time_s liveliness_lease_duration;

  /// If true, any ROS specific namespacing conventions will be circumvented.
  /**
   * In the case of DDS and topics, for example, this means the typical
   * ROS specific prefix of `rt` would not be applied as described here:
   *
   *   http://design.ros2.org/articles/topic_and_service_names.html#ros-specific-namespace-prefix
   *
   * This might be useful when trying to directly connect a native DDS topic
   * with a ROS 2 topic.
   */
  bool avoid_ros_namespace_conventions;
} rmw_qos_profile_t;

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // RMW__TYPES_H_
