// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/Mission.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/mission__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__Mission__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9b, 0xe7, 0xf6, 0x98, 0x55, 0xaa, 0xa5, 0x08,
      0x53, 0xc6, 0x4b, 0xa8, 0xb9, 0xa4, 0xb3, 0x24,
      0x24, 0x4e, 0xe9, 0x46, 0xab, 0xb7, 0x97, 0xa8,
      0x7e, 0x8d, 0x76, 0x61, 0x0e, 0xb5, 0x5b, 0x4d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__Mission__TYPE_NAME[] = "px4_msgs/msg/Mission";

// Define type names, field names, and default values
static char px4_msgs__msg__Mission__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__Mission__FIELD_NAME__dataman_id[] = "dataman_id";
static char px4_msgs__msg__Mission__FIELD_NAME__count[] = "count";
static char px4_msgs__msg__Mission__FIELD_NAME__current_seq[] = "current_seq";
static char px4_msgs__msg__Mission__FIELD_NAME__land_start_index[] = "land_start_index";
static char px4_msgs__msg__Mission__FIELD_NAME__land_index[] = "land_index";
static char px4_msgs__msg__Mission__FIELD_NAME__mission_update_counter[] = "mission_update_counter";
static char px4_msgs__msg__Mission__FIELD_NAME__geofence_update_counter[] = "geofence_update_counter";
static char px4_msgs__msg__Mission__FIELD_NAME__safe_points_update_counter[] = "safe_points_update_counter";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__Mission__FIELDS[] = {
  {
    {px4_msgs__msg__Mission__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__dataman_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__count, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__current_seq, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__land_start_index, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__land_index, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__mission_update_counter, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__geofence_update_counter, 23, 23},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__Mission__FIELD_NAME__safe_points_update_counter, 26, 26},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__Mission__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__Mission__TYPE_NAME, 20, 20},
      {px4_msgs__msg__Mission__FIELDS, 9, 9},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 timestamp\\t# time since system start (microseconds)\n"
  "uint8 dataman_id\\t# default 0, there are two offboard storage places in the dataman: 0 or 1\n"
  "\n"
  "uint16 count\\t\\t# count of the missions stored in the dataman\n"
  "int32 current_seq\\t# default -1, start at the one changed latest\n"
  "\n"
  "int32 land_start_index  # Index of the land start marker, if unavailable index of the land item, -1 otherwise\n"
  "int32 land_index \\t# Index of the land item, -1 otherwise\n"
  "\n"
  "uint16 mission_update_counter # indicates updates to the mission, reload from dataman if increased\n"
  "uint16 geofence_update_counter # indicates updates to the geofence, reload from dataman if increased\n"
  "uint16 safe_points_update_counter # indicates updates to the safe points, reload from dataman if increased";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__Mission__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__Mission__TYPE_NAME, 20, 20},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 750, 750},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__Mission__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__Mission__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
