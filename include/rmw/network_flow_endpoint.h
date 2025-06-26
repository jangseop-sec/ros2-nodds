#ifndef RMW__NETWORK_FLOW_ENDPOINT_H_
#define RMW__NETWORK_FLOW_ENDPOINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rmw/types.h"

/// Transport protocol types
typedef enum rmw_transport_protocol_e
{
  RMW_TRANSPORT_PROTOCOL_UNKNOWN = 0,
  RMW_TRANSPORT_PROTOCOL_UDP,
  RMW_TRANSPORT_PROTOCOL_TCP,
  RMW_TRANSPORT_PROTOCOL_COUNT
} rmw_transport_protocol_t;

/// Internet protocol types
typedef enum rmw_internet_protocol_e
{
  RMW_INTERNET_PROTOCOL_UNKNOWN = 0,
  RMW_INTERNET_PROTOCOL_IPV4,
  RMW_INTERNET_PROTOCOL_IPV6,
  RMW_INTERNET_PROTOCOL_COUNT
} rmw_internet_protocol_t;

/// Maximum length of internet address string including terminating null
/// Inspired from linux/inet.h
#define RMW_INET_ADDRSTRLEN 48

/// Structure that describes network flow endpoint of a publisher or subscription
typedef struct rmw_network_flow_endpoint_s
{
  // Transport protocol
  rmw_transport_protocol_t transport_protocol;
  // Internet protocol
  rmw_internet_protocol_t internet_protocol;
  // Port
  uint16_t transport_port;
  // Flow label
  // TODO(anamud): Consider specializing since flow_label is set only at publisher
  // ... side.
  uint32_t flow_label;
  // DSCP (Diff. Services Code Point)
  // TODO(anamud): Consider specializing since DSCP is set only at publisher
  // ... side.
  uint8_t dscp;
  // Internet address
  char internet_address[RMW_INET_ADDRSTRLEN];
} rmw_network_flow_endpoint_t;

rmw_network_flow_endpoint_t
rmw_get_zero_initialized_network_flow_endpoint(void);

const char * rmw_network_flow_endpoint_get_transport_protocol_string(
  const rmw_transport_protocol_t transport_protocol);

const char * rmw_network_flow_endpoint_get_internet_protocol_string(
  const rmw_internet_protocol_t internet_protocol);

rmw_ret_t
rmw_network_flow_endpoint_set_internet_address(
  rmw_network_flow_endpoint_t * network_flow_endpoint,
  const char * internet_address,
  size_t size);

#ifdef __cplusplus
}
#endif

#endif  // RMW__NETWORK_FLOW_ENDPOINT_H_