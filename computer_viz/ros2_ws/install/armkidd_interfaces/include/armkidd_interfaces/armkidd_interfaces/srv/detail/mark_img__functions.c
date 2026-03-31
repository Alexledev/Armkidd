// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice
#include "armkidd_interfaces/srv/detail/mark_img__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
armkidd_interfaces__srv__MarkImg_Request__init(armkidd_interfaces__srv__MarkImg_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x1
  // y1
  // x2
  // y2
  // choke_x
  // choke_y
  // is_valid
  return true;
}

void
armkidd_interfaces__srv__MarkImg_Request__fini(armkidd_interfaces__srv__MarkImg_Request * msg)
{
  if (!msg) {
    return;
  }
  // x1
  // y1
  // x2
  // y2
  // choke_x
  // choke_y
  // is_valid
}

bool
armkidd_interfaces__srv__MarkImg_Request__are_equal(const armkidd_interfaces__srv__MarkImg_Request * lhs, const armkidd_interfaces__srv__MarkImg_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // choke_x
  if (lhs->choke_x != rhs->choke_x) {
    return false;
  }
  // choke_y
  if (lhs->choke_y != rhs->choke_y) {
    return false;
  }
  // is_valid
  if (lhs->is_valid != rhs->is_valid) {
    return false;
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Request__copy(
  const armkidd_interfaces__srv__MarkImg_Request * input,
  armkidd_interfaces__srv__MarkImg_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // choke_x
  output->choke_x = input->choke_x;
  // choke_y
  output->choke_y = input->choke_y;
  // is_valid
  output->is_valid = input->is_valid;
  return true;
}

armkidd_interfaces__srv__MarkImg_Request *
armkidd_interfaces__srv__MarkImg_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Request * msg = (armkidd_interfaces__srv__MarkImg_Request *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armkidd_interfaces__srv__MarkImg_Request));
  bool success = armkidd_interfaces__srv__MarkImg_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armkidd_interfaces__srv__MarkImg_Request__destroy(armkidd_interfaces__srv__MarkImg_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armkidd_interfaces__srv__MarkImg_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armkidd_interfaces__srv__MarkImg_Request__Sequence__init(armkidd_interfaces__srv__MarkImg_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Request * data = NULL;

  if (size) {
    data = (armkidd_interfaces__srv__MarkImg_Request *)allocator.zero_allocate(size, sizeof(armkidd_interfaces__srv__MarkImg_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armkidd_interfaces__srv__MarkImg_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armkidd_interfaces__srv__MarkImg_Request__fini(&data[i - 1]);
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
armkidd_interfaces__srv__MarkImg_Request__Sequence__fini(armkidd_interfaces__srv__MarkImg_Request__Sequence * array)
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
      armkidd_interfaces__srv__MarkImg_Request__fini(&array->data[i]);
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

armkidd_interfaces__srv__MarkImg_Request__Sequence *
armkidd_interfaces__srv__MarkImg_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Request__Sequence * array = (armkidd_interfaces__srv__MarkImg_Request__Sequence *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armkidd_interfaces__srv__MarkImg_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armkidd_interfaces__srv__MarkImg_Request__Sequence__destroy(armkidd_interfaces__srv__MarkImg_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armkidd_interfaces__srv__MarkImg_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armkidd_interfaces__srv__MarkImg_Request__Sequence__are_equal(const armkidd_interfaces__srv__MarkImg_Request__Sequence * lhs, const armkidd_interfaces__srv__MarkImg_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Request__Sequence__copy(
  const armkidd_interfaces__srv__MarkImg_Request__Sequence * input,
  armkidd_interfaces__srv__MarkImg_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armkidd_interfaces__srv__MarkImg_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armkidd_interfaces__srv__MarkImg_Request * data =
      (armkidd_interfaces__srv__MarkImg_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armkidd_interfaces__srv__MarkImg_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armkidd_interfaces__srv__MarkImg_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `image`
#include "std_msgs/msg/detail/byte_multi_array__functions.h"

bool
armkidd_interfaces__srv__MarkImg_Response__init(armkidd_interfaces__srv__MarkImg_Response * msg)
{
  if (!msg) {
    return false;
  }
  // image
  if (!std_msgs__msg__ByteMultiArray__init(&msg->image)) {
    armkidd_interfaces__srv__MarkImg_Response__fini(msg);
    return false;
  }
  return true;
}

void
armkidd_interfaces__srv__MarkImg_Response__fini(armkidd_interfaces__srv__MarkImg_Response * msg)
{
  if (!msg) {
    return;
  }
  // image
  std_msgs__msg__ByteMultiArray__fini(&msg->image);
}

bool
armkidd_interfaces__srv__MarkImg_Response__are_equal(const armkidd_interfaces__srv__MarkImg_Response * lhs, const armkidd_interfaces__srv__MarkImg_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // image
  if (!std_msgs__msg__ByteMultiArray__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Response__copy(
  const armkidd_interfaces__srv__MarkImg_Response * input,
  armkidd_interfaces__srv__MarkImg_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // image
  if (!std_msgs__msg__ByteMultiArray__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

armkidd_interfaces__srv__MarkImg_Response *
armkidd_interfaces__srv__MarkImg_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Response * msg = (armkidd_interfaces__srv__MarkImg_Response *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armkidd_interfaces__srv__MarkImg_Response));
  bool success = armkidd_interfaces__srv__MarkImg_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armkidd_interfaces__srv__MarkImg_Response__destroy(armkidd_interfaces__srv__MarkImg_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armkidd_interfaces__srv__MarkImg_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armkidd_interfaces__srv__MarkImg_Response__Sequence__init(armkidd_interfaces__srv__MarkImg_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Response * data = NULL;

  if (size) {
    data = (armkidd_interfaces__srv__MarkImg_Response *)allocator.zero_allocate(size, sizeof(armkidd_interfaces__srv__MarkImg_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armkidd_interfaces__srv__MarkImg_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armkidd_interfaces__srv__MarkImg_Response__fini(&data[i - 1]);
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
armkidd_interfaces__srv__MarkImg_Response__Sequence__fini(armkidd_interfaces__srv__MarkImg_Response__Sequence * array)
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
      armkidd_interfaces__srv__MarkImg_Response__fini(&array->data[i]);
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

armkidd_interfaces__srv__MarkImg_Response__Sequence *
armkidd_interfaces__srv__MarkImg_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Response__Sequence * array = (armkidd_interfaces__srv__MarkImg_Response__Sequence *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armkidd_interfaces__srv__MarkImg_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armkidd_interfaces__srv__MarkImg_Response__Sequence__destroy(armkidd_interfaces__srv__MarkImg_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armkidd_interfaces__srv__MarkImg_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armkidd_interfaces__srv__MarkImg_Response__Sequence__are_equal(const armkidd_interfaces__srv__MarkImg_Response__Sequence * lhs, const armkidd_interfaces__srv__MarkImg_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Response__Sequence__copy(
  const armkidd_interfaces__srv__MarkImg_Response__Sequence * input,
  armkidd_interfaces__srv__MarkImg_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armkidd_interfaces__srv__MarkImg_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armkidd_interfaces__srv__MarkImg_Response * data =
      (armkidd_interfaces__srv__MarkImg_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armkidd_interfaces__srv__MarkImg_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armkidd_interfaces__srv__MarkImg_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__functions.h"

bool
armkidd_interfaces__srv__MarkImg_Event__init(armkidd_interfaces__srv__MarkImg_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    armkidd_interfaces__srv__MarkImg_Event__fini(msg);
    return false;
  }
  // request
  if (!armkidd_interfaces__srv__MarkImg_Request__Sequence__init(&msg->request, 0)) {
    armkidd_interfaces__srv__MarkImg_Event__fini(msg);
    return false;
  }
  // response
  if (!armkidd_interfaces__srv__MarkImg_Response__Sequence__init(&msg->response, 0)) {
    armkidd_interfaces__srv__MarkImg_Event__fini(msg);
    return false;
  }
  return true;
}

void
armkidd_interfaces__srv__MarkImg_Event__fini(armkidd_interfaces__srv__MarkImg_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  armkidd_interfaces__srv__MarkImg_Request__Sequence__fini(&msg->request);
  // response
  armkidd_interfaces__srv__MarkImg_Response__Sequence__fini(&msg->response);
}

bool
armkidd_interfaces__srv__MarkImg_Event__are_equal(const armkidd_interfaces__srv__MarkImg_Event * lhs, const armkidd_interfaces__srv__MarkImg_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!armkidd_interfaces__srv__MarkImg_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!armkidd_interfaces__srv__MarkImg_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Event__copy(
  const armkidd_interfaces__srv__MarkImg_Event * input,
  armkidd_interfaces__srv__MarkImg_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!armkidd_interfaces__srv__MarkImg_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!armkidd_interfaces__srv__MarkImg_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

armkidd_interfaces__srv__MarkImg_Event *
armkidd_interfaces__srv__MarkImg_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Event * msg = (armkidd_interfaces__srv__MarkImg_Event *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armkidd_interfaces__srv__MarkImg_Event));
  bool success = armkidd_interfaces__srv__MarkImg_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armkidd_interfaces__srv__MarkImg_Event__destroy(armkidd_interfaces__srv__MarkImg_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armkidd_interfaces__srv__MarkImg_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armkidd_interfaces__srv__MarkImg_Event__Sequence__init(armkidd_interfaces__srv__MarkImg_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Event * data = NULL;

  if (size) {
    data = (armkidd_interfaces__srv__MarkImg_Event *)allocator.zero_allocate(size, sizeof(armkidd_interfaces__srv__MarkImg_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armkidd_interfaces__srv__MarkImg_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armkidd_interfaces__srv__MarkImg_Event__fini(&data[i - 1]);
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
armkidd_interfaces__srv__MarkImg_Event__Sequence__fini(armkidd_interfaces__srv__MarkImg_Event__Sequence * array)
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
      armkidd_interfaces__srv__MarkImg_Event__fini(&array->data[i]);
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

armkidd_interfaces__srv__MarkImg_Event__Sequence *
armkidd_interfaces__srv__MarkImg_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armkidd_interfaces__srv__MarkImg_Event__Sequence * array = (armkidd_interfaces__srv__MarkImg_Event__Sequence *)allocator.allocate(sizeof(armkidd_interfaces__srv__MarkImg_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armkidd_interfaces__srv__MarkImg_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armkidd_interfaces__srv__MarkImg_Event__Sequence__destroy(armkidd_interfaces__srv__MarkImg_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armkidd_interfaces__srv__MarkImg_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armkidd_interfaces__srv__MarkImg_Event__Sequence__are_equal(const armkidd_interfaces__srv__MarkImg_Event__Sequence * lhs, const armkidd_interfaces__srv__MarkImg_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armkidd_interfaces__srv__MarkImg_Event__Sequence__copy(
  const armkidd_interfaces__srv__MarkImg_Event__Sequence * input,
  armkidd_interfaces__srv__MarkImg_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armkidd_interfaces__srv__MarkImg_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armkidd_interfaces__srv__MarkImg_Event * data =
      (armkidd_interfaces__srv__MarkImg_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armkidd_interfaces__srv__MarkImg_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armkidd_interfaces__srv__MarkImg_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armkidd_interfaces__srv__MarkImg_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
