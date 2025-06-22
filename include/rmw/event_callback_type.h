#ifndef RMW__EVENT_CALLBACK_TYPE_H_
#define RMW__EVENT_CALLBACK_TYPE_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (* rmw_event_callback_t)(const void * user_data, size_t number_of_events);

#ifdef __cplusplus
}
#endif

#endif // RMW__EVENT_CALLBACK_TYPE_H_