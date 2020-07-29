// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice
#include "sensor_fusion_msgs/msg/vinerows__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "sensor_fusion_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "sensor_fusion_msgs/msg/vinerows__struct.h"
#include "sensor_fusion_msgs/msg/vinerows__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "sensor_fusion_msg_types/msg/vinerow__functions.h"  // vinerows

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sensor_fusion_msgs
size_t get_serialized_size_sensor_fusion_msg_types__msg__Vinerow(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sensor_fusion_msgs
size_t max_serialized_size_sensor_fusion_msg_types__msg__Vinerow(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_sensor_fusion_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_fusion_msg_types, msg, Vinerow)();


using _Vinerows__ros_msg_type = sensor_fusion_msgs__msg__Vinerows;

static bool _Vinerows__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Vinerows__ros_msg_type * ros_message = static_cast<const _Vinerows__ros_msg_type *>(untyped_ros_message);
  // Field name: vinerows
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_fusion_msg_types, msg, Vinerow
      )()->data);
    size_t size = 7;
    auto array_ptr = ros_message->vinerows;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _Vinerows__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Vinerows__ros_msg_type * ros_message = static_cast<_Vinerows__ros_msg_type *>(untyped_ros_message);
  // Field name: vinerows
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_fusion_msg_types, msg, Vinerow
      )()->data);
    size_t size = 7;
    auto array_ptr = ros_message->vinerows;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensor_fusion_msgs
size_t get_serialized_size_sensor_fusion_msgs__msg__Vinerows(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Vinerows__ros_msg_type * ros_message = static_cast<const _Vinerows__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name vinerows
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->vinerows;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_fusion_msg_types__msg__Vinerow(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Vinerows__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_sensor_fusion_msgs__msg__Vinerows(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensor_fusion_msgs
size_t max_serialized_size_sensor_fusion_msgs__msg__Vinerows(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: vinerows
  {
    size_t array_size = 7;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_fusion_msg_types__msg__Vinerow(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Vinerows__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_sensor_fusion_msgs__msg__Vinerows(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Vinerows = {
  "sensor_fusion_msgs::msg",
  "Vinerows",
  _Vinerows__cdr_serialize,
  _Vinerows__cdr_deserialize,
  _Vinerows__get_serialized_size,
  _Vinerows__max_serialized_size
};

static rosidl_message_type_support_t _Vinerows__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Vinerows,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_fusion_msgs, msg, Vinerows)() {
  return &_Vinerows__type_support;
}

#if defined(__cplusplus)
}
#endif
