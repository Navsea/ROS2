// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_generator_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "sensor_fusion_msg_types/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "sensor_fusion_msg_types/msg/vinerow__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace sensor_fusion_msg_types
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msg_types
cdr_serialize(
  const sensor_fusion_msg_types::msg::Vinerow & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msg_types
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sensor_fusion_msg_types::msg::Vinerow & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msg_types
get_serialized_size(
  const sensor_fusion_msg_types::msg::Vinerow & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msg_types
max_serialized_size_Vinerow(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sensor_fusion_msg_types

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msg_types
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sensor_fusion_msg_types, msg, Vinerow)();

#ifdef __cplusplus
}
#endif

#endif  // SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
