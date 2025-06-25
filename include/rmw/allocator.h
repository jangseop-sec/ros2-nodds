#ifndef RMW__ALLOCATOR_H_
#define RMW__ALLOCATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct rcutils_allocator_s
{
  /// Allocate memory, given a size and the `state` pointer.
  /** An error should be indicated by returning `NULL`. */
  void * (*allocate)(size_t size, void * state);
  /// Deallocate previously allocated memory, mimicking free().
  /** Also takes the `state` pointer. */
  void (* deallocate)(void * pointer, void * state);
  /// Reallocate if possible, otherwise it deallocates and allocates.
  /**
   * Also takes the `state` pointer.
   *
   * If unsupported then do deallocate and then allocate.
   * This should behave as realloc() does, as opposed to posix's
   * [reallocf](https://linux.die.net/man/3/reallocf), i.e. the memory given
   * by pointer will not be free'd automatically if realloc() fails.
   * For reallocf-like behavior use rcutils_reallocf().
   * This function must be able to take an input pointer of `NULL` and succeed.
   */
  void * (*reallocate)(void * pointer, size_t size, void * state);
  /// Allocate memory with all elements set to zero, given a number of elements and their size.
  /** An error should be indicated by returning `NULL`. */
  void * (*zero_allocate)(size_t number_of_elements, size_t size_of_element, void * state);
  /// Implementation defined state storage.
  /**
   * This is passed as the final parameter to other allocator functions.
   * Note that the contents of the state can be modified even in const-qualified
   * allocator objects.
   */
  void * state;
} rcutils_allocator_t;


#ifdef __cplusplus
}
#endif

#endif  // RMW__ALLOCATOR_H_