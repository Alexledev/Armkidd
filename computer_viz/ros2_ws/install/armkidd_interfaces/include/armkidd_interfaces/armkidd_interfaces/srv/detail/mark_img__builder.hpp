// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "armkidd_interfaces/srv/mark_img.hpp"


#ifndef ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__BUILDER_HPP_
#define ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armkidd_interfaces
{

namespace srv
{

namespace builder
{

class Init_MarkImg_Request_is_valid
{
public:
  explicit Init_MarkImg_Request_is_valid(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  ::armkidd_interfaces::srv::MarkImg_Request is_valid(::armkidd_interfaces::srv::MarkImg_Request::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_choke_y
{
public:
  explicit Init_MarkImg_Request_choke_y(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Request_is_valid choke_y(::armkidd_interfaces::srv::MarkImg_Request::_choke_y_type arg)
  {
    msg_.choke_y = std::move(arg);
    return Init_MarkImg_Request_is_valid(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_choke_x
{
public:
  explicit Init_MarkImg_Request_choke_x(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Request_choke_y choke_x(::armkidd_interfaces::srv::MarkImg_Request::_choke_x_type arg)
  {
    msg_.choke_x = std::move(arg);
    return Init_MarkImg_Request_choke_y(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_y2
{
public:
  explicit Init_MarkImg_Request_y2(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Request_choke_x y2(::armkidd_interfaces::srv::MarkImg_Request::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return Init_MarkImg_Request_choke_x(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_x2
{
public:
  explicit Init_MarkImg_Request_x2(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Request_y2 x2(::armkidd_interfaces::srv::MarkImg_Request::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_MarkImg_Request_y2(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_y1
{
public:
  explicit Init_MarkImg_Request_y1(::armkidd_interfaces::srv::MarkImg_Request & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Request_x2 y1(::armkidd_interfaces::srv::MarkImg_Request::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_MarkImg_Request_x2(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

class Init_MarkImg_Request_x1
{
public:
  Init_MarkImg_Request_x1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkImg_Request_y1 x1(::armkidd_interfaces::srv::MarkImg_Request::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_MarkImg_Request_y1(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armkidd_interfaces::srv::MarkImg_Request>()
{
  return armkidd_interfaces::srv::builder::Init_MarkImg_Request_x1();
}

}  // namespace armkidd_interfaces


namespace armkidd_interfaces
{

namespace srv
{

namespace builder
{

class Init_MarkImg_Response_image
{
public:
  Init_MarkImg_Response_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::armkidd_interfaces::srv::MarkImg_Response image(::armkidd_interfaces::srv::MarkImg_Response::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armkidd_interfaces::srv::MarkImg_Response>()
{
  return armkidd_interfaces::srv::builder::Init_MarkImg_Response_image();
}

}  // namespace armkidd_interfaces


namespace armkidd_interfaces
{

namespace srv
{

namespace builder
{

class Init_MarkImg_Event_response
{
public:
  explicit Init_MarkImg_Event_response(::armkidd_interfaces::srv::MarkImg_Event & msg)
  : msg_(msg)
  {}
  ::armkidd_interfaces::srv::MarkImg_Event response(::armkidd_interfaces::srv::MarkImg_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Event msg_;
};

class Init_MarkImg_Event_request
{
public:
  explicit Init_MarkImg_Event_request(::armkidd_interfaces::srv::MarkImg_Event & msg)
  : msg_(msg)
  {}
  Init_MarkImg_Event_response request(::armkidd_interfaces::srv::MarkImg_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MarkImg_Event_response(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Event msg_;
};

class Init_MarkImg_Event_info
{
public:
  Init_MarkImg_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkImg_Event_request info(::armkidd_interfaces::srv::MarkImg_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MarkImg_Event_request(msg_);
  }

private:
  ::armkidd_interfaces::srv::MarkImg_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armkidd_interfaces::srv::MarkImg_Event>()
{
  return armkidd_interfaces::srv::builder::Init_MarkImg_Event_info();
}

}  // namespace armkidd_interfaces

#endif  // ARMKIDD_INTERFACES__SRV__DETAIL__MARK_IMG__BUILDER_HPP_
