// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pioneer_msgs:msg/AUVState.idl
// generated code does not contain a copyright notice

#ifndef PIONEER_MSGS__MSG__DETAIL__AUV_STATE__STRUCT_H_
#define PIONEER_MSGS__MSG__DETAIL__AUV_STATE__STRUCT_H_

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
// Member 'current_state'
// Member 'current_control'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AUVState in the package pioneer_msgs.
/**
  * Message of current_state of AUV
  * Only publish by state machine
 */
typedef struct pioneer_msgs__msg__AUVState
{
  std_msgs__msg__Header header;
  /// State Name Example
  /// "state_navigate_task1"
  /// "recover_mode"
  /// Detail refer to state machine repo readme
  rosidl_runtime_c__String current_state;
  /// The node responsible for control AUV, reference only
  rosidl_runtime_c__String current_control;
} pioneer_msgs__msg__AUVState;

// Struct for a sequence of pioneer_msgs__msg__AUVState.
typedef struct pioneer_msgs__msg__AUVState__Sequence
{
  pioneer_msgs__msg__AUVState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pioneer_msgs__msg__AUVState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PIONEER_MSGS__MSG__DETAIL__AUV_STATE__STRUCT_H_
