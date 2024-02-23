// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pioneer_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_
#define PIONEER_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pioneer_msgs/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pioneer_msgs
{

namespace msg
{

namespace builder
{

class Init_Status_status
{
public:
  explicit Init_Status_status(::pioneer_msgs::msg::Status & msg)
  : msg_(msg)
  {}
  ::pioneer_msgs::msg::Status status(::pioneer_msgs::msg::Status::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pioneer_msgs::msg::Status msg_;
};

class Init_Status_current_state
{
public:
  explicit Init_Status_current_state(::pioneer_msgs::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_status current_state(::pioneer_msgs::msg::Status::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return Init_Status_status(msg_);
  }

private:
  ::pioneer_msgs::msg::Status msg_;
};

class Init_Status_header
{
public:
  Init_Status_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_current_state header(::pioneer_msgs::msg::Status::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Status_current_state(msg_);
  }

private:
  ::pioneer_msgs::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pioneer_msgs::msg::Status>()
{
  return pioneer_msgs::msg::builder::Init_Status_header();
}

}  // namespace pioneer_msgs

#endif  // PIONEER_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_
