// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/srv/mark_img.hpp"


#ifndef ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__TRAITS_HPP_
#define ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armkidd_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MarkImg_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: x2
  {
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << ", ";
  }

  // member: choke_x
  {
    out << "choke_x: ";
    rosidl_generator_traits::value_to_yaml(msg.choke_x, out);
    out << ", ";
  }

  // member: choke_y
  {
    out << "choke_y: ";
    rosidl_generator_traits::value_to_yaml(msg.choke_y, out);
    out << ", ";
  }

  // member: is_valid
  {
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkImg_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }

  // member: choke_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "choke_x: ";
    rosidl_generator_traits::value_to_yaml(msg.choke_x, out);
    out << "\n";
  }

  // member: choke_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "choke_y: ";
    rosidl_generator_traits::value_to_yaml(msg.choke_y, out);
    out << "\n";
  }

  // member: is_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkImg_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armkidd_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armkidd_interfaces::srv::MarkImg_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  armkidd_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armkidd_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const armkidd_interfaces::srv::MarkImg_Request & msg)
{
  return armkidd_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<armkidd_interfaces::srv::MarkImg_Request>()
{
  return "armkidd_interfaces::srv::MarkImg_Request";
}

template<>
inline const char * name<armkidd_interfaces::srv::MarkImg_Request>()
{
  return "armkidd_interfaces/srv/MarkImg_Request";
}

template<>
struct has_fixed_size<armkidd_interfaces::srv::MarkImg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<armkidd_interfaces::srv::MarkImg_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<armkidd_interfaces::srv::MarkImg_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'image'
#include "std_msgs/msg/detail/byte_multi_array__traits.hpp"

namespace armkidd_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MarkImg_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkImg_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkImg_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armkidd_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armkidd_interfaces::srv::MarkImg_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  armkidd_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armkidd_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const armkidd_interfaces::srv::MarkImg_Response & msg)
{
  return armkidd_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<armkidd_interfaces::srv::MarkImg_Response>()
{
  return "armkidd_interfaces::srv::MarkImg_Response";
}

template<>
inline const char * name<armkidd_interfaces::srv::MarkImg_Response>()
{
  return "armkidd_interfaces/srv/MarkImg_Response";
}

template<>
struct has_fixed_size<armkidd_interfaces::srv::MarkImg_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::ByteMultiArray>::value> {};

template<>
struct has_bounded_size<armkidd_interfaces::srv::MarkImg_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::ByteMultiArray>::value> {};

template<>
struct is_message<armkidd_interfaces::srv::MarkImg_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace armkidd_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MarkImg_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkImg_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkImg_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armkidd_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armkidd_interfaces::srv::MarkImg_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  armkidd_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armkidd_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const armkidd_interfaces::srv::MarkImg_Event & msg)
{
  return armkidd_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<armkidd_interfaces::srv::MarkImg_Event>()
{
  return "armkidd_interfaces::srv::MarkImg_Event";
}

template<>
inline const char * name<armkidd_interfaces::srv::MarkImg_Event>()
{
  return "armkidd_interfaces/srv/MarkImg_Event";
}

template<>
struct has_fixed_size<armkidd_interfaces::srv::MarkImg_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<armkidd_interfaces::srv::MarkImg_Event>
  : std::integral_constant<bool, has_bounded_size<armkidd_interfaces::srv::MarkImg_Request>::value && has_bounded_size<armkidd_interfaces::srv::MarkImg_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<armkidd_interfaces::srv::MarkImg_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<armkidd_interfaces::srv::MarkImg>()
{
  return "armkidd_interfaces::srv::MarkImg";
}

template<>
inline const char * name<armkidd_interfaces::srv::MarkImg>()
{
  return "armkidd_interfaces/srv/MarkImg";
}

template<>
struct has_fixed_size<armkidd_interfaces::srv::MarkImg>
  : std::integral_constant<
    bool,
    has_fixed_size<armkidd_interfaces::srv::MarkImg_Request>::value &&
    has_fixed_size<armkidd_interfaces::srv::MarkImg_Response>::value
  >
{
};

template<>
struct has_bounded_size<armkidd_interfaces::srv::MarkImg>
  : std::integral_constant<
    bool,
    has_bounded_size<armkidd_interfaces::srv::MarkImg_Request>::value &&
    has_bounded_size<armkidd_interfaces::srv::MarkImg_Response>::value
  >
{
};

template<>
struct is_service<armkidd_interfaces::srv::MarkImg>
  : std::true_type
{
};

template<>
struct is_service_request<armkidd_interfaces::srv::MarkImg_Request>
  : std::true_type
{
};

template<>
struct is_service_response<armkidd_interfaces::srv::MarkImg_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__TRAITS_HPP_
