// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_H_
#define SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/header__struct.h"
// Member 'vinerows'
#include "sensor_fusion_msg_types/msg/vinerow__struct.h"

// Struct defined in msg/Vinerows in the package sensor_fusion_msgs.
typedef struct sensor_fusion_msgs__msg__Vinerows
{
  std_msgs__msg__Header header;
  sensor_fusion_msg_types__msg__Vinerow__Sequence vinerows;
} sensor_fusion_msgs__msg__Vinerows;

// Struct for a sequence of sensor_fusion_msgs__msg__Vinerows.
typedef struct sensor_fusion_msgs__msg__Vinerows__Sequence
{
  sensor_fusion_msgs__msg__Vinerows * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensor_fusion_msgs__msg__Vinerows__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_H_
