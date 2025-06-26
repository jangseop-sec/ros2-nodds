#ifndef RMW__SUBSCRIPTION_CONTENT_FILTER_OPTIONS_H_
#define RMW__SUBSCRIPTION_CONTENT_FILTER_OPTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "rcutils/allocator.h"
#include "rcutils/types.h"

#include "rmw/ret_types.h"

typedef struct rmw_subscription_content_filter_options_s
{
  /**
   * Specify the criteria to select the data samples of interest.
   *
   * It is similar to the WHERE part of an SQL clause.
   */
  char * filter_expression;
  /**
   * Give values to the tokens placeholder ‘parameters’ (i.e., "%n" tokens begin from 0) in the
   * filter_expression. The number of supplied parameters must fit with the requested values.
   *
   * It can be NULL if there is no "%n" tokens placeholder in filter_expression.
   * The maximum index number must be smaller than 100.
   */
  rcutils_string_array_t expression_parameters;
} rmw_subscription_content_filter_options_t;


rmw_subscription_content_filter_options_t
rmw_get_zero_initialized_content_filter_options();

rmw_ret_t
rmw_subscription_content_filter_options_init(
  const char * filter_expression,
  size_t expression_parameters_argc,
  const char * expression_parameter_argv[],
  const rcutils_allocator_t * allocator,
  rmw_subscription_content_filter_options_t * options);

rmw_ret_t
rmw_subscription_content_filter_options_set(
  const char * filter_expression,
  size_t expression_parameters_argc,
  const char * expression_parameter_argv[],
  const rcutils_allocator_t * allocator,
  rmw_subscription_content_filter_options_t * options);

rmw_ret_t
rmw_subscription_content_filter_options_copy(
  const rmw_subscription_content_filter_options_t * src,
  const rcutils_allocator_t * allocator,
  rmw_subscription_content_filter_options_t * dst);

rmw_ret_t
rmw_subscription_content_filter_options_fini(
  rmw_subscription_content_filter_options_t * options,
  const rcutils_allocator_t * allocator);

#ifdef __cplusplus
}
#endif

#endif  // RMW__SUBSCRIPTION_CONTENT_FILTER_OPTIONS_H_