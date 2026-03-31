// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/srv/mark_img.hpp"


#ifndef ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_HPP_
#define ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Request __attribute__((deprecated))
#else
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Request __declspec(deprecated)
#endif

namespace armkidd_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MarkImg_Request_
{
  using Type = MarkImg_Request_<ContainerAllocator>;

  explicit MarkImg_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x1 = 0;
      this->y1 = 0;
      this->x2 = 0;
      this->y2 = 0;
      this->choke_x = 0;
      this->choke_y = 0;
      this->is_valid = false;
    }
  }

  explicit MarkImg_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x1 = 0;
      this->y1 = 0;
      this->x2 = 0;
      this->y2 = 0;
      this->choke_x = 0;
      this->choke_y = 0;
      this->is_valid = false;
    }
  }

  // field types and members
  using _x1_type =
    int16_t;
  _x1_type x1;
  using _y1_type =
    int16_t;
  _y1_type y1;
  using _x2_type =
    int16_t;
  _x2_type x2;
  using _y2_type =
    int16_t;
  _y2_type y2;
  using _choke_x_type =
    int16_t;
  _choke_x_type choke_x;
  using _choke_y_type =
    int16_t;
  _choke_y_type choke_y;
  using _is_valid_type =
    bool;
  _is_valid_type is_valid;

  // setters for named parameter idiom
  Type & set__x1(
    const int16_t & _arg)
  {
    this->x1 = _arg;
    return *this;
  }
  Type & set__y1(
    const int16_t & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__x2(
    const int16_t & _arg)
  {
    this->x2 = _arg;
    return *this;
  }
  Type & set__y2(
    const int16_t & _arg)
  {
    this->y2 = _arg;
    return *this;
  }
  Type & set__choke_x(
    const int16_t & _arg)
  {
    this->choke_x = _arg;
    return *this;
  }
  Type & set__choke_y(
    const int16_t & _arg)
  {
    this->choke_y = _arg;
    return *this;
  }
  Type & set__is_valid(
    const bool & _arg)
  {
    this->is_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Request
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Request
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MarkImg_Request_ & other) const
  {
    if (this->x1 != other.x1) {
      return false;
    }
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->x2 != other.x2) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    if (this->choke_x != other.choke_x) {
      return false;
    }
    if (this->choke_y != other.choke_y) {
      return false;
    }
    if (this->is_valid != other.is_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const MarkImg_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MarkImg_Request_

// alias to use template instance with default allocator
using MarkImg_Request =
  armkidd_interfaces::srv::MarkImg_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace armkidd_interfaces


// Include directives for member types
// Member 'image'
#include "std_msgs/msg/detail/byte_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Response __attribute__((deprecated))
#else
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Response __declspec(deprecated)
#endif

namespace armkidd_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MarkImg_Response_
{
  using Type = MarkImg_Response_<ContainerAllocator>;

  explicit MarkImg_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    (void)_init;
  }

  explicit MarkImg_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    std_msgs::msg::ByteMultiArray_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const std_msgs::msg::ByteMultiArray_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Response
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Response
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MarkImg_Response_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const MarkImg_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MarkImg_Response_

// alias to use template instance with default allocator
using MarkImg_Response =
  armkidd_interfaces::srv::MarkImg_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace armkidd_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Event __attribute__((deprecated))
#else
# define DEPRECATED__armkidd_interfaces__srv__MarkImg_Event __declspec(deprecated)
#endif

namespace armkidd_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MarkImg_Event_
{
  using Type = MarkImg_Event_<ContainerAllocator>;

  explicit MarkImg_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit MarkImg_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<armkidd_interfaces::srv::MarkImg_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<armkidd_interfaces::srv::MarkImg_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Event
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armkidd_interfaces__srv__MarkImg_Event
    std::shared_ptr<armkidd_interfaces::srv::MarkImg_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MarkImg_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const MarkImg_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MarkImg_Event_

// alias to use template instance with default allocator
using MarkImg_Event =
  armkidd_interfaces::srv::MarkImg_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace armkidd_interfaces

namespace armkidd_interfaces
{

namespace srv
{

struct MarkImg
{
  using Request = armkidd_interfaces::srv::MarkImg_Request;
  using Response = armkidd_interfaces::srv::MarkImg_Response;
  using Event = armkidd_interfaces::srv::MarkImg_Event;
};

}  // namespace srv

}  // namespace armkidd_interfaces

#endif  // ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__STRUCT_HPP_
