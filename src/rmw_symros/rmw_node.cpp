#include <array>
#include <mutex>
#include <utility>
#include <set>
#include <string>

#include "rcl/error_handling.h"

#include "rmw/error_handling.h"
#include "rmw/security_options.h"
#include "rmw/rmw.h"
#include "rmw/validate_namespace.h"
#include "rmw/validate_node_name.h"
#include "rmw/allocators.h"
#include "rmw/init.h"

#include "rmw_dds_common/context.hpp"

#include "rcpputils/scope_exit.hpp"

namespace rmw_symros {

rmw_node_t *
rmw_create_node(
  rmw_context_t * context,
  const char * name,
  const char * namespace_)
{
  rmw_dds_common::Context& common_context = rmw_dds_common::Context::get_instance();
  rmw_dds_common::GraphCache & graph_cache = common_context.graph_cache;

  rmw_node_t * node_handle = rmw_node_allocate();
  if (!node_handle) {
    RMW_SET_ERROR_MSG("failed to allocate node");
    return nullptr;
  }
  auto cleanup_node = rcpputils::make_scope_exit(
    [node_handle]() {
      rmw_free(const_cast<char *>(node_handle->name));
      rmw_free(const_cast<char *>(node_handle->namespace_));
      rmw_node_free(node_handle);
    });
  

  node_handle->data = nullptr;
  node_handle->name = static_cast<const char *>(rmw_allocate(sizeof(char) * strlen(name) + 1));
  if (nullptr == node_handle->name) {
    RMW_SET_ERROR_MSG("failed to copy node name");
    return nullptr;
  }
  memcpy(const_cast<char *>(node_handle->name), name, strlen(name) + 1);

  node_handle->namespace_ =
    static_cast<const char *>(rmw_allocate(sizeof(char) * strlen(namespace_) + 1));
  if (nullptr == node_handle->namespace_) {
    RMW_SET_ERROR_MSG("failed to copy node namespace");
    return nullptr;
  }
  memcpy(const_cast<char *>(node_handle->namespace_), namespace_, strlen(namespace_) + 1);

  node_handle->context = context;

  {
    // Though graph_cache methods are thread safe, both cache update and publishing have to also
    // be atomic.
    // If not, the following race condition is possible:
    // node1-update-get-message / node2-update-get-message / node2-publish / node1-publish
    // In that case, the last message published is not accurate.
    std::lock_guard<std::mutex> guard(common_context.node_update_mutex);
    rmw_dds_common::msg::ParticipantEntitiesInfo participant_msg =
      graph_cache.add_node(common_context.gid, name, namespace_);
    if (RMW_RET_OK != __rmw_publish(
        node_handle->implementation_identifier,
        common_context->pub,
        static_cast<void *>(&participant_msg),
        nullptr))
    {
      return nullptr;
    }
  }
  cleanup_node.cancel();
  return node_handle;
}





  return rmw_node;
  
}

}