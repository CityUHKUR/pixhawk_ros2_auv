// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pioneer_msgs/msg/detail/motion_command__rosidl_typesupport_introspection_c.h"
#include "pioneer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pioneer_msgs/msg/detail/motion_command__functions.h"
#include "pioneer_msgs/msg/detail/motion_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `direction`
#include "geometry_msgs/msg/vector3.h"
// Member `direction`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pioneer_msgs__msg__MotionCommand__init(message_memory);
}

void pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_fini_function(void * message_memory)
{
  pioneer_msgs__msg__MotionCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pioneer_msgs__msg__MotionCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "turn_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pioneer_msgs__msg__MotionCommand, turn_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pioneer_msgs__msg__MotionCommand, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pioneer_msgs__msg__MotionCommand, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pioneer_msgs__msg__MotionCommand, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_members = {
  "pioneer_msgs__msg",  // message namespace
  "MotionCommand",  // message name
  5,  // number of fields
  sizeof(pioneer_msgs__msg__MotionCommand),
  pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_member_array,  // message members
  pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_type_support_handle = {
  0,
  &pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pioneer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pioneer_msgs, msg, MotionCommand)() {
  pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_type_support_handle.typesupport_identifier) {
    pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pioneer_msgs__msg__MotionCommand__rosidl_typesupport_introspection_c__MotionCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
