// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice
#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "armkidd_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "armkidd_interfaces/msg/detail/world_target__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
bool cdr_serialize_armkidd_interfaces__msg__WorldTarget(
  const armkidd_interfaces__msg__WorldTarget * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
bool cdr_deserialize_armkidd_interfaces__msg__WorldTarget(
  eprosima::fastcdr::Cdr &,
  armkidd_interfaces__msg__WorldTarget * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
size_t get_serialized_size_armkidd_interfaces__msg__WorldTarget(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
size_t max_serialized_size_armkidd_interfaces__msg__WorldTarget(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
bool cdr_serialize_key_armkidd_interfaces__msg__WorldTarget(
  const armkidd_interfaces__msg__WorldTarget * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
size_t get_serialized_size_key_armkidd_interfaces__msg__WorldTarget(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
size_t max_serialized_size_key_armkidd_interfaces__msg__WorldTarget(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armkidd_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, armkidd_interfaces, msg, WorldTarget)();

#ifdef __cplusplus
}
#endif

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
