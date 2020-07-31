// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSGS__MSG__VINEROWS__TRAITS_HPP_
#define SENSOR_FUSION_MSGS__MSG__VINEROWS__TRAITS_HPP_

#include "sensor_fusion_msgs/msg/vinerows__struct.hpp"
#include <rosidl_generator_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sensor_fusion_msgs::msg::Vinerows>()
{
  return "sensor_fusion_msgs::msg::Vinerows";
}

template<>
struct has_fixed_size<sensor_fusion_msgs::msg::Vinerows>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_fusion_msgs::msg::Vinerows>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_fusion_msgs::msg::Vinerows>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_FUSION_MSGS__MSG__VINEROWS__TRAITS_HPP_
