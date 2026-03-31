// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armkidd_interfaces:msg/WorldTarget.idl
// generated code does not contain a copyright notice
#include "armkidd_interfaces/msg/detail/world_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armkidd_interfaces__msg__WorldTarget__init(armkidd_interfaces__msg__WorldTarget * msg)
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
armkidd_interfaces__msg__WorldTarget__fini(armkidd_interfaces__msg__WorldTarget * msg)
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
armkidd_interfaces__msg__WorldTarget__are_equal(const armkidd_interfaces__msg__WorldTarget * lhs, const armkidd_interfaces__msg__WorldTarget * rhs)
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
armkidd_interfaces__msg__WorldTarget__copy(
  const armkidd_interfaces__msg__WorldTarget * input,
  armkidd_interfaces__msg__WorldTarget * output)
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

armkidd_interfaces__msg__WorldTarget *
armkidd_interfaces__msg__WorldTarget__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__WorldTarget * msg = (armkidd_interfaces__msg__WorldTarget *)allocator.allocate(sizeof(armkidd_interfaces__msg__WorldTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armkidd_interfaces__msg__WorldTarget));
  bool success = armkidd_interfaces__msg__WorldTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armkidd_interfaces__msg__WorldTarget__destroy(armkidd_interfaces__msg__WorldTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armkidd_interfaces__msg__WorldTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armkidd_interfaces__msg__WorldTarget__Sequence__init(armkidd_interfaces__msg__WorldTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__WorldTarget * data = NULL;

  if (size) {
    data = (armkidd_interfaces__msg__WorldTarget *)allocator.zero_allocate(size, sizeof(armkidd_interfaces__msg__WorldTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armkidd_interfaces__msg__WorldTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armkidd_interfaces__msg__WorldTarget__fini(&data[i - 1]);
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
armkidd_interfaces__msg__WorldTarget__Sequence__fini(armkidd_interfaces__msg__WorldTarget__Sequence * array)
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
      armkidd_interfaces__msg__WorldTarget__fini(&array->data[i]);
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

armkidd_interfaces__msg__WorldTarget__Sequence *
armkidd_interfaces__msg__WorldTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__msg__WorldTarget__Sequence * array = (armkidd_interfaces__msg__WorldTarget__Sequence *)allocator.allocate(sizeof(armkidd_interfaces__msg__WorldTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armkidd_interfaces__msg__WorldTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armkidd_interfaces__msg__WorldTarget__Sequence__destroy(armkidd_interfaces__msg__WorldTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armkidd_interfaces__msg__WorldTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armkidd_interfaces__msg__WorldTarget__Sequence__are_equal(const armkidd_interfaces__msg__WorldTarget__Sequence * lhs, const armkidd_interfaces__msg__WorldTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armkidd_interfaces__msg__WorldTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armkidd_interfaces__msg__WorldTarget__Sequence__copy(
  const armkidd_interfaces__msg__WorldTarget__Sequence * input,
  armkidd_interfaces__msg__WorldTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armkidd_interfaces__msg__WorldTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armkidd_interfaces__msg__WorldTarget * data =
      (armkidd_interfaces__msg__WorldTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armkidd_interfaces__msg__WorldTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armkidd_interfaces__msg__WorldTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armkidd_interfaces__msg__WorldTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
