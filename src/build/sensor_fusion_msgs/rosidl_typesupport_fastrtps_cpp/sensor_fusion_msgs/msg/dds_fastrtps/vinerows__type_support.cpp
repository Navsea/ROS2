// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice
#include "sensor_fusion_msgs/msg/vinerows__rosidl_typesupport_fastrtps_cpp.hpp"
#include "sensor_fusion_msgs/msg/vinerows__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace sensor_fusion_msg_types
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_fusion_msg_types::msg::Vinerow &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_fusion_msg_types::msg::Vinerow &);
size_t get_serialized_size(
  const sensor_fusion_msg_types::msg::Vinerow &,
  size_t current_alignment);
size_t
max_serialized_size_Vinerow(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_fusion_msg_types


namespace sensor_fusion_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msgs
cdr_serialize(
  const sensor_fusion_msgs::msg::Vinerows & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: vinerows
  {
    for (size_t i = 0; i < 7; i++) {
      sensor_fusion_msg_types::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.vinerows[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sensor_fusion_msgs::msg::Vinerows & ros_message)
{
  // Member: vinerows
  {
    for (size_t i = 0; i < 7; i++) {
      sensor_fusion_msg_types::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.vinerows[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msgs
get_serialized_size(
  const sensor_fusion_msgs::msg::Vinerows & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: vinerows
  {
    size_t array_size = 7;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_fusion_msg_types::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.vinerows[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor_fusion_msgs
max_serialized_size_Vinerows(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: vinerows
  {
    size_t array_size = 7;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_fusion_msg_types::msg::typesupport_fastrtps_cpp::max_serialized_size_Vinerow(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Vinerows__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const sensor_fusion_msgs::msg::Vinerows *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Vinerows__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<sensor_fusion_msgs::msg::Vinerows *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Vinerows__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const sensor_fusion_msgs::msg::Vinerows *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Vinerows__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Vinerows(full_bounded, 0);
}

static message_type_support_callbacks_t _Vinerows__callbacks = {
  "sensor_fusion_msgs::msg",
  "Vinerows",
  _Vinerows__cdr_serialize,
  _Vinerows__cdr_deserialize,
  _Vinerows__get_serialized_size,
  _Vinerows__max_serialized_size
};

static rosidl_message_type_support_t _Vinerows__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Vinerows__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sensor_fusion_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_sensor_fusion_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<sensor_fusion_msgs::msg::Vinerows>()
{
  return &sensor_fusion_msgs::msg::typesupport_fastrtps_cpp::_Vinerows__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sensor_fusion_msgs, msg, Vinerows)() {
  return &sensor_fusion_msgs::msg::typesupport_fastrtps_cpp::_Vinerows__handle;
}

#ifdef __cplusplus
}
#endif
