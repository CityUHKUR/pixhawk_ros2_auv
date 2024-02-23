// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pioneer_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_
#define PIONEER_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pioneer_msgs/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pioneer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Status & msg,
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

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status & msg,
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

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status & msg, bool use_flow_style = false)
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
  const pioneer_msgs::msg::Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  pioneer_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pioneer_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pioneer_msgs::msg::Status & msg)
{
  return pioneer_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pioneer_msgs::msg::Status>()
{
  return "pioneer_msgs::msg::Status";
}

template<>
inline const char * name<pioneer_msgs::msg::Status>()
{
  return "pioneer_msgs/msg/Status";
}

template<>
struct has_fixed_size<pioneer_msgs::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pioneer_msgs::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pioneer_msgs::msg::Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PIONEER_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_
