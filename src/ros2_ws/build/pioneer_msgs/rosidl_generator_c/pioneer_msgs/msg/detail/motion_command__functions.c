// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pioneer_msgs:msg/MotionCommand.idl
// generated code does not contain a copyright notice
#include "pioneer_msgs/msg/detail/motion_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `direction`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
pioneer_msgs__msg__MotionCommand__init(pioneer_msgs__msg__MotionCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pioneer_msgs__msg__MotionCommand__fini(msg);
    return false;
  }
  // turn_mode
  // direction
  if (!geometry_msgs__msg__Vector3__init(&msg->direction)) {
    pioneer_msgs__msg__MotionCommand__fini(msg);
    return false;
  }
  // distance
  // time
  return true;
}

void
pioneer_msgs__msg__MotionCommand__fini(pioneer_msgs__msg__MotionCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // turn_mode
  // direction
  geometry_msgs__msg__Vector3__fini(&msg->direction);
  // distance
  // time
}

bool
pioneer_msgs__msg__MotionCommand__are_equal(const pioneer_msgs__msg__MotionCommand * lhs, const pioneer_msgs__msg__MotionCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // turn_mode
  if (lhs->turn_mode != rhs->turn_mode) {
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  return true;
}

bool
pioneer_msgs__msg__MotionCommand__copy(
  const pioneer_msgs__msg__MotionCommand * input,
  pioneer_msgs__msg__MotionCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // turn_mode
  output->turn_mode = input->turn_mode;
  // direction
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  // time
  output->time = input->time;
  return true;
}

pioneer_msgs__msg__MotionCommand *
pioneer_msgs__msg__MotionCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__MotionCommand * msg = (pioneer_msgs__msg__MotionCommand *)allocator.allocate(sizeof(pioneer_msgs__msg__MotionCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pioneer_msgs__msg__MotionCommand));
  bool success = pioneer_msgs__msg__MotionCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pioneer_msgs__msg__MotionCommand__destroy(pioneer_msgs__msg__MotionCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pioneer_msgs__msg__MotionCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pioneer_msgs__msg__MotionCommand__Sequence__init(pioneer_msgs__msg__MotionCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__MotionCommand * data = NULL;

  if (size) {
    data = (pioneer_msgs__msg__MotionCommand *)allocator.zero_allocate(size, sizeof(pioneer_msgs__msg__MotionCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pioneer_msgs__msg__MotionCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pioneer_msgs__msg__MotionCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pioneer_msgs__msg__MotionCommand__Sequence__fini(pioneer_msgs__msg__MotionCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pioneer_msgs__msg__MotionCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pioneer_msgs__msg__MotionCommand__Sequence *
pioneer_msgs__msg__MotionCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__MotionCommand__Sequence * array = (pioneer_msgs__msg__MotionCommand__Sequence *)allocator.allocate(sizeof(pioneer_msgs__msg__MotionCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pioneer_msgs__msg__MotionCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pioneer_msgs__msg__MotionCommand__Sequence__destroy(pioneer_msgs__msg__MotionCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pioneer_msgs__msg__MotionCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pioneer_msgs__msg__MotionCommand__Sequence__are_equal(const pioneer_msgs__msg__MotionCommand__Sequence * lhs, const pioneer_msgs__msg__MotionCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pioneer_msgs__msg__MotionCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pioneer_msgs__msg__MotionCommand__Sequence__copy(
  const pioneer_msgs__msg__MotionCommand__Sequence * input,
  pioneer_msgs__msg__MotionCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pioneer_msgs__msg__MotionCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pioneer_msgs__msg__MotionCommand * data =
      (pioneer_msgs__msg__MotionCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pioneer_msgs__msg__MotionCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pioneer_msgs__msg__MotionCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pioneer_msgs__msg__MotionCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
