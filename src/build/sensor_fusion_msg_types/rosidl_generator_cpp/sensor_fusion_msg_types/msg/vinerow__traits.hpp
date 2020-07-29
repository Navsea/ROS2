// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__TRAITS_HPP_
#define SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__TRAITS_HPP_

#include "sensor_fusion_msg_types/msg/vinerow__struct.hpp"
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
inline const char * data_type<sensor_fusion_msg_types::msg::Vinerow>()
{
  return "sensor_fusion_msg_types::msg::Vinerow";
}

template<>
struct has_fixed_size<sensor_fusion_msg_types::msg::Vinerow>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<sensor_fusion_msg_types::msg::Vinerow>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<sensor_fusion_msg_types::msg::Vinerow>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__TRAITS_HPP_
