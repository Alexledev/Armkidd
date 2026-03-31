// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from armkidd_interfaces:msg/ArmkiddTarget.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "armkidd_interfaces/msg/detail/armkidd_target__functions.h"
#include "armkidd_interfaces/msg/detail/armkidd_target__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace armkidd_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ArmkiddTarget_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) armkidd_interfaces::msg::ArmkiddTarget(_init);
}

void ArmkiddTarget_fini_function(void * message_memory)
{
  auto typed_message = static_cast<armkidd_interfaces::msg::ArmkiddTarget *>(message_memory);
  typed_message->~ArmkiddTarget();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ArmkiddTarget_message_member_array[5] = {
  {
    "target_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armkidd_interfaces::msg::ArmkiddTarget, target_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armkidd_interfaces::msg::ArmkiddTarget, target_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "depth",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armkidd_interfaces::msg::ArmkiddTarget, depth),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "width",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armkidd_interfaces::msg::ArmkiddTarget, width),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "height",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armkidd_interfaces::msg::ArmkiddTarget, height),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ArmkiddTarget_message_members = {
  "armkidd_interfaces::msg",  // message namespace
  "ArmkiddTarget",  // message name
  5,  // number of fields
  sizeof(armkidd_interfaces::msg::ArmkiddTarget),
  false,  // has_any_key_member_
  ArmkiddTarget_message_member_array,  // message members
  ArmkiddTarget_init_function,  // function to initialize message memory (memory has to be allocated)
  ArmkiddTarget_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ArmkiddTarget_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ArmkiddTarget_message_members,
  get_message_typesupport_handle_function,
  &armkidd_interfaces__msg__ArmkiddTarget__get_type_hash,
  &armkidd_interfaces__msg__ArmkiddTarget__get_type_description,
  &armkidd_interfaces__msg__ArmkiddTarget__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace armkidd_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<armkidd_interfaces::msg::ArmkiddTarget>()
{
  return &::armkidd_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmkiddTarget_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armkidd_interfaces, msg, ArmkiddTarget)() {
  return &::armkidd_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmkiddTarget_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
