#ifndef RMW__EVENT_H_
#define RMW__EVENT_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum rmw_event_type_e
{
  // subscription events
  RMW_EVENT_LIVELINESS_CHANGED,
  RMW_EVENT_REQUESTED_DEADLINE_MISSED,
  RMW_EVENT_REQUESTED_QOS_INCOMPATIBLE,
  RMW_EVENT_MESSAGE_LOST,

  // publisher events
  RMW_EVENT_LIVELINESS_LOST,
  RMW_EVENT_OFFERED_DEADLINE_MISSED,
  RMW_EVENT_OFFERED_QOS_INCOMPATIBLE,

  // sentinel value
  RMW_EVENT_INVALID
} rmw_event_type_t;

typedef struct rmw_event_s
{
  /// Implementation identifier, used to ensure two different implementations are not being mixed.
  const char * implementation_identifier;
  /// Data specific to this event type from either the publisher or subscriber.
  void * data;
  /// The event type that occurred.
  rmw_event_type_t event_type;
} rmw_event_t;

#ifdef __cplusplus
}
#endif

#endif  // RMW__EVENT_H_