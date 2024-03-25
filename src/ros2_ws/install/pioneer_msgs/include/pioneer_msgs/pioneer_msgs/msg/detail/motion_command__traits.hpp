// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__TRAITS_HPP_
#define PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pioneer_msgs/msg/detail/motion_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace pioneer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotionCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: turn_mode
  {
    out << "turn_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.turn_mode, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    to_flow_style_yaml(msg.direction, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: turn_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "turn_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.turn_mode, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction:\n";
    to_block_style_yaml(msg.direction, out, indentation + 2);
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotionCommand & msg, bool use_flow_style = false)
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

}  // namespace pioneer_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pioneer_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pioneer_msgs::msg::MotionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  pioneer_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pioneer_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pioneer_msgs::msg::MotionCommand & msg)
{
  return pioneer_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pioneer_msgs::msg::MotionCommand>()
{
  return "pioneer_msgs::msg::MotionCommand";
}

template<>
inline const char * name<pioneer_msgs::msg::MotionCommand>()
{
  return "pioneer_msgs/msg/MotionCommand";
}

template<>
struct has_fixed_size<pioneer_msgs::msg::MotionCommand>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pioneer_msgs::msg::MotionCommand>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pioneer_msgs::msg::MotionCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__TRAITS_HPP_
