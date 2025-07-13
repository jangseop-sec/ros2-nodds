// generated from rclcpp/resource/logging.hpp.em

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

#ifndef RCLCPP__LOGGING_HPP_
#define RCLCPP__LOGGING_HPP_

#include <sstream>
#include <type_traits>

#include "rclcpp/logger.hpp"
#include "rcutils/logging_macros.h"
#include "rclcpp/utilities.hpp"

#define RCLCPP_DEBUG(logger, ...)
#define RCLCPP_DEBUG_ONCE(logger, ...)
#define RCLCPP_DEBUG_EXPRESSION(logger, expression, ...)
#define RCLCPP_DEBUG_FUNCTION(logger, function, ...)
#define RCLCPP_DEBUG_SKIPFIRST(logger, ...)
#define RCLCPP_DEBUG_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_DEBUG_SKIPFIRST_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_DEBUG_STREAM(logger, stream_arg)
#define RCLCPP_DEBUG_STREAM_ONCE(logger, stream_arg)
#define RCLCPP_DEBUG_STREAM_EXPRESSION(logger, expression, stream_arg)
#define RCLCPP_DEBUG_STREAM_FUNCTION(logger, function, stream_arg)
#define RCLCPP_DEBUG_STREAM_SKIPFIRST(logger, stream_arg)
#define RCLCPP_DEBUG_STREAM_THROTTLE(logger, clock, duration, stream_arg)
#define RCLCPP_DEBUG_STREAM_SKIPFIRST_THROTTLE(logger, clock, duration, stream_arg)

#define RCLCPP_INFO(logger, ...)
#define RCLCPP_INFO_ONCE(logger, ...)
#define RCLCPP_INFO_EXPRESSION(logger, expression, ...)
#define RCLCPP_INFO_FUNCTION(logger, function, ...)
#define RCLCPP_INFO_SKIPFIRST(logger, ...)
#define RCLCPP_INFO_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_INFO_SKIPFIRST_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_INFO_STREAM(logger, stream_arg)
#define RCLCPP_INFO_STREAM_ONCE(logger, stream_arg)
#define RCLCPP_INFO_STREAM_EXPRESSION(logger, expression, stream_arg)
#define RCLCPP_INFO_STREAM_FUNCTION(logger, function, stream_arg)
#define RCLCPP_INFO_STREAM_SKIPFIRST(logger, stream_arg)
#define RCLCPP_INFO_STREAM_THROTTLE(logger, clock, duration, stream_arg)
#define RCLCPP_INFO_STREAM_SKIPFIRST_THROTTLE(logger, clock, duration, stream_arg)

#define RCLCPP_WARN(logger, ...)
#define RCLCPP_WARN_ONCE(logger, ...)
#define RCLCPP_WARN_EXPRESSION(logger, expression, ...)
#define RCLCPP_WARN_FUNCTION(logger, function, ...)
#define RCLCPP_WARN_SKIPFIRST(logger, ...)
#define RCLCPP_WARN_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_WARN_SKIPFIRST_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_WARN_STREAM(logger, stream_arg)
#define RCLCPP_WARN_STREAM_ONCE(logger, stream_arg)
#define RCLCPP_WARN_STREAM_EXPRESSION(logger, expression, stream_arg)
#define RCLCPP_WARN_STREAM_FUNCTION(logger, function, stream_arg)
#define RCLCPP_WARN_STREAM_SKIPFIRST(logger, stream_arg)
#define RCLCPP_WARN_STREAM_THROTTLE(logger, clock, duration, stream_arg)
#define RCLCPP_WARN_STREAM_SKIPFIRST_THROTTLE(logger, clock, duration, stream_arg)

#define RCLCPP_ERROR(logger, ...)
#define RCLCPP_ERROR_ONCE(logger, ...)
#define RCLCPP_ERROR_EXPRESSION(logger, expression, ...)
#define RCLCPP_ERROR_FUNCTION(logger, function, ...)
#define RCLCPP_ERROR_SKIPFIRST(logger, ...)
#define RCLCPP_ERROR_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_ERROR_SKIPFIRST_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_ERROR_STREAM(logger, stream_arg)
#define RCLCPP_ERROR_STREAM_ONCE(logger, stream_arg)
#define RCLCPP_ERROR_STREAM_EXPRESSION(logger, expression, stream_arg)
#define RCLCPP_ERROR_STREAM_FUNCTION(logger, function, stream_arg)
#define RCLCPP_ERROR_STREAM_SKIPFIRST(logger, stream_arg)
#define RCLCPP_ERROR_STREAM_THROTTLE(logger, clock, duration, stream_arg)
#define RCLCPP_ERROR_STREAM_SKIPFIRST_THROTTLE(logger, clock, duration, stream_arg)

#define RCLCPP_FATAL(logger, ...)
#define RCLCPP_FATAL_ONCE(logger, ...)
#define RCLCPP_FATAL_EXPRESSION(logger, expression, ...)
#define RCLCPP_FATAL_FUNCTION(logger, function, ...)
#define RCLCPP_FATAL_SKIPFIRST(logger, ...)
#define RCLCPP_FATAL_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_FATAL_SKIPFIRST_THROTTLE(logger, clock, duration, ...)
#define RCLCPP_FATAL_STREAM(logger, stream_arg)
#define RCLCPP_FATAL_STREAM_ONCE(logger, stream_arg)
#define RCLCPP_FATAL_STREAM_EXPRESSION(logger, expression, stream_arg)
#define RCLCPP_FATAL_STREAM_FUNCTION(logger, function, stream_arg)
#define RCLCPP_FATAL_STREAM_SKIPFIRST(logger, stream_arg)
#define RCLCPP_FATAL_STREAM_THROTTLE(logger, clock, duration, stream_arg)
#define RCLCPP_FATAL_STREAM_SKIPFIRST_THROTTLE(logger, clock, duration, stream_arg)

#endif  // RCLCPP__LOGGING_HPP_
