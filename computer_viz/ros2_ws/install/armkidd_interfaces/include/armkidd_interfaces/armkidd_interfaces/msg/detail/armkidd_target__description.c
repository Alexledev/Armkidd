// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from armkidd_interfaces:msg/ArmkiddTarget.idl
// generated code does not contain a copyright notice

#include "armkidd_interfaces/msg/detail/armkidd_target__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_armkidd_interfaces
const rosidl_type_hash_t *
armkidd_interfaces__msg__ArmkiddTarget__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x69, 0x3f, 0x2a, 0x84, 0xc1, 0x75, 0x19, 0x71,
      0x7b, 0x81, 0xb3, 0x6d, 0xd1, 0x3d, 0xf9, 0x85,
      0x8d, 0xb6, 0x83, 0xe8, 0x0b, 0x6f, 0x38, 0x58,
      0xa2, 0xf6, 0x3c, 0xc3, 0xc3, 0x1c, 0xda, 0xe8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char armkidd_interfaces__msg__ArmkiddTarget__TYPE_NAME[] = "armkidd_interfaces/msg/ArmkiddTarget";

// Define type names, field names, and default values
static char armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__target_x[] = "target_x";
static char armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__target_y[] = "target_y";
static char armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__depth[] = "depth";
static char armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__width[] = "width";
static char armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__height[] = "height";

static rosidl_runtime_c__type_description__Field armkidd_interfaces__msg__ArmkiddTarget__FIELDS[] = {
  {
    {armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__target_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__target_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {armkidd_interfaces__msg__ArmkiddTarget__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
armkidd_interfaces__msg__ArmkiddTarget__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {armkidd_interfaces__msg__ArmkiddTarget__TYPE_NAME, 36, 36},
      {armkidd_interfaces__msg__ArmkiddTarget__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 target_x\n"
  "float32 target_y\n"
  "float32 depth\n"
  "float32 width\n"
  "float32 height";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
armkidd_interfaces__msg__ArmkiddTarget__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {armkidd_interfaces__msg__ArmkiddTarget__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 77, 77},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
armkidd_interfaces__msg__ArmkiddTarget__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *armkidd_interfaces__msg__ArmkiddTarget__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
