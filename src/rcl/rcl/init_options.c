// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcl/init_options.h"

#include "./common.h"
#include "./init_options_impl.h"
#include "rcutils/macros.h"
#include "rcl/error_handling.h"
#include "rmw/error_handling.h"
#include "rcutils/logging_macros.h"
#include "rmw/init_options.h"
#include "rcutils/strdup.h"

rcl_init_options_t
rcl_get_zero_initialized_init_options(void)
{
  return (const rcl_init_options_t) {
           .impl = 0,
  };  // NOLINT(readability/braces): false positive
}

/// Initialize given init_options with the default values and zero-initialize implementation.
static inline
rcl_ret_t
_rcl_init_options_zero_init(rcl_init_options_t * init_options, rcl_allocator_t allocator)
{
  init_options->impl = allocator.allocate(sizeof(rcl_init_options_impl_t), allocator.state);
  RCL_CHECK_FOR_NULL_WITH_MSG(
    init_options->impl,
    "failed to allocate memory for init options impl",
    return RCL_RET_BAD_ALLOC);
  init_options->impl->allocator = allocator;
  init_options->impl->rmw_init_options = rmw_get_zero_initialized_init_options();

  return RCL_RET_OK;
}

rcl_ret_t
rcl_init_options_init(rcl_init_options_t * init_options, rcl_allocator_t allocator)
{
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_INVALID_ARGUMENT);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_ALREADY_INIT);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_BAD_ALLOC);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_ERROR);

  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, RCL_RET_INVALID_ARGUMENT);
  if (NULL != init_options->impl) {
    RCL_SET_ERROR_MSG("given init_options (rcl_init_options_t) is already initialized");
    return RCL_RET_ALREADY_INIT;
  }
  RCL_CHECK_ALLOCATOR(&allocator, return RCL_RET_INVALID_ARGUMENT);

  rcl_ret_t ret = _rcl_init_options_zero_init(init_options, allocator);
  if (RCL_RET_OK != ret) {
    return ret;
  }
  
  // Initialize the rmw_init_options within the impl.
  rmw_ret_t rmw_ret = RMW_RET_OK; // DUMMY 'rmw_init_options_init' call
  // rmw_ret_t rmw_ret = rmw_init_options_init(&(init_options->impl->rmw_init_options), allocator);
  // REWRITE 'rmw_init_options_init'
  rmw_init_options_t * rmw_init_options = &(init_options->impl->rmw_init_options);
  rmw_init_options->instance_id = 0;
  rmw_init_options->allocator = allocator;
  rmw_init_options->impl = NULL;
  rmw_init_options->enclave = NULL;
  rmw_init_options->domain_id = RMW_DEFAULT_DOMAIN_ID;
  rmw_init_options->security_options = rmw_get_default_security_options();
  rmw_init_options->localhost_only = RMW_LOCALHOST_ONLY_DEFAULT;

  if (RMW_RET_OK != rmw_ret) {
    allocator.deallocate(init_options->impl, allocator.state);
    RCL_SET_ERROR_MSG(rmw_get_error_string().str);
    return rcl_convert_rmw_ret_to_rcl_ret(rmw_ret);
  }
  return RCL_RET_OK;
}

rcl_ret_t
rcl_init_options_copy(const rcl_init_options_t * src, rcl_init_options_t * dst)
{
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_INVALID_ARGUMENT);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_ALREADY_INIT);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_BAD_ALLOC);
  RCUTILS_CAN_SET_MSG_AND_RETURN_WITH_ERROR_OF(RCL_RET_ERROR);

  RCL_CHECK_ARGUMENT_FOR_NULL(src, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(src->impl, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ALLOCATOR(&src->impl->allocator, return RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(dst, RCL_RET_INVALID_ARGUMENT);
  if (NULL != dst->impl) {
    RCL_SET_ERROR_MSG("given dst (rcl_init_options_t) is already initialized");
    return RCL_RET_ALREADY_INIT;
  }

  // initialize dst (since we know it's in a zero initialized state)
  rcl_ret_t ret = _rcl_init_options_zero_init(dst, src->impl->allocator);
  if (RCL_RET_OK != ret) {
    return ret;  // error already set
  }

  // copy src information into dst
  rmw_ret_t rmw_ret = RMW_RET_OK;  // DUMMY 'rmw_init_options_copy' call
  // rmw_ret_t rmw_ret =
  //   rmw_init_options_copy(&(src->impl->rmw_init_options), &(dst->impl->rmw_init_options));
  // REWRITE 'rmw_init_options_copy'
  const rmw_init_options_t * rmw_src = &(src->impl->rmw_init_options);
  rmw_init_options_t * rmw_dst = &(dst->impl->rmw_init_options);
  
  const rcutils_allocator_t * allocator = &rmw_src->allocator;
  RCUTILS_CHECK_ALLOCATOR(allocator, rmw_ret = RMW_RET_INVALID_ARGUMENT);

  rmw_init_options_t tmp = *rmw_src;
  tmp.enclave = rcutils_strdup(tmp.enclave, *allocator);
  if (NULL != rmw_src->enclave && NULL == tmp.enclave) {
    rmw_ret = RMW_RET_BAD_ALLOC;
    rmw_error_string_t error_string = rmw_get_error_string();
    rmw_reset_error();
    ret = rcl_init_options_fini(dst);
    if (RCL_RET_OK != ret) {
      RCUTILS_LOG_ERROR_NAMED(
        "rcl",
        "failed to finalize dst rcl_init_options while handling failure to "
        "copy rmw_init_options, original ret '%d' and error: %s", rmw_ret, error_string.str);
      return ret;  // error already set
    }
    RCL_SET_ERROR_MSG(error_string.str);
    return rcl_convert_rmw_ret_to_rcl_ret(rmw_ret);
  }

  tmp.security_options = rmw_get_zero_initialized_security_options();

  // entry of 'rmw_seucrity_options_copy'
  // src=rmw_src->security_options
  // dst=&tmp.security_options
  // allocator = allocator
  const rmw_security_options_t * security_options_src = &(rmw_src->security_options);
  rmw_security_options_t * security_options_dst = &(tmp.security_options);

  char * new_root_path = rcutils_strdup(
    security_options_src->security_root_path, *allocator);
  if (security_options_src->security_root_path && !new_root_path) {
    rmw_ret = RMW_RET_BAD_ALLOC;
    allocator->deallocate(tmp.enclave, allocator->state);
    rmw_error_string_t error_string = rmw_get_error_string();
    rmw_reset_error();
    ret = rcl_init_options_fini(dst);
    if (RCL_RET_OK != ret) {
      RCUTILS_LOG_ERROR_NAMED(
        "rcl",
        "failed to finalize dst rcl_init_options while handling failure to "
        "copy rmw_init_options, original ret '%d' and error: %s", rmw_ret, error_string.str);
      return ret;  // error already set
    }
    RCL_SET_ERROR_MSG(error_string.str);
    return rcl_convert_rmw_ret_to_rcl_ret(rmw_ret);
  }

  allocator->deallocate(security_options_dst->security_root_path, allocator->state);
  security_options_dst->security_root_path = new_root_path;
  security_options_dst->enforce_security = security_options_src->enforce_security;
  // exit of 'rmw_security_options_copy'

  *rmw_dst = tmp;
  // exit of 'rmw_init_options_copy'

  if (RMW_RET_OK != rmw_ret) {
    rmw_error_string_t error_string = rmw_get_error_string();
    rmw_reset_error();
    ret = rcl_init_options_fini(dst);
    if (RCL_RET_OK != ret) {
      RCUTILS_LOG_ERROR_NAMED(
        "rcl",
        "failed to finalize dst rcl_init_options while handling failure to "
        "copy rmw_init_options, original ret '%d' and error: %s", rmw_ret, error_string.str);
      return ret;  // error already set
    }
    RCL_SET_ERROR_MSG(error_string.str);
    return rcl_convert_rmw_ret_to_rcl_ret(rmw_ret);
  }

  return RCL_RET_OK;
}

rcl_ret_t
rcl_init_options_fini(rcl_init_options_t * init_options)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options->impl, RCL_RET_INVALID_ARGUMENT);
  rcl_allocator_t allocator = init_options->impl->allocator;
  RCL_CHECK_ALLOCATOR(&allocator, return RCL_RET_INVALID_ARGUMENT);
  rmw_ret_t rmw_ret = RMW_RET_OK;  // DUMMY 'rmw_init_options_fini' call
  // rmw_ret_t rmw_ret = rmw_init_options_fini(&(init_options->impl->rmw_init_options));
  // REWRITE 'rmw_init_options_fini'
  rmw_init_options_t * rmw_init_options = &(init_options->impl->rmw_init_options);
  rcutils_allocator_t * rmw_allocator = &rmw_init_options->allocator;
  RCUTILS_CHECK_ALLOCATOR(rmw_allocator, rmw_ret = RMW_RET_INVALID_ARGUMENT);

  rmw_allocator->deallocate(rmw_init_options->enclave, rmw_allocator->state);

  // entry of 'rmw_security_options_fini'
  rmw_security_options_t * security_options = &(rmw_init_options->security_options);
  rmw_allocator->deallocate(security_options->security_root_path, rmw_allocator->state);
  *security_options = rmw_get_zero_initialized_security_options();
  // exit of 'rmw_security_options_fini'
  *rmw_init_options = rmw_get_zero_initialized_init_options();
  // exit of 'rmw_init_options_fini'

  if (RMW_RET_OK != rmw_ret) {
    RCL_SET_ERROR_MSG(rmw_get_error_string().str);
    return rcl_convert_rmw_ret_to_rcl_ret(rmw_ret);
  }
  allocator.deallocate(init_options->impl, allocator.state);
  return RCL_RET_OK;
}

rcl_ret_t
rcl_init_options_get_domain_id(const rcl_init_options_t * init_options, size_t * domain_id)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options->impl, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(domain_id, RCL_RET_INVALID_ARGUMENT);
  *domain_id = init_options->impl->rmw_init_options.domain_id;
  return RCL_RET_OK;
}

rcl_ret_t
rcl_init_options_set_domain_id(rcl_init_options_t * init_options, size_t domain_id)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, RCL_RET_INVALID_ARGUMENT);
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options->impl, RCL_RET_INVALID_ARGUMENT);
  init_options->impl->rmw_init_options.domain_id = domain_id;
  return RCL_RET_OK;
}

rmw_init_options_t *
rcl_init_options_get_rmw_init_options(rcl_init_options_t * init_options)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, NULL);
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options->impl, NULL);
  return &(init_options->impl->rmw_init_options);
}

const rcl_allocator_t *
rcl_init_options_get_allocator(const rcl_init_options_t * init_options)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options, NULL);
  RCL_CHECK_ARGUMENT_FOR_NULL(init_options->impl, NULL);
  return &(init_options->impl->allocator);
}

#ifdef __cplusplus
}
#endif
