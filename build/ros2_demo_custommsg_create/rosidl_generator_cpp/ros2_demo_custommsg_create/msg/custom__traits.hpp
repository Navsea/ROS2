// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_demo_custommsg_create:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__TRAITS_HPP_
#define ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__TRAITS_HPP_

#include "ros2_demo_custommsg_create/msg/custom__struct.hpp"
#include <rosidl_generator_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'dir'
#include "geometry_msgs/msg/vector3__traits.hpp"
// Member 'center'
#include "geometry_msgs/msg/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_demo_custommsg_create::msg::Custom>()
{
  return "ros2_demo_custommsg_create::msg::Custom";
}

template<>
struct has_fixed_size<ros2_demo_custommsg_create::msg::Custom>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<ros2_demo_custommsg_create::msg::Custom>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<ros2_demo_custommsg_create::msg::Custom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__TRAITS_HPP_
