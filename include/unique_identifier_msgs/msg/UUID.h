#ifndef UNIQUE_IDENTIFIER_MSGS__MSG__UUID_H_
#define UNIQUE_IDENTIFIER_MSGS__MSG__UUID_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct UUID {
  uint8_t uuid[16];
} unique_identifier_msgs__msg__UUID;

#ifdef __cplusplus
}
#endif

#endif  // UNIQUE_IDENTIFIER_MSGS__MSG__UUID_H_