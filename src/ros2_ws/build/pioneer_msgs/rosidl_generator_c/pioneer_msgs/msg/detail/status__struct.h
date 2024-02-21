// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pioneer_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__STATUS__STRUCT_H_
#define PIONEER_MSGS__MSG__DETAIL__STATUS__STRUCT_H_

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
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Status in the package pioneer_msgs.
typedef struct pioneer_msgs__msg__Status
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String status;
} pioneer_msgs__msg__Status;

// Struct for a sequence of pioneer_msgs__msg__Status.
typedef struct pioneer_msgs__msg__Status__Sequence
{
  pioneer_msgs__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pioneer_msgs__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIONEER_MSGS__MSG__DETAIL__STATUS__STRUCT_H_
