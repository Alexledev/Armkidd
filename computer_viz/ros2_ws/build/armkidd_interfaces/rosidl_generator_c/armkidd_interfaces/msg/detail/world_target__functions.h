// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/world_target.h"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__FUNCTIONS_H_
#define ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "armkidd_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "armkidd_interfaces/msg/detail/world_target__struct.h"

/// Initialize msg/WorldTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * armkidd_interfaces__msg__WorldTarget
 * )) before or use
 * armkidd_interfaces__msg__WorldTarget__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__init(armkidd_interfaces__msg__WorldTarget * msg);

/// Finalize msg/WorldTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
void
armkidd_interfaces__msg__WorldTarget__fini(armkidd_interfaces__msg__WorldTarget * msg);

/// Create msg/WorldTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * armkidd_interfaces__msg__WorldTarget__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
armkidd_interfaces__msg__WorldTarget *
armkidd_interfaces__msg__WorldTarget__create(void);

/// Destroy msg/WorldTarget message.
/**
 * It calls
 * armkidd_interfaces__msg__WorldTarget__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
void
armkidd_interfaces__msg__WorldTarget__destroy(armkidd_interfaces__msg__WorldTarget * msg);

/// Check for msg/WorldTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__are_equal(const armkidd_interfaces__msg__WorldTarget * lhs, const armkidd_interfaces__msg__WorldTarget * rhs);

/// Copy a msg/WorldTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__copy(
  const armkidd_interfaces__msg__WorldTarget * input,
  armkidd_interfaces__msg__WorldTarget * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__msg__WorldTarget__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__msg__WorldTarget__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__msg__WorldTarget__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__msg__WorldTarget__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/WorldTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * armkidd_interfaces__msg__WorldTarget__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__Sequence__init(armkidd_interfaces__msg__WorldTarget__Sequence * array, size_t size);

/// Finalize array of msg/WorldTarget messages.
/**
 * It calls
 * armkidd_interfaces__msg__WorldTarget__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
void
armkidd_interfaces__msg__WorldTarget__Sequence__fini(armkidd_interfaces__msg__WorldTarget__Sequence * array);

/// Create array of msg/WorldTarget messages.
/**
 * It allocates the memory for the array and calls
 * armkidd_interfaces__msg__WorldTarget__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
armkidd_interfaces__msg__WorldTarget__Sequence *
armkidd_interfaces__msg__WorldTarget__Sequence__create(size_t size);

/// Destroy array of msg/WorldTarget messages.
/**
 * It calls
 * armkidd_interfaces__msg__WorldTarget__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
void
armkidd_interfaces__msg__WorldTarget__Sequence__destroy(armkidd_interfaces__msg__WorldTarget__Sequence * array);

/// Check for msg/WorldTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__Sequence__are_equal(const armkidd_interfaces__msg__WorldTarget__Sequence * lhs, const armkidd_interfaces__msg__WorldTarget__Sequence * rhs);

/// Copy an array of msg/WorldTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
bool
armkidd_interfaces__msg__WorldTarget__Sequence__copy(
  const armkidd_interfaces__msg__WorldTarget__Sequence * input,
  armkidd_interfaces__msg__WorldTarget__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__FUNCTIONS_H_
