// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/vehicle_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__VehicleCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x0a, 0xb5, 0x37, 0x80, 0x7e, 0x2e, 0x20,
      0xe0, 0x48, 0x26, 0x63, 0x3e, 0xa2, 0xc5, 0x2e,
      0x54, 0x31, 0xbe, 0xa8, 0xeb, 0x01, 0x87, 0x15,
      0x2f, 0xf2, 0x3b, 0xd0, 0x7f, 0x1d, 0xd3, 0x0b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__VehicleCommand__TYPE_NAME[] = "px4_msgs/msg/VehicleCommand";

// Define type names, field names, and default values
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param1[] = "param1";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param2[] = "param2";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param3[] = "param3";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param4[] = "param4";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param5[] = "param5";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param6[] = "param6";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param7[] = "param7";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__command[] = "command";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__target_system[] = "target_system";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__target_component[] = "target_component";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__source_system[] = "source_system";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__source_component[] = "source_component";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__confirmation[] = "confirmation";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__from_external[] = "from_external";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__VehicleCommand__FIELDS[] = {
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param4, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param5, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param6, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param7, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__target_system, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__target_component, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__source_system, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__source_component, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__confirmation, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__from_external, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__VehicleCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__VehicleCommand__TYPE_NAME, 27, 27},
      {px4_msgs__msg__VehicleCommand__FIELDS, 15, 15},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "VehicleCommand request\n"
  "---\n"
  "VehicleCommandAck reply";

static char srv_encoding[] = "srv";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__VehicleCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__VehicleCommand__TYPE_NAME, 27, 27},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 51, 51},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__VehicleCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__VehicleCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
