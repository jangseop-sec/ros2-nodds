#ifndef RMW__MACROS_H_
#define RMW__MACROS_H_

#include "rcutils/macros.h"

/// Expand the argument to its literal text
#define RMW_STRINGIFY(x) RCUTILS_STRINGIFY(x)

/// Indicate that a variable is not used, and prevent compiler from issuing warnings
#define RMW_WARN_UNUSED RCUTILS_WARN_UNUSED

#endif  // RMW__MACROS_H_