// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice
#include "sensor_fusion_msg_types/msg/vinerow__functions.h"

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
sensor_fusion_msg_types__msg__Vinerow__init(sensor_fusion_msg_types__msg__Vinerow * msg)
{
  if (!msg) {
    return false;
  }
  // dir
  if (!geometry_msgs__msg__Vector3__init(&msg->dir)) {
    sensor_fusion_msg_types__msg__Vinerow__fini(msg);
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    sensor_fusion_msg_types__msg__Vinerow__fini(msg);
    return false;
  }
  // dist
  // var
  // is_valid
  return true;
}

void
sensor_fusion_msg_types__msg__Vinerow__fini(sensor_fusion_msg_types__msg__Vinerow * msg)
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

sensor_fusion_msg_types__msg__Vinerow *
sensor_fusion_msg_types__msg__Vinerow__create()
{
  sensor_fusion_msg_types__msg__Vinerow * msg = (sensor_fusion_msg_types__msg__Vinerow *)malloc(sizeof(sensor_fusion_msg_types__msg__Vinerow));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sensor_fusion_msg_types__msg__Vinerow));
  bool success = sensor_fusion_msg_types__msg__Vinerow__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
sensor_fusion_msg_types__msg__Vinerow__destroy(sensor_fusion_msg_types__msg__Vinerow * msg)
{
  if (msg) {
    sensor_fusion_msg_types__msg__Vinerow__fini(msg);
  }
  free(msg);
}


bool
sensor_fusion_msg_types__msg__Vinerow__Sequence__init(sensor_fusion_msg_types__msg__Vinerow__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  sensor_fusion_msg_types__msg__Vinerow * data = NULL;
  if (size) {
    data = (sensor_fusion_msg_types__msg__Vinerow *)calloc(size, sizeof(sensor_fusion_msg_types__msg__Vinerow));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sensor_fusion_msg_types__msg__Vinerow__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sensor_fusion_msg_types__msg__Vinerow__fini(&data[i - 1]);
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
sensor_fusion_msg_types__msg__Vinerow__Sequence__fini(sensor_fusion_msg_types__msg__Vinerow__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sensor_fusion_msg_types__msg__Vinerow__fini(&array->data[i]);
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

sensor_fusion_msg_types__msg__Vinerow__Sequence *
sensor_fusion_msg_types__msg__Vinerow__Sequence__create(size_t size)
{
  sensor_fusion_msg_types__msg__Vinerow__Sequence * array = (sensor_fusion_msg_types__msg__Vinerow__Sequence *)malloc(sizeof(sensor_fusion_msg_types__msg__Vinerow__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = sensor_fusion_msg_types__msg__Vinerow__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
sensor_fusion_msg_types__msg__Vinerow__Sequence__destroy(sensor_fusion_msg_types__msg__Vinerow__Sequence * array)
{
  if (array) {
    sensor_fusion_msg_types__msg__Vinerow__Sequence__fini(array);
  }
  free(array);
}
