// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armkidd_interfaces:msg/ArmkiddTarget.idl
// generated code does not contain a copyright notice
#include "armkidd_interfaces/msg/detail/armkidd_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armkidd_interfaces__msg__ArmkiddTarget__init(armkidd_interfaces__msg__ArmkiddTarget * msg)
{
  if (!msg) {
    return false;
  }
  // target_x
  // target_y
  // depth
  // width
  // height
  return true;
}

void
armkidd_interfaces__msg__ArmkiddTarget__fini(armkidd_interfaces__msg__ArmkiddTarget * msg)
{
  if (!msg) {
    return;
  }
  // target_x
  // target_y
  // depth
  // width
  // height
}

bool
armkidd_interfaces__msg__ArmkiddTarget__are_equal(const armkidd_interfaces__msg__ArmkiddTarget * lhs, const armkidd_interfaces__msg__ArmkiddTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_x
  if (lhs->target_x != rhs->target_x) {
    return false;
  }
  // target_y
  if (lhs->target_y != rhs->target_y) {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  return true;
}

bool
armkidd_interfaces__msg__ArmkiddTarget__copy(
  const armkidd_interfaces__msg__ArmkiddTarget * input,
  armkidd_interfaces__msg__ArmkiddTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // target_x
  output->target_x = input->target_x;
  // target_y
  output->target_y = input->target_y;
  // depth
  output->depth = input->depth;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  return true;
}

armkidd_interfaces__msg__ArmkiddTarget *
armkidd_interfaces__msg__ArmkiddTarget__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__ArmkiddTarget * msg = (armkidd_interfaces__msg__ArmkiddTarget *)allocator.allocate(sizeof(armkidd_interfaces__msg__ArmkiddTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armkidd_interfaces__msg__ArmkiddTarget));
  bool success = armkidd_interfaces__msg__ArmkiddTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armkidd_interfaces__msg__ArmkiddTarget__destroy(armkidd_interfaces__msg__ArmkiddTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armkidd_interfaces__msg__ArmkiddTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armkidd_interfaces__msg__ArmkiddTarget__Sequence__init(armkidd_interfaces__msg__ArmkiddTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__ArmkiddTarget * data = NULL;

  if (size) {
    data = (armkidd_interfaces__msg__ArmkiddTarget *)allocator.zero_allocate(size, sizeof(armkidd_interfaces__msg__ArmkiddTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armkidd_interfaces__msg__ArmkiddTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armkidd_interfaces__msg__ArmkiddTarget__fini(&data[i - 1]);
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
armkidd_interfaces__msg__ArmkiddTarget__Sequence__fini(armkidd_interfaces__msg__ArmkiddTarget__Sequence * array)
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
      armkidd_interfaces__msg__ArmkiddTarget__fini(&array->data[i]);
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

armkidd_interfaces__msg__ArmkiddTarget__Sequence *
armkidd_interfaces__msg__ArmkiddTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__ArmkiddTarget__Sequence * array = (armkidd_interfaces__msg__ArmkiddTarget__Sequence *)allocator.allocate(sizeof(armkidd_interfaces__msg__ArmkiddTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armkidd_interfaces__msg__ArmkiddTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armkidd_interfaces__msg__ArmkiddTarget__Sequence__destroy(armkidd_interfaces__msg__ArmkiddTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armkidd_interfaces__msg__ArmkiddTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armkidd_interfaces__msg__ArmkiddTarget__Sequence__are_equal(const armkidd_interfaces__msg__ArmkiddTarget__Sequence * lhs, const armkidd_interfaces__msg__ArmkiddTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armkidd_interfaces__msg__ArmkiddTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armkidd_interfaces__msg__ArmkiddTarget__Sequence__copy(
  const armkidd_interfaces__msg__ArmkiddTarget__Sequence * input,
  armkidd_interfaces__msg__ArmkiddTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armkidd_interfaces__msg__ArmkiddTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armkidd_interfaces__msg__ArmkiddTarget * data =
      (armkidd_interfaces__msg__ArmkiddTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armkidd_interfaces__msg__ArmkiddTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armkidd_interfaces__msg__ArmkiddTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armkidd_interfaces__msg__ArmkiddTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
