// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/world_target.hpp"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__TRAITS_HPP_
#define ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armkidd_interfaces/msg/detail/world_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armkidd_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WorldTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_x
  {
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << ", ";
  }

  // member: target_y
  {
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
    out << ", ";
  }

  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WorldTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << "\n";
  }

  // member: target_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
    out << "\n";
  }

  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WorldTarget & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace armkidd_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armkidd_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armkidd_interfaces::msg::WorldTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  armkidd_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armkidd_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const armkidd_interfaces::msg::WorldTarget & msg)
{
  return armkidd_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<armkidd_interfaces::msg::WorldTarget>()
{
  return "armkidd_interfaces::msg::WorldTarget";
}

template<>
inline const char * name<armkidd_interfaces::msg::WorldTarget>()
{
  return "armkidd_interfaces/msg/WorldTarget";
}

template<>
struct has_fixed_size<armkidd_interfaces::msg::WorldTarget>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<armkidd_interfaces::msg::WorldTarget>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<armkidd_interfaces::msg::WorldTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__TRAITS_HPP_
