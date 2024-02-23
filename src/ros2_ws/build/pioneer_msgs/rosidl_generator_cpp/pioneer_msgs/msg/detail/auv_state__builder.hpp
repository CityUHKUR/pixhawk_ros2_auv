// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pioneer_msgs:msg/AUVState.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__AUV_STATE__BUILDER_HPP_
#define PIONEER_MSGS__MSG__DETAIL__AUV_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pioneer_msgs/msg/detail/auv_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pioneer_msgs
{

namespace msg
{

namespace builder
{

class Init_AUVState_current_control
{
public:
  explicit Init_AUVState_current_control(::pioneer_msgs::msg::AUVState & msg)
  : msg_(msg)
  {}
  ::pioneer_msgs::msg::AUVState current_control(::pioneer_msgs::msg::AUVState::_current_control_type arg)
  {
    msg_.current_control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pioneer_msgs::msg::AUVState msg_;
};

class Init_AUVState_current_state
{
public:
  explicit Init_AUVState_current_state(::pioneer_msgs::msg::AUVState & msg)
  : msg_(msg)
  {}
  Init_AUVState_current_control current_state(::pioneer_msgs::msg::AUVState::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return Init_AUVState_current_control(msg_);
  }

private:
  ::pioneer_msgs::msg::AUVState msg_;
};

class Init_AUVState_header
{
public:
  Init_AUVState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AUVState_current_state header(::pioneer_msgs::msg::AUVState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AUVState_current_state(msg_);
  }

private:
  ::pioneer_msgs::msg::AUVState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pioneer_msgs::msg::AUVState>()
{
  return pioneer_msgs::msg::builder::Init_AUVState_header();
}

}  // namespace pioneer_msgs

#endif  // PIONEER_MSGS__MSG__DETAIL__AUV_STATE__BUILDER_HPP_
