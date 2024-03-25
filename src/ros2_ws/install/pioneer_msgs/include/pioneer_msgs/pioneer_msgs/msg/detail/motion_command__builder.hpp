// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__BUILDER_HPP_
#define PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pioneer_msgs/msg/detail/motion_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pioneer_msgs
{

namespace msg
{

namespace builder
{

class Init_MotionCommand_time
{
public:
  explicit Init_MotionCommand_time(::pioneer_msgs::msg::MotionCommand & msg)
  : msg_(msg)
  {}
  ::pioneer_msgs::msg::MotionCommand time(::pioneer_msgs::msg::MotionCommand::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pioneer_msgs::msg::MotionCommand msg_;
};

class Init_MotionCommand_distance
{
public:
  explicit Init_MotionCommand_distance(::pioneer_msgs::msg::MotionCommand & msg)
  : msg_(msg)
  {}
  Init_MotionCommand_time distance(::pioneer_msgs::msg::MotionCommand::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_MotionCommand_time(msg_);
  }

private:
  ::pioneer_msgs::msg::MotionCommand msg_;
};

class Init_MotionCommand_direction
{
public:
  explicit Init_MotionCommand_direction(::pioneer_msgs::msg::MotionCommand & msg)
  : msg_(msg)
  {}
  Init_MotionCommand_distance direction(::pioneer_msgs::msg::MotionCommand::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_MotionCommand_distance(msg_);
  }

private:
  ::pioneer_msgs::msg::MotionCommand msg_;
};

class Init_MotionCommand_turn_mode
{
public:
  explicit Init_MotionCommand_turn_mode(::pioneer_msgs::msg::MotionCommand & msg)
  : msg_(msg)
  {}
  Init_MotionCommand_direction turn_mode(::pioneer_msgs::msg::MotionCommand::_turn_mode_type arg)
  {
    msg_.turn_mode = std::move(arg);
    return Init_MotionCommand_direction(msg_);
  }

private:
  ::pioneer_msgs::msg::MotionCommand msg_;
};

class Init_MotionCommand_header
{
public:
  Init_MotionCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotionCommand_turn_mode header(::pioneer_msgs::msg::MotionCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotionCommand_turn_mode(msg_);
  }

private:
  ::pioneer_msgs::msg::MotionCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pioneer_msgs::msg::MotionCommand>()
{
  return pioneer_msgs::msg::builder::Init_MotionCommand_header();
}

}  // namespace pioneer_msgs

#endif  // PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__BUILDER_HPP_
