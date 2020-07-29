// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_demo_custommsg_create:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__STRUCT_H_
#define ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'dir'
#include "geometry_msgs/msg/vector3__struct.h"
// Member 'center'
#include "geometry_msgs/msg/point__struct.h"

// Struct defined in msg/Custom in the package ros2_demo_custommsg_create.
typedef struct ros2_demo_custommsg_create__msg__Custom
{
  geometry_msgs__msg__Vector3 dir;
  geometry_msgs__msg__Point center;
  double dist;
  double var[7];
  bool is_valid;
} ros2_demo_custommsg_create__msg__Custom;

// Struct for a sequence of ros2_demo_custommsg_create__msg__Custom.
typedef struct ros2_demo_custommsg_create__msg__Custom__Sequence
{
  ros2_demo_custommsg_create__msg__Custom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_demo_custommsg_create__msg__Custom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__STRUCT_H_
