// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/srv/mark_img.h"


#ifndef ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_H_
#define ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MarkImg in the package armkidd_interfaces.
typedef struct armkidd_interfaces__srv__MarkImg_Request
{
  int16_t x1;
  int16_t y1;
  int16_t x2;
  int16_t y2;
  int16_t choke_x;
  int16_t choke_y;
  bool is_valid;
} armkidd_interfaces__srv__MarkImg_Request;

// Struct for a sequence of armkidd_interfaces__srv__MarkImg_Request.
typedef struct armkidd_interfaces__srv__MarkImg_Request__Sequence
{
  armkidd_interfaces__srv__MarkImg_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armkidd_interfaces__srv__MarkImg_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "std_msgs/msg/detail/byte_multi_array__struct.h"

/// Struct defined in srv/MarkImg in the package armkidd_interfaces.
typedef struct armkidd_interfaces__srv__MarkImg_Response
{
  std_msgs__msg__ByteMultiArray image;
} armkidd_interfaces__srv__MarkImg_Response;

// Struct for a sequence of armkidd_interfaces__srv__MarkImg_Response.
typedef struct armkidd_interfaces__srv__MarkImg_Response__Sequence
{
  armkidd_interfaces__srv__MarkImg_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armkidd_interfaces__srv__MarkImg_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  armkidd_interfaces__srv__MarkImg_Event__request__MAX_SIZE = 1
};
// response
enum
{
  armkidd_interfaces__srv__MarkImg_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MarkImg in the package armkidd_interfaces.
typedef struct armkidd_interfaces__srv__MarkImg_Event
{
  service_msgs__msg__ServiceEventInfo info;
  armkidd_interfaces__srv__MarkImg_Request__Sequence request;
  armkidd_interfaces__srv__MarkImg_Response__Sequence response;
} armkidd_interfaces__srv__MarkImg_Event;

// Struct for a sequence of armkidd_interfaces__srv__MarkImg_Event.
typedef struct armkidd_interfaces__srv__MarkImg_Event__Sequence
{
  armkidd_interfaces__srv__MarkImg_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armkidd_interfaces__srv__MarkImg_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_H_
