// generated from rcutils/resource/logging_macros.h.em

// Copyright 2017 Open Source Robotics Foundation, Inc.
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

/*! \file */

#ifndef RCUTILS__LOGGING_MACROS_H_
#define RCUTILS__LOGGING_MACROS_H_

#include "rcutils/logging.h"

#include <stdio.h>
#include <stdlib.h>

// This is to avoid compilation warnings in C++ with '-Wold-style-cast'.
#ifdef __cplusplus
  #define RCUTILS_CAST_DURATION(x) 
#else
  #define RCUTILS_CAST_DURATION(x) 
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// 모든 로깅 매크로를 빈 함수(매크로)로 재정의
#define RCUTILS_LOG_DEBUG(...)
#define RCUTILS_LOG_DEBUG_NAMED(name, ...)
#define RCUTILS_LOG_DEBUG_ONCE(...)
#define RCUTILS_LOG_DEBUG_ONCE_NAMED(name, ...)
#define RCUTILS_LOG_DEBUG_EXPRESSION(expression, ...)
#define RCUTILS_LOG_DEBUG_EXPRESSION_NAMED(expression, name, ...)
#define RCUTILS_LOG_DEBUG_FUNCTION(function, ...)
#define RCUTILS_LOG_DEBUG_FUNCTION_NAMED(function, name, ...)
#define RCUTILS_LOG_DEBUG_SKIPFIRST(...)
#define RCUTILS_LOG_DEBUG_SKIPFIRST_NAMED(name, ...)
#define RCUTILS_LOG_DEBUG_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_DEBUG_THROTTLE_NAMED(get_time_point_value, duration, name, ...)
#define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...)

#define RCUTILS_LOG_INFO(...)
#define RCUTILS_LOG_INFO_NAMED(name, ...)
#define RCUTILS_LOG_INFO_ONCE(...)
#define RCUTILS_LOG_INFO_ONCE_NAMED(name, ...)
#define RCUTILS_LOG_INFO_EXPRESSION(expression, ...)
#define RCUTILS_LOG_INFO_EXPRESSION_NAMED(expression, name, ...)
#define RCUTILS_LOG_INFO_FUNCTION(function, ...)
#define RCUTILS_LOG_INFO_FUNCTION_NAMED(function, name, ...)
#define RCUTILS_LOG_INFO_SKIPFIRST(...)
#define RCUTILS_LOG_INFO_SKIPFIRST_NAMED(name, ...)
#define RCUTILS_LOG_INFO_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_INFO_THROTTLE_NAMED(get_time_point_value, duration, name, ...)
#define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...)

#define RCUTILS_LOG_WARN(...)
#define RCUTILS_LOG_WARN_NAMED(name, ...)
#define RCUTILS_LOG_WARN_ONCE(...)
#define RCUTILS_LOG_WARN_ONCE_NAMED(name, ...)
#define RCUTILS_LOG_WARN_EXPRESSION(expression, ...)
#define RCUTILS_LOG_WARN_EXPRESSION_NAMED(expression, name, ...)
#define RCUTILS_LOG_WARN_FUNCTION(function, ...)
#define RCUTILS_LOG_WARN_FUNCTION_NAMED(function, name, ...)
#define RCUTILS_LOG_WARN_SKIPFIRST(...)
#define RCUTILS_LOG_WARN_SKIPFIRST_NAMED(name, ...)
#define RCUTILS_LOG_WARN_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_WARN_THROTTLE_NAMED(get_time_point_value, duration, name, ...)
#define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...)

#define RCUTILS_LOG_ERROR(...)
#define RCUTILS_LOG_ERROR_NAMED(name, ...)
#define RCUTILS_LOG_ERROR_ONCE(...)
#define RCUTILS_LOG_ERROR_ONCE_NAMED(name, ...)
#define RCUTILS_LOG_ERROR_EXPRESSION(expression, ...)
#define RCUTILS_LOG_ERROR_EXPRESSION_NAMED(expression, name, ...)
#define RCUTILS_LOG_ERROR_FUNCTION(function, ...)
#define RCUTILS_LOG_ERROR_FUNCTION_NAMED(function, name, ...)
#define RCUTILS_LOG_ERROR_SKIPFIRST(...)
#define RCUTILS_LOG_ERROR_SKIPFIRST_NAMED(name, ...)
#define RCUTILS_LOG_ERROR_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_ERROR_THROTTLE_NAMED(get_time_point_value, duration, name, ...)
#define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...)

#define RCUTILS_LOG_FATAL(...)
#define RCUTILS_LOG_FATAL_NAMED(name, ...)
#define RCUTILS_LOG_FATAL_ONCE(...)
#define RCUTILS_LOG_FATAL_ONCE_NAMED(name, ...)
#define RCUTILS_LOG_FATAL_EXPRESSION(expression, ...)
#define RCUTILS_LOG_FATAL_EXPRESSION_NAMED(expression, name, ...)
#define RCUTILS_LOG_FATAL_FUNCTION(function, ...)
#define RCUTILS_LOG_FATAL_FUNCTION_NAMED(function, name, ...)
#define RCUTILS_LOG_FATAL_SKIPFIRST(...)
#define RCUTILS_LOG_FATAL_SKIPFIRST_NAMED(name, ...)
#define RCUTILS_LOG_FATAL_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...)
#define RCUTILS_LOG_FATAL_THROTTLE_NAMED(get_time_point_value, duration, name, ...)
#define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...)


#ifdef __cplusplus
}
#endif

#endif  // RCUTILS__LOGGING_MACROS_H_
