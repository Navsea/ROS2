// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice
#include "sensor_fusion_msgs/msg/vinerows__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header__functions.h"
// Member `vinerows`
#include "sensor_fusion_msg_types/msg/vinerow__functions.h"

bool
sensor_fusion_msgs__msg__Vinerows__init(sensor_fusion_msgs__msg__Vinerows * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    sensor_fusion_msgs__msg__Vinerows__fini(msg);
    return false;
  }
  // vinerows
  if (!sensor_fusion_msg_types__msg__Vinerow__Sequence__init(&msg->vinerows, 0)) {
    sensor_fusion_msgs__msg__Vinerows__fini(msg);
    return false;
  }
  return true;
}

void
sensor_fusion_msgs__msg__Vinerows__fini(sensor_fusion_msgs__msg__Vinerows * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // vinerows
  sensor_fusion_msg_types__msg__Vinerow__Sequence__fini(&msg->vinerows);
}

sensor_fusion_msgs__msg__Vinerows *
sensor_fusion_msgs__msg__Vinerows__create()
{
  sensor_fusion_msgs__msg__Vinerows * msg = (sensor_fusion_msgs__msg__Vinerows *)malloc(sizeof(sensor_fusion_msgs__msg__Vinerows));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sensor_fusion_msgs__msg__Vinerows));
  bool success = sensor_fusion_msgs__msg__Vinerows__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
sensor_fusion_msgs__msg__Vinerows__destroy(sensor_fusion_msgs__msg__Vinerows * msg)
{
  if (msg) {
    sensor_fusion_msgs__msg__Vinerows__fini(msg);
  }
  free(msg);
}


bool
sensor_fusion_msgs__msg__Vinerows__Sequence__init(sensor_fusion_msgs__msg__Vinerows__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  sensor_fusion_msgs__msg__Vinerows * data = NULL;
  if (size) {
    data = (sensor_fusion_msgs__msg__Vinerows *)calloc(size, sizeof(sensor_fusion_msgs__msg__Vinerows));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sensor_fusion_msgs__msg__Vinerows__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sensor_fusion_msgs__msg__Vinerows__fini(&data[i - 1]);
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
sensor_fusion_msgs__msg__Vinerows__Sequence__fini(sensor_fusion_msgs__msg__Vinerows__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sensor_fusion_msgs__msg__Vinerows__fini(&array->data[i]);
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

sensor_fusion_msgs__msg__Vinerows__Sequence *
sensor_fusion_msgs__msg__Vinerows__Sequence__create(size_t size)
{
  sensor_fusion_msgs__msg__Vinerows__Sequence * array = (sensor_fusion_msgs__msg__Vinerows__Sequence *)malloc(sizeof(sensor_fusion_msgs__msg__Vinerows__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = sensor_fusion_msgs__msg__Vinerows__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
sensor_fusion_msgs__msg__Vinerows__Sequence__destroy(sensor_fusion_msgs__msg__Vinerows__Sequence * array)
{
  if (array) {
    sensor_fusion_msgs__msg__Vinerows__Sequence__fini(array);
  }
  free(array);
}
