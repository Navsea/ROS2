// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_demo_custommsg_create:msg/Custom.idl
// generated code does not contain a copyright notice
#include "ros2_demo_custommsg_create/msg/custom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `dir`
#include "geometry_msgs/msg/vector3__functions.h"
// Member `center`
#include "geometry_msgs/msg/point__functions.h"

bool
ros2_demo_custommsg_create__msg__Custom__init(ros2_demo_custommsg_create__msg__Custom * msg)
{
  if (!msg) {
    return false;
  }
  // dir
  if (!geometry_msgs__msg__Vector3__init(&msg->dir)) {
    ros2_demo_custommsg_create__msg__Custom__fini(msg);
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    ros2_demo_custommsg_create__msg__Custom__fini(msg);
    return false;
  }
  // dist
  // var
  // is_valid
  return true;
}

void
ros2_demo_custommsg_create__msg__Custom__fini(ros2_demo_custommsg_create__msg__Custom * msg)
{
  if (!msg) {
    return;
  }
  // dir
  geometry_msgs__msg__Vector3__fini(&msg->dir);
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // dist
  // var
  // is_valid
}

ros2_demo_custommsg_create__msg__Custom *
ros2_demo_custommsg_create__msg__Custom__create()
{
  ros2_demo_custommsg_create__msg__Custom * msg = (ros2_demo_custommsg_create__msg__Custom *)malloc(sizeof(ros2_demo_custommsg_create__msg__Custom));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_demo_custommsg_create__msg__Custom));
  bool success = ros2_demo_custommsg_create__msg__Custom__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ros2_demo_custommsg_create__msg__Custom__destroy(ros2_demo_custommsg_create__msg__Custom * msg)
{
  if (msg) {
    ros2_demo_custommsg_create__msg__Custom__fini(msg);
  }
  free(msg);
}


bool
ros2_demo_custommsg_create__msg__Custom__Sequence__init(ros2_demo_custommsg_create__msg__Custom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ros2_demo_custommsg_create__msg__Custom * data = NULL;
  if (size) {
    data = (ros2_demo_custommsg_create__msg__Custom *)calloc(size, sizeof(ros2_demo_custommsg_create__msg__Custom));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_demo_custommsg_create__msg__Custom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_demo_custommsg_create__msg__Custom__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_demo_custommsg_create__msg__Custom__Sequence__fini(ros2_demo_custommsg_create__msg__Custom__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_demo_custommsg_create__msg__Custom__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_demo_custommsg_create__msg__Custom__Sequence *
ros2_demo_custommsg_create__msg__Custom__Sequence__create(size_t size)
{
  ros2_demo_custommsg_create__msg__Custom__Sequence * array = (ros2_demo_custommsg_create__msg__Custom__Sequence *)malloc(sizeof(ros2_demo_custommsg_create__msg__Custom__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ros2_demo_custommsg_create__msg__Custom__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ros2_demo_custommsg_create__msg__Custom__Sequence__destroy(ros2_demo_custommsg_create__msg__Custom__Sequence * array)
{
  if (array) {
    ros2_demo_custommsg_create__msg__Custom__Sequence__fini(array);
  }
  free(array);
}
