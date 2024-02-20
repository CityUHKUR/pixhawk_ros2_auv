// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/VehicleOpticalFlowVel.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/vehicle_optical_flow_vel__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__VehicleOpticalFlowVel__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfe, 0x44, 0x67, 0xa8, 0x48, 0x77, 0x8b, 0xdc,
      0x20, 0x05, 0x28, 0x9e, 0x5f, 0x86, 0x97, 0xd4,
      0xcb, 0xf4, 0xdc, 0xdf, 0xd2, 0xe0, 0x7b, 0xf8,
      0xc0, 0xb1, 0x6e, 0x65, 0x3d, 0xa0, 0xb7, 0xc5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__VehicleOpticalFlowVel__TYPE_NAME[] = "px4_msgs/msg/VehicleOpticalFlowVel";

// Define type names, field names, and default values
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__timestamp_sample[] = "timestamp_sample";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__vel_body[] = "vel_body";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__vel_ne[] = "vel_ne";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__flow_uncompensated_integral[] = "flow_uncompensated_integral";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__flow_compensated_integral[] = "flow_compensated_integral";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_rate[] = "gyro_rate";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_rate_integral[] = "gyro_rate_integral";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_bias[] = "gyro_bias";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__ref_gyro[] = "ref_gyro";
static char px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__meas_gyro[] = "meas_gyro";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__VehicleOpticalFlowVel__FIELDS[] = {
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__timestamp_sample, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__vel_body, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__vel_ne, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__flow_uncompensated_integral, 27, 27},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__flow_compensated_integral, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_rate, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_rate_integral, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__gyro_bias, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__ref_gyro, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOpticalFlowVel__FIELD_NAME__meas_gyro, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__VehicleOpticalFlowVel__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__VehicleOpticalFlowVel__TYPE_NAME, 34, 34},
      {px4_msgs__msg__VehicleOpticalFlowVel__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 timestamp                       # time since system start (microseconds)\n"
  "uint64 timestamp_sample                # the timestamp of the raw data (microseconds)\n"
  "\n"
  "float32[2] vel_body                    # velocity obtained from gyro-compensated and distance-scaled optical flow raw measurements in body frame(m/s)\n"
  "float32[2] vel_ne                      # same as vel_body but in local frame (m/s)\n"
  "\n"
  "float32[2] flow_uncompensated_integral # integrated optical flow measurement (rad)\n"
  "float32[2] flow_compensated_integral   # integrated optical flow measurement compensated for angular motion (rad)\n"
  "\n"
  "float32[3] gyro_rate                   # gyro measurement synchronized with flow measurements (rad/s)\n"
  "float32[3] gyro_rate_integral          # gyro measurement integrated to flow rate and synchronized with flow measurements (rad)\n"
  "\n"
  "float32[3] gyro_bias\n"
  "float32[3] ref_gyro\n"
  "float32[3] meas_gyro\n"
  "\n"
  "# TOPICS estimator_optical_flow_vel vehicle_optical_flow_vel";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__VehicleOpticalFlowVel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__VehicleOpticalFlowVel__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 954, 954},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__VehicleOpticalFlowVel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__VehicleOpticalFlowVel__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
