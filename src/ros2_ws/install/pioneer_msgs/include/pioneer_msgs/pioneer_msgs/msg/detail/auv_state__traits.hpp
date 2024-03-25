// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pioneer_msgs:msg/AUVState.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__AUV_STATE__TRAITS_HPP_
#define PIONEER_MSGS__MSG__DETAIL__AUV_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pioneer_msgs/msg/detail/auv_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pioneer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AUVState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: current_state
  {
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
    out << ", ";
  }

  // member: current_control
  {
    out << "current_control: ";
    rosidl_generator_traits::value_to_yaml(msg.current_control, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AUVState & msg,
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

  // member: current_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
    out << "\n";
  }

  // member: current_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_control: ";
    rosidl_generator_traits::value_to_yaml(msg.current_control, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AUVState & msg, bool use_flow_style = false)
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
  const pioneer_msgs::msg::AUVState & msg,
  std::ostream & out, size_t indentation = 0)
{
  pioneer_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pioneer_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pioneer_msgs::msg::AUVState & msg)
{
  return pioneer_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pioneer_msgs::msg::AUVState>()
{
  return "pioneer_msgs::msg::AUVState";
}

template<>
inline const char * name<pioneer_msgs::msg::AUVState>()
{
  return "pioneer_msgs/msg/AUVState";
}

template<>
struct has_fixed_size<pioneer_msgs::msg::AUVState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pioneer_msgs::msg::AUVState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pioneer_msgs::msg::AUVState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIONEER_MSGS__MSG__DETAIL__AUV_STATE__TRAITS_HPP_
