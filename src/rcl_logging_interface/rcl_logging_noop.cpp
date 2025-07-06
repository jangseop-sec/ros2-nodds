#include "rcl_logging_interface/rcl_logging_interface.h"
#include "rcutils/allocator.h"

rcl_logging_ret_t rcl_logging_external_initialize(
  const char * config_file,
  rcutils_allocator_t allocator)
{
  (void) config_file;
  (void) allocator;
  return RCL_LOGGING_RET_OK;
}

rcl_logging_ret_t rcl_logging_external_shutdown()
{
  return RCL_LOGGING_RET_OK;
}

void rcl_logging_external_log(int severity, const char * name, const char * msg)
{
  (void) severity;
  (void) name;
  (void) msg;
}

rcl_logging_ret_t rcl_logging_external_set_logger_level(const char * name, int level)
{
  (void) name;
  (void) level;
  return RCL_LOGGING_RET_OK;
}