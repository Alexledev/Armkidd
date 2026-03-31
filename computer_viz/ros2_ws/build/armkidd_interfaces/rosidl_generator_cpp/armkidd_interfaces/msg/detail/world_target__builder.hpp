// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/world_target.hpp"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__BUILDER_HPP_
#define ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armkidd_interfaces/msg/detail/world_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armkidd_interfaces
{

namespace msg
{

namespace builder
{

class Init_WorldTarget_height
{
public:
  explicit Init_WorldTarget_height(::armkidd_interfaces::msg::WorldTarget & msg)
  : msg_(msg)
  {}
  ::armkidd_interfaces::msg::WorldTarget height(::armkidd_interfaces::msg::WorldTarget::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armkidd_interfaces::msg::WorldTarget msg_;
};

class Init_WorldTarget_width
{
public:
  explicit Init_WorldTarget_width(::armkidd_interfaces::msg::WorldTarget & msg)
  : msg_(msg)
  {}
  Init_WorldTarget_height width(::armkidd_interfaces::msg::WorldTarget::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_WorldTarget_height(msg_);
  }

private:
  ::armkidd_interfaces::msg::WorldTarget msg_;
};

class Init_WorldTarget_depth
{
public:
  explicit Init_WorldTarget_depth(::armkidd_interfaces::msg::WorldTarget & msg)
  : msg_(msg)
  {}
  Init_WorldTarget_width depth(::armkidd_interfaces::msg::WorldTarget::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_WorldTarget_width(msg_);
  }

private:
  ::armkidd_interfaces::msg::WorldTarget msg_;
};

class Init_WorldTarget_target_y
{
public:
  explicit Init_WorldTarget_target_y(::armkidd_interfaces::msg::WorldTarget & msg)
  : msg_(msg)
  {}
  Init_WorldTarget_depth target_y(::armkidd_interfaces::msg::WorldTarget::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return Init_WorldTarget_depth(msg_);
  }

private:
  ::armkidd_interfaces::msg::WorldTarget msg_;
};

class Init_WorldTarget_target_x
{
public:
  Init_WorldTarget_target_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldTarget_target_y target_x(::armkidd_interfaces::msg::WorldTarget::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_WorldTarget_target_y(msg_);
  }

private:
  ::armkidd_interfaces::msg::WorldTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armkidd_interfaces::msg::WorldTarget>()
{
  return armkidd_interfaces::msg::builder::Init_WorldTarget_target_x();
}

}  // namespace armkidd_interfaces

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__WORLD_TARGET__BUILDER_HPP_
