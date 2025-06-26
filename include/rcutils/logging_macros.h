#ifndef RCUTILS__LOGGING_MACROS_H_
#define RCUTILS__LOGGING_MACROS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rcutils/logging.h"
  
 #include <stdio.h>
 #include <stdlib.h>
  
 #ifdef __cplusplus
 extern "C"
 {
 #endif
  
 // These are used for compiling out logging macros lower than a minimum severity.
 #define RCUTILS_LOG_MIN_SEVERITY_DEBUG 0
 #define RCUTILS_LOG_MIN_SEVERITY_INFO 1
 #define RCUTILS_LOG_MIN_SEVERITY_WARN 2
 #define RCUTILS_LOG_MIN_SEVERITY_ERROR 3
 #define RCUTILS_LOG_MIN_SEVERITY_FATAL 4
 #define RCUTILS_LOG_MIN_SEVERITY_NONE 5
  
 #ifndef RCUTILS_LOG_MIN_SEVERITY
 #define RCUTILS_LOG_MIN_SEVERITY RCUTILS_LOG_MIN_SEVERITY_DEBUG
 #endif
  
 // TODO(dhood): optimise severity check via notifyLoggerLevelsChanged concept or similar.
 // The RCUTILS_LOG_COND_NAMED macro is surrounded by do { .. } while (0) to implement
 // the standard C macro idiom to make the macro safe in all contexts; see
 // http://c-faq.com/cpp/multistmt.html for more information.
 #define RCUTILS_LOG_COND_NAMED(severity, condition_before, condition_after, name, ...) \
   do { \
     RCUTILS_LOGGING_AUTOINIT \
     static rcutils_log_location_t __rcutils_logging_location = {__func__, __FILE__, __LINE__}; \
     if (rcutils_logging_logger_is_enabled_for(name, severity)) { \
       condition_before \
       rcutils_log(&__rcutils_logging_location, severity, name, __VA_ARGS__); \
       condition_after \
     } \
   } while (0)
  
  
 #define RCUTILS_LOG_CONDITION_EMPTY
  
  
 #define RCUTILS_LOG_CONDITION_ONCE_BEFORE \
   { \
     static int __rcutils_logging_once = 0; \
     if (RCUTILS_UNLIKELY(0 == __rcutils_logging_once)) { \
       __rcutils_logging_once = 1;
  
 #define RCUTILS_LOG_CONDITION_ONCE_AFTER } \
 }
  
  
 #define RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression) \
   if (expression) {
  
 #define RCUTILS_LOG_CONDITION_EXPRESSION_AFTER }
  
  
 typedef bool (* RclLogFilter)();
 #define RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function) \
   if ((*function)()) {
  
 #define RCUTILS_LOG_CONDITION_FUNCTION_AFTER }
  
  
 #define RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE \
   { \
     static bool __rcutils_logging_first = true; \
     if (RCUTILS_UNLIKELY(true == __rcutils_logging_first)) { \
       __rcutils_logging_first = false; \
     } else {
  
 #define RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER } \
 }
  
  
 #define RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) { \
     static rcutils_duration_value_t __rcutils_logging_duration = RCUTILS_MS_TO_NS((rcutils_duration_value_t)duration); \
     static rcutils_time_point_value_t __rcutils_logging_last_logged = 0; \
     rcutils_time_point_value_t __rcutils_logging_now = 0; \
     bool __rcutils_logging_condition = true; \
     if (get_time_point_value(&__rcutils_logging_now) != RCUTILS_RET_OK) { \
       rcutils_log( \
         &__rcutils_logging_location, RCUTILS_LOG_SEVERITY_ERROR, "", \
         "%s() at %s:%d getting current steady time failed\n", \
         __func__, __FILE__, __LINE__); \
     } else { \
       __rcutils_logging_condition = __rcutils_logging_now >= __rcutils_logging_last_logged + __rcutils_logging_duration; \
     } \
  \
     if (RCUTILS_LIKELY(__rcutils_logging_condition)) { \
       __rcutils_logging_last_logged = __rcutils_logging_now;
  
 #define RCUTILS_LOG_CONDITION_THROTTLE_AFTER } \
 }
  
 #if (RCUTILS_LOG_MIN_SEVERITY > RCUTILS_LOG_MIN_SEVERITY_DEBUG)
 // empty logging macros for severity DEBUG when being disabled at compile time
 # define RCUTILS_LOG_DEBUG(format, ...)
 # define RCUTILS_LOG_DEBUG_NAMED(name, format, ...)
 # define RCUTILS_LOG_DEBUG_ONCE(format, ...)
 # define RCUTILS_LOG_DEBUG_ONCE_NAMED(name, format, ...)
 # define RCUTILS_LOG_DEBUG_EXPRESSION(expression, format, ...)
 # define RCUTILS_LOG_DEBUG_EXPRESSION_NAMED(expression, name, format, ...)
 # define RCUTILS_LOG_DEBUG_FUNCTION(function, format, ...)
 # define RCUTILS_LOG_DEBUG_FUNCTION_NAMED(function, name, format, ...)
 # define RCUTILS_LOG_DEBUG_SKIPFIRST(format, ...)
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_NAMED(name, format, ...)
 # define RCUTILS_LOG_DEBUG_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_DEBUG_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
  
 #else
  
 # define RCUTILS_LOG_DEBUG(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_ONCE(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_ONCE_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_EXPRESSION(expression, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_EXPRESSION_NAMED(expression, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_FUNCTION(function, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_FUNCTION_NAMED(function, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_SKIPFIRST(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_DEBUG_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_DEBUG, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
 #endif
  
 #if (RCUTILS_LOG_MIN_SEVERITY > RCUTILS_LOG_MIN_SEVERITY_INFO)
 // empty logging macros for severity INFO when being disabled at compile time
 # define RCUTILS_LOG_INFO(format, ...)
 # define RCUTILS_LOG_INFO_NAMED(name, format, ...)
 # define RCUTILS_LOG_INFO_ONCE(format, ...)
 # define RCUTILS_LOG_INFO_ONCE_NAMED(name, format, ...)
 # define RCUTILS_LOG_INFO_EXPRESSION(expression, format, ...)
 # define RCUTILS_LOG_INFO_EXPRESSION_NAMED(expression, name, format, ...)
 # define RCUTILS_LOG_INFO_FUNCTION(function, format, ...)
 # define RCUTILS_LOG_INFO_FUNCTION_NAMED(function, name, format, ...)
 # define RCUTILS_LOG_INFO_SKIPFIRST(format, ...)
 # define RCUTILS_LOG_INFO_SKIPFIRST_NAMED(name, format, ...)
 # define RCUTILS_LOG_INFO_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_INFO_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
 # define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
  
 #else
  
 # define RCUTILS_LOG_INFO(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_ONCE(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_ONCE_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_EXPRESSION(expression, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_EXPRESSION_NAMED(expression, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_FUNCTION(function, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_FUNCTION_NAMED(function, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_SKIPFIRST(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_SKIPFIRST_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_INFO_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_INFO, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
 #endif
  
 #if (RCUTILS_LOG_MIN_SEVERITY > RCUTILS_LOG_MIN_SEVERITY_WARN)
 // empty logging macros for severity WARN when being disabled at compile time
 # define RCUTILS_LOG_WARN(format, ...)
 # define RCUTILS_LOG_WARN_NAMED(name, format, ...)
 # define RCUTILS_LOG_WARN_ONCE(format, ...)
 # define RCUTILS_LOG_WARN_ONCE_NAMED(name, format, ...)
 # define RCUTILS_LOG_WARN_EXPRESSION(expression, format, ...)
 # define RCUTILS_LOG_WARN_EXPRESSION_NAMED(expression, name, format, ...)
 # define RCUTILS_LOG_WARN_FUNCTION(function, format, ...)
 # define RCUTILS_LOG_WARN_FUNCTION_NAMED(function, name, format, ...)
 # define RCUTILS_LOG_WARN_SKIPFIRST(format, ...)
 # define RCUTILS_LOG_WARN_SKIPFIRST_NAMED(name, format, ...)
 # define RCUTILS_LOG_WARN_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_WARN_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
 # define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
  
 #else
  
 # define RCUTILS_LOG_WARN(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_ONCE(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_ONCE_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_EXPRESSION(expression, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_EXPRESSION_NAMED(expression, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_FUNCTION(function, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_FUNCTION_NAMED(function, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_SKIPFIRST(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_SKIPFIRST_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_WARN_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_WARN, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
 #endif
  
 #if (RCUTILS_LOG_MIN_SEVERITY > RCUTILS_LOG_MIN_SEVERITY_ERROR)
 // empty logging macros for severity ERROR when being disabled at compile time
 # define RCUTILS_LOG_ERROR(format, ...)
 # define RCUTILS_LOG_ERROR_NAMED(name, format, ...)
 # define RCUTILS_LOG_ERROR_ONCE(format, ...)
 # define RCUTILS_LOG_ERROR_ONCE_NAMED(name, format, ...)
 # define RCUTILS_LOG_ERROR_EXPRESSION(expression, format, ...)
 # define RCUTILS_LOG_ERROR_EXPRESSION_NAMED(expression, name, format, ...)
 # define RCUTILS_LOG_ERROR_FUNCTION(function, format, ...)
 # define RCUTILS_LOG_ERROR_FUNCTION_NAMED(function, name, format, ...)
 # define RCUTILS_LOG_ERROR_SKIPFIRST(format, ...)
 # define RCUTILS_LOG_ERROR_SKIPFIRST_NAMED(name, format, ...)
 # define RCUTILS_LOG_ERROR_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_ERROR_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
 # define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
  
 #else
  
 # define RCUTILS_LOG_ERROR(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_ONCE(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_ONCE_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_EXPRESSION(expression, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_EXPRESSION_NAMED(expression, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_FUNCTION(function, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_FUNCTION_NAMED(function, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_SKIPFIRST(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_SKIPFIRST_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_ERROR_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_ERROR, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
 #endif
  
 #if (RCUTILS_LOG_MIN_SEVERITY > RCUTILS_LOG_MIN_SEVERITY_FATAL)
 // empty logging macros for severity FATAL when being disabled at compile time
 # define RCUTILS_LOG_FATAL(format, ...)
 # define RCUTILS_LOG_FATAL_NAMED(name, format, ...)
 # define RCUTILS_LOG_FATAL_ONCE(format, ...)
 # define RCUTILS_LOG_FATAL_ONCE_NAMED(name, format, ...)
 # define RCUTILS_LOG_FATAL_EXPRESSION(expression, format, ...)
 # define RCUTILS_LOG_FATAL_EXPRESSION_NAMED(expression, name, format, ...)
 # define RCUTILS_LOG_FATAL_FUNCTION(function, format, ...)
 # define RCUTILS_LOG_FATAL_FUNCTION_NAMED(function, name, format, ...)
 # define RCUTILS_LOG_FATAL_SKIPFIRST(format, ...)
 # define RCUTILS_LOG_FATAL_SKIPFIRST_NAMED(name, format, ...)
 # define RCUTILS_LOG_FATAL_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE(get_time_point_value, duration, format, ...)
 # define RCUTILS_LOG_FATAL_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
 # define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, format, ...)
  
 #else
  
 # define RCUTILS_LOG_FATAL(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_EMPTY, RCUTILS_LOG_CONDITION_EMPTY, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_ONCE(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_ONCE_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_ONCE_BEFORE, RCUTILS_LOG_CONDITION_ONCE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_EXPRESSION(expression, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_EXPRESSION_NAMED(expression, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_EXPRESSION_BEFORE(expression), RCUTILS_LOG_CONDITION_EXPRESSION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_FUNCTION(function, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_FUNCTION_NAMED(function, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_FUNCTION_BEFORE(function), RCUTILS_LOG_CONDITION_FUNCTION_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_SKIPFIRST(...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_SKIPFIRST_NAMED(name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE(get_time_point_value, duration, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, NULL, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration), RCUTILS_LOG_CONDITION_THROTTLE_AFTER, name, \
     __VA_ARGS__)
  
 # define RCUTILS_LOG_FATAL_SKIPFIRST_THROTTLE_NAMED(get_time_point_value, duration, name, ...) \
   RCUTILS_LOG_COND_NAMED( \
     RCUTILS_LOG_SEVERITY_FATAL, \
     RCUTILS_LOG_CONDITION_THROTTLE_BEFORE(get_time_point_value, duration) RCUTILS_LOG_CONDITION_SKIPFIRST_BEFORE, RCUTILS_LOG_CONDITION_THROTTLE_AFTER RCUTILS_LOG_CONDITION_SKIPFIRST_AFTER, name, \
     __VA_ARGS__)
 #endif

#ifdef __cplusplus
}
#endif

#endif  // RCUTILS__LOGGING_MACROS_H_