// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_HPP_
#define PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pioneer_msgs__msg__MotionCommand __attribute__((deprecated))
#else
# define DEPRECATED__pioneer_msgs__msg__MotionCommand __declspec(deprecated)
#endif

namespace pioneer_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotionCommand_
{
  using Type = MotionCommand_<ContainerAllocator>;

  explicit MotionCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    direction(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turn_mode = false;
      this->distance = 0.0f;
      this->time = 0.0f;
    }
  }

  explicit MotionCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    direction(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turn_mode = false;
      this->distance = 0.0f;
      this->time = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _turn_mode_type =
    bool;
  _turn_mode_type turn_mode;
  using _direction_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _direction_type direction;
  using _distance_type =
    float;
  _distance_type distance;
  using _time_type =
    float;
  _time_type time;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__turn_mode(
    const bool & _arg)
  {
    this->turn_mode = _arg;
    return *this;
  }
  Type & set__direction(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pioneer_msgs::msg::MotionCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const pioneer_msgs::msg::MotionCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pioneer_msgs::msg::MotionCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pioneer_msgs::msg::MotionCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pioneer_msgs__msg__MotionCommand
    std::shared_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pioneer_msgs__msg__MotionCommand
    std::shared_ptr<pioneer_msgs::msg::MotionCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotionCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->turn_mode != other.turn_mode) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotionCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotionCommand_

// alias to use template instance with default allocator
using MotionCommand =
  pioneer_msgs::msg::MotionCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pioneer_msgs

#endif  // PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_HPP_
