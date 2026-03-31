// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armkidd_interfaces:msg/ArmkiddTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/armkidd_target.hpp"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__BUILDER_HPP_
#define ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armkidd_interfaces/msg/detail/armkidd_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armkidd_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmkiddTarget_height
{
public:
  explicit Init_ArmkiddTarget_height(::armkidd_interfaces::msg::ArmkiddTarget & msg)
  : msg_(msg)
  {}
  ::armkidd_interfaces::msg::ArmkiddTarget height(::armkidd_interfaces::msg::ArmkiddTarget::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armkidd_interfaces::msg::ArmkiddTarget msg_;
};

class Init_ArmkiddTarget_width
{
public:
  explicit Init_ArmkiddTarget_width(::armkidd_interfaces::msg::ArmkiddTarget & msg)
  : msg_(msg)
  {}
  Init_ArmkiddTarget_height width(::armkidd_interfaces::msg::ArmkiddTarget::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ArmkiddTarget_height(msg_);
  }

private:
  ::armkidd_interfaces::msg::ArmkiddTarget msg_;
};

class Init_ArmkiddTarget_depth
{
public:
  explicit Init_ArmkiddTarget_depth(::armkidd_interfaces::msg::ArmkiddTarget & msg)
  : msg_(msg)
  {}
  Init_ArmkiddTarget_width depth(::armkidd_interfaces::msg::ArmkiddTarget::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_ArmkiddTarget_width(msg_);
  }

private:
  ::armkidd_interfaces::msg::ArmkiddTarget msg_;
};

class Init_ArmkiddTarget_target_y
{
public:
  explicit Init_ArmkiddTarget_target_y(::armkidd_interfaces::msg::ArmkiddTarget & msg)
  : msg_(msg)
  {}
  Init_ArmkiddTarget_depth target_y(::armkidd_interfaces::msg::ArmkiddTarget::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return Init_ArmkiddTarget_depth(msg_);
  }

private:
  ::armkidd_interfaces::msg::ArmkiddTarget msg_;
};

class Init_ArmkiddTarget_target_x
{
public:
  Init_ArmkiddTarget_target_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmkiddTarget_target_y target_x(::armkidd_interfaces::msg::ArmkiddTarget::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_ArmkiddTarget_target_y(msg_);
  }

private:
  ::armkidd_interfaces::msg::ArmkiddTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armkidd_interfaces::msg::ArmkiddTarget>()
{
  return armkidd_interfaces::msg::builder::Init_ArmkiddTarget_target_x();
}

}  // namespace armkidd_interfaces

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__BUILDER_HPP_
