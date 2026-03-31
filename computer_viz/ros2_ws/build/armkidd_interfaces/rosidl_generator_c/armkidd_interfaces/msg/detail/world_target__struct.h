// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/world_target.h"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__STRUCT_H_
#define ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WorldTarget in the package armkidd_interfaces.
typedef struct armkidd_interfaces__msg__WorldTarget
{
  float target_x;
  float target_y;
  float depth;
  float width;
  float height;
} armkidd_interfaces__msg__WorldTarget;

// Struct for a sequence of armkidd_interfaces__msg__WorldTarget.
typedef struct armkidd_interfaces__msg__WorldTarget__Sequence
{
  armkidd_interfaces__msg__WorldTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armkidd_interfaces__msg__WorldTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__STRUCT_H_
