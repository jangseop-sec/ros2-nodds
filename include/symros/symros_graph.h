#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

#include "rcl/rcl.h"
#include "rcl/node.h"
#include "rcl/publisher.h"
#include "rcl/subscription.h"
#include "rcl/service.h"
#include "rcl/client.h"
#include "rcl/graph.h"                 // rcl_names_and_types_t 정의만 사용
#include "rcutils/allocator.h"
#include "rcutils/strdup.h"
#include "rcutils/types/string_array.h"

// ===== vector → double pointer(+count)만 변경한 구조 =====
typedef struct symros_node_info {
  rcl_node_t * node;

  rcl_publisher_t   **pubs;     size_t pubs_count;
  rcl_subscription_t **subs;     size_t subs_count;
  rcl_service_t     **srvs;     size_t srvs_count;
  rcl_client_t      **clients;  size_t clients_count;

  char **pubs_type;     size_t pubs_type_count;
  char **subs_type;     size_t subs_type_count;
  char **srvs_type;     size_t srvs_type_count;
  char **clients_type;  size_t clients_type_count;
} symros_node_info;

typedef struct symros_node_graph {
  symros_node_info **nodes_info; size_t nodes_count;

  rcutils_allocator_t alloc;
} symros_node_graph;

// singleton
symros_node_graph * symros_get_node_graph(void);

// add/remove
void symros_add_node(rcl_node_t * node);
void symros_add_publisher(rcl_node_t * node, rcl_publisher_t * pub, const char * type_);
void symros_add_subscription(rcl_node_t * node, rcl_subscription_t * sub, const char * type_);
void symros_add_service(rcl_node_t * node, rcl_service_t * srv, const char * type_);
void symros_add_client(rcl_node_t * node, rcl_client_t * client, const char * type_);

void symros_remove_node(rcl_node_t * node);
void symros_remove_publisher(rcl_publisher_t * pub);
void symros_remove_subscription(rcl_subscription_t * sub);
void symros_remove_service(rcl_service_t * srv);
void symros_remove_client(rcl_client_t * client);

// queries (symros_graph 내부 상태만 사용)
rcl_ret_t symros_get_publisher_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types);
rcl_ret_t symros_get_subscriber_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types);
rcl_ret_t symros_get_service_names_and_types_by_node  (char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types);
rcl_ret_t symros_get_client_names_and_types_by_node   (char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types);
rcl_ret_t symros_get_topic_names_and_types_           (rcl_names_and_types_t * topic_names_and_types);
rcl_ret_t symros_get_service_names_and_types          (rcl_names_and_types_t * service_names_and_types);
rcl_ret_t symros_get_node_names                       (rcutils_string_array_t * node_names, rcutils_string_array_t * node_namespaces);

// counters / availability
rcl_ret_t symros_count_publishers  (const char * topic_name, size_t count /*unused*/);
rcl_ret_t symros_count_subscribers (const char * topic_name, size_t count /*unused*/);
rcl_ret_t symros_service_server_is_available(const rcl_client_t * client, bool * is_available);

// for logging
void symros_print_node_info(const symros_node_info * info);
void symros_print_node_graph(const symros_node_graph * graph);

#ifdef __cplusplus
}
#endif
