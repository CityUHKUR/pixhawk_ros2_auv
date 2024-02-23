// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pioneer_msgs:msg/AUVState.idl
// generated code does not contain a copyright notice
#include "pioneer_msgs/msg/detail/auv_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `current_state`
// Member `current_control`
#include "rosidl_runtime_c/string_functions.h"

bool
pioneer_msgs__msg__AUVState__init(pioneer_msgs__msg__AUVState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pioneer_msgs__msg__AUVState__fini(msg);
    return false;
  }
  // current_state
  if (!rosidl_runtime_c__String__init(&msg->current_state)) {
    pioneer_msgs__msg__AUVState__fini(msg);
    return false;
  }
  // current_control
  if (!rosidl_runtime_c__String__init(&msg->current_control)) {
    pioneer_msgs__msg__AUVState__fini(msg);
    return false;
  }
  return true;
}

void
pioneer_msgs__msg__AUVState__fini(pioneer_msgs__msg__AUVState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // current_state
  rosidl_runtime_c__String__fini(&msg->current_state);
  // current_control
  rosidl_runtime_c__String__fini(&msg->current_control);
}

bool
pioneer_msgs__msg__AUVState__are_equal(const pioneer_msgs__msg__AUVState * lhs, const pioneer_msgs__msg__AUVState * rhs)
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
  // current_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_state), &(rhs->current_state)))
  {
    return false;
  }
  // current_control
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_control), &(rhs->current_control)))
  {
    return false;
  }
  return true;
}

bool
pioneer_msgs__msg__AUVState__copy(
  const pioneer_msgs__msg__AUVState * input,
  pioneer_msgs__msg__AUVState * output)
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
  // current_state
  if (!rosidl_runtime_c__String__copy(
      &(input->current_state), &(output->current_state)))
  {
    return false;
  }
  // current_control
  if (!rosidl_runtime_c__String__copy(
      &(input->current_control), &(output->current_control)))
  {
    return false;
  }
  return true;
}

pioneer_msgs__msg__AUVState *
pioneer_msgs__msg__AUVState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__AUVState * msg = (pioneer_msgs__msg__AUVState *)allocator.allocate(sizeof(pioneer_msgs__msg__AUVState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pioneer_msgs__msg__AUVState));
  bool success = pioneer_msgs__msg__AUVState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pioneer_msgs__msg__AUVState__destroy(pioneer_msgs__msg__AUVState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pioneer_msgs__msg__AUVState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pioneer_msgs__msg__AUVState__Sequence__init(pioneer_msgs__msg__AUVState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__AUVState * data = NULL;

  if (size) {
    data = (pioneer_msgs__msg__AUVState *)allocator.zero_allocate(size, sizeof(pioneer_msgs__msg__AUVState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pioneer_msgs__msg__AUVState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pioneer_msgs__msg__AUVState__fini(&data[i - 1]);
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
pioneer_msgs__msg__AUVState__Sequence__fini(pioneer_msgs__msg__AUVState__Sequence * array)
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
      pioneer_msgs__msg__AUVState__fini(&array->data[i]);
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

pioneer_msgs__msg__AUVState__Sequence *
pioneer_msgs__msg__AUVState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pioneer_msgs__msg__AUVState__Sequence * array = (pioneer_msgs__msg__AUVState__Sequence *)allocator.allocate(sizeof(pioneer_msgs__msg__AUVState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pioneer_msgs__msg__AUVState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pioneer_msgs__msg__AUVState__Sequence__destroy(pioneer_msgs__msg__AUVState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pioneer_msgs__msg__AUVState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pioneer_msgs__msg__AUVState__Sequence__are_equal(const pioneer_msgs__msg__AUVState__Sequence * lhs, const pioneer_msgs__msg__AUVState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pioneer_msgs__msg__AUVState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pioneer_msgs__msg__AUVState__Sequence__copy(
  const pioneer_msgs__msg__AUVState__Sequence * input,
  pioneer_msgs__msg__AUVState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pioneer_msgs__msg__AUVState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pioneer_msgs__msg__AUVState * data =
      (pioneer_msgs__msg__AUVState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pioneer_msgs__msg__AUVState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pioneer_msgs__msg__AUVState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pioneer_msgs__msg__AUVState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
