// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

#include "armkidd_interfaces/srv/detail/mark_img__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__srv__MarkImg__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1a, 0x4c, 0x65, 0x89, 0x1a, 0xf2, 0x95, 0x85,
      0x24, 0x88, 0x3f, 0x71, 0xe5, 0x65, 0x46, 0x60,
      0x8b, 0x03, 0xe0, 0xd0, 0x6f, 0x26, 0x14, 0xda,
      0xcc, 0x01, 0x5d, 0x30, 0x98, 0x94, 0x8c, 0x9f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__srv__MarkImg_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0xd4, 0xd4, 0x3d, 0xae, 0x69, 0x5d, 0xda,
      0xf4, 0x6d, 0xbd, 0xff, 0x87, 0x42, 0xb5, 0x50,
      0xa9, 0x07, 0x1d, 0x59, 0xac, 0x0e, 0xd9, 0x8a,
      0x70, 0xf5, 0x2e, 0xd8, 0xaa, 0xa2, 0x05, 0xf8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__srv__MarkImg_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc0, 0xaf, 0xe0, 0xd6, 0x78, 0x2f, 0x42, 0x87,
      0xb0, 0x48, 0x41, 0x20, 0x14, 0x9f, 0xfe, 0xcf,
      0xe8, 0x93, 0x4d, 0x9e, 0x67, 0x7c, 0x5b, 0x42,
      0xa9, 0xd7, 0xa1, 0x68, 0x8a, 0x52, 0xec, 0x03,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__srv__MarkImg_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdd, 0x67, 0x48, 0x9d, 0xe4, 0x22, 0x28, 0xac,
      0x6c, 0xc2, 0x26, 0x9c, 0x2d, 0xed, 0x29, 0xf1,
      0xdc, 0x1d, 0xcf, 0x56, 0xa1, 0xda, 0xb7, 0xe7,
      0x0c, 0xef, 0x39, 0x7e, 0xb6, 0xe5, 0x73, 0x25,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/byte_multi_array__functions.h"
#include "std_msgs/msg/detail/multi_array_layout__functions.h"
#include "std_msgs/msg/detail/multi_array_dimension__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__ByteMultiArray__EXPECTED_HASH = {1, {
    0x97, 0x2f, 0xec, 0x7f, 0x50, 0xab, 0x3c, 0x1d,
    0x06, 0x78, 0x3c, 0x22, 0x8e, 0x79, 0xe8, 0xa9,
    0xa5, 0x09, 0x02, 0x17, 0x08, 0xc5, 0x11, 0xc0,
    0x59, 0x92, 0x62, 0x61, 0xad, 0xa9, 0x01, 0xd4,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayDimension__EXPECTED_HASH = {1, {
    0x5e, 0x77, 0x3a, 0x60, 0xa4, 0xc7, 0xfc, 0x8a,
    0x54, 0x98, 0x5f, 0x30, 0x7c, 0x78, 0x37, 0xaa,
    0x29, 0x94, 0x25, 0x2a, 0x12, 0x6c, 0x30, 0x19,
    0x57, 0xa2, 0x4e, 0x31, 0x28, 0x2c, 0x9c, 0xbe,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayLayout__EXPECTED_HASH = {1, {
    0x4c, 0x66, 0xe6, 0xf7, 0x8e, 0x74, 0x0a, 0xc1,
    0x03, 0xa9, 0x4c, 0xf6, 0x32, 0x59, 0xf9, 0x68,
    0xe4, 0x8c, 0x61, 0x7e, 0x76, 0x99, 0xe8, 0x29,
    0xb6, 0x3c, 0x21, 0xa5, 0xcb, 0x50, 0xda, 0xc6,
  }};
#endif

static char armkidd_interfaces__srv__MarkImg__TYPE_NAME[] = "armkidd_interfaces/srv/MarkImg";
static char armkidd_interfaces__srv__MarkImg_Event__TYPE_NAME[] = "armkidd_interfaces/srv/MarkImg_Event";
static char armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME[] = "armkidd_interfaces/srv/MarkImg_Request";
static char armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME[] = "armkidd_interfaces/srv/MarkImg_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__ByteMultiArray__TYPE_NAME[] = "std_msgs/msg/ByteMultiArray";
static char std_msgs__msg__MultiArrayDimension__TYPE_NAME[] = "std_msgs/msg/MultiArrayDimension";
static char std_msgs__msg__MultiArrayLayout__TYPE_NAME[] = "std_msgs/msg/MultiArrayLayout";

// Define type names, field names, and default values
static char armkidd_interfaces__srv__MarkImg__FIELD_NAME__request_message[] = "request_message";
static char armkidd_interfaces__srv__MarkImg__FIELD_NAME__response_message[] = "response_message";
static char armkidd_interfaces__srv__MarkImg__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field armkidd_interfaces__srv__MarkImg__FIELDS[] = {
  {
    {armkidd_interfaces__srv__MarkImg__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {armkidd_interfaces__srv__MarkImg_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription armkidd_interfaces__srv__MarkImg__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {armkidd_interfaces__srv__MarkImg_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__srv__MarkImg__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {armkidd_interfaces__srv__MarkImg__TYPE_NAME, 30, 30},
      {armkidd_interfaces__srv__MarkImg__FIELDS, 3, 3},
    },
    {armkidd_interfaces__srv__MarkImg__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = armkidd_interfaces__srv__MarkImg_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = armkidd_interfaces__srv__MarkImg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = armkidd_interfaces__srv__MarkImg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__x1[] = "x1";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__y1[] = "y1";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__x2[] = "x2";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__y2[] = "y2";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__choke_x[] = "choke_x";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__choke_y[] = "choke_y";
static char armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__is_valid[] = "is_valid";

static rosidl_runtime_c__type_description__Field armkidd_interfaces__srv__MarkImg_Request__FIELDS[] = {
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__x1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__y1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__x2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__y2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__choke_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__choke_y, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Request__FIELD_NAME__is_valid, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__srv__MarkImg_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
      {armkidd_interfaces__srv__MarkImg_Request__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char armkidd_interfaces__srv__MarkImg_Response__FIELD_NAME__image[] = "image";

static rosidl_runtime_c__type_description__Field armkidd_interfaces__srv__MarkImg_Response__FIELDS[] = {
  {
    {armkidd_interfaces__srv__MarkImg_Response__FIELD_NAME__image, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription armkidd_interfaces__srv__MarkImg_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__srv__MarkImg_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
      {armkidd_interfaces__srv__MarkImg_Response__FIELDS, 1, 1},
    },
    {armkidd_interfaces__srv__MarkImg_Response__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__info[] = "info";
static char armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__request[] = "request";
static char armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field armkidd_interfaces__srv__MarkImg_Event__FIELDS[] = {
  {
    {armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription armkidd_interfaces__srv__MarkImg_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__srv__MarkImg_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {armkidd_interfaces__srv__MarkImg_Event__TYPE_NAME, 36, 36},
      {armkidd_interfaces__srv__MarkImg_Event__FIELDS, 3, 3},
    },
    {armkidd_interfaces__srv__MarkImg_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = armkidd_interfaces__srv__MarkImg_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = armkidd_interfaces__srv__MarkImg_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int16 x1\n"
  "int16 y1\n"
  "int16 x2\n"
  "int16 y2\n"
  "int16 choke_x\n"
  "int16 choke_y\n"
  "bool is_valid\n"
  "---\n"
  "std_msgs/ByteMultiArray image";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__srv__MarkImg__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {armkidd_interfaces__srv__MarkImg__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 111, 111},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__srv__MarkImg_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {armkidd_interfaces__srv__MarkImg_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__srv__MarkImg_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {armkidd_interfaces__srv__MarkImg_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__srv__MarkImg_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {armkidd_interfaces__srv__MarkImg_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__srv__MarkImg__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *armkidd_interfaces__srv__MarkImg__get_individual_type_description_source(NULL),
    sources[1] = *armkidd_interfaces__srv__MarkImg_Event__get_individual_type_description_source(NULL);
    sources[2] = *armkidd_interfaces__srv__MarkImg_Request__get_individual_type_description_source(NULL);
    sources[3] = *armkidd_interfaces__srv__MarkImg_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[6] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__srv__MarkImg_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *armkidd_interfaces__srv__MarkImg_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__srv__MarkImg_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *armkidd_interfaces__srv__MarkImg_Response__get_individual_type_description_source(NULL),
    sources[1] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__srv__MarkImg_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *armkidd_interfaces__srv__MarkImg_Event__get_individual_type_description_source(NULL),
    sources[1] = *armkidd_interfaces__srv__MarkImg_Request__get_individual_type_description_source(NULL);
    sources[2] = *armkidd_interfaces__srv__MarkImg_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[6] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
