// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_H_
#define SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'direction'
#include "geometry_msgs/msg/vector3__struct.h"
// Member 'center'
#include "geometry_msgs/msg/point__struct.h"

// Struct defined in msg/Vinerow in the package sensor_fusion_msg_types.
typedef struct sensor_fusion_msg_types__msg__Vinerow
{
  geometry_msgs__msg__Vector3 direction;
  geometry_msgs__msg__Point center;
  double distance;
  double variance[7];
  bool is_valid;
} sensor_fusion_msg_types__msg__Vinerow;

// Struct for a sequence of sensor_fusion_msg_types__msg__Vinerow.
typedef struct sensor_fusion_msg_types__msg__Vinerow__Sequence
{
  sensor_fusion_msg_types__msg__Vinerow * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensor_fusion_msg_types__msg__Vinerow__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_H_
