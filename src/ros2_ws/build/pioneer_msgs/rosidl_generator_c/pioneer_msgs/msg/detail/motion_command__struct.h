// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_H_
#define PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/MotionCommand in the package pioneer_msgs.
typedef struct pioneer_msgs__msg__MotionCommand
{
  std_msgs__msg__Header header;
  bool turn_mode;
  geometry_msgs__msg__Vector3 direction;
  float distance;
  float time;
} pioneer_msgs__msg__MotionCommand;

// Struct for a sequence of pioneer_msgs__msg__MotionCommand.
typedef struct pioneer_msgs__msg__MotionCommand__Sequence
{
  pioneer_msgs__msg__MotionCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pioneer_msgs__msg__MotionCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIONEER_MSGS__MSG__DETAIL__MOTION_COMMAND__STRUCT_H_
