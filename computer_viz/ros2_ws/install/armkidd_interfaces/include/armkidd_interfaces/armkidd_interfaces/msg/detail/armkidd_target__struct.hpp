// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armkidd_interfaces:msg/ArmkiddTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/msg/armkidd_target.hpp"


#ifndef ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__STRUCT_HPP_
#define ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armkidd_interfaces__msg__ArmkiddTarget __attribute__((deprecated))
#else
# define DEPRECATED__armkidd_interfaces__msg__ArmkiddTarget __declspec(deprecated)
#endif

namespace armkidd_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmkiddTarget_
{
  using Type = ArmkiddTarget_<ContainerAllocator>;

  explicit ArmkiddTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_x = 0.0f;
      this->target_y = 0.0f;
      this->depth = 0.0f;
      this->width = 0.0f;
      this->height = 0.0f;
    }
  }

  explicit ArmkiddTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_x = 0.0f;
      this->target_y = 0.0f;
      this->depth = 0.0f;
      this->width = 0.0f;
      this->height = 0.0f;
    }
  }

  // field types and members
  using _target_x_type =
    float;
  _target_x_type target_x;
  using _target_y_type =
    float;
  _target_y_type target_y;
  using _depth_type =
    float;
  _depth_type depth;
  using _width_type =
    float;
  _width_type width;
  using _height_type =
    float;
  _height_type height;

  // setters for named parameter idiom
  Type & set__target_x(
    const float & _arg)
  {
    this->target_x = _arg;
    return *this;
  }
  Type & set__target_y(
    const float & _arg)
  {
    this->target_y = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const float & _arg)
  {
    this->height = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armkidd_interfaces__msg__ArmkiddTarget
    std::shared_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armkidd_interfaces__msg__ArmkiddTarget
    std::shared_ptr<armkidd_interfaces::msg::ArmkiddTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmkiddTarget_ & other) const
  {
    if (this->target_x != other.target_x) {
      return false;
    }
    if (this->target_y != other.target_y) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmkiddTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmkiddTarget_

// alias to use template instance with default allocator
using ArmkiddTarget =
  armkidd_interfaces::msg::ArmkiddTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace armkidd_interfaces

#endif  // ARMKIDD_INTERFACES__MSG__DETAIL__ARMKIDD_TARGET__STRUCT_HPP_
