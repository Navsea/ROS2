// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sensor_fusion_msgs/msg/vinerows__rosidl_typesupport_introspection_c.h"
#include "sensor_fusion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sensor_fusion_msgs/msg/vinerows__functions.h"
#include "sensor_fusion_msgs/msg/vinerows__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/header__rosidl_typesupport_introspection_c.h"
// Member `vinerows`
#include "sensor_fusion_msg_types/msg/vinerow.h"
// Member `vinerows`
#include "sensor_fusion_msg_types/msg/vinerow__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Vinerows__rosidl_typesupport_introspection_c__Vinerows_init_function(
  void * message_memory, enum rosidl_runtime_c_message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sensor_fusion_msgs__msg__Vinerows__init(message_memory);
}

void Vinerows__rosidl_typesupport_introspection_c__Vinerows_fini_function(void * message_memory)
{
  sensor_fusion_msgs__msg__Vinerows__fini(message_memory);
}

size_t Vinerows__rosidl_typesupport_introspection_c__size_function__Vinerow__vinerows(
  const void * untyped_member)
{
  const sensor_fusion_msg_types__msg__Vinerow__Sequence * member =
    (const sensor_fusion_msg_types__msg__Vinerow__Sequence *)(untyped_member);
  return member->size;
}

const void * Vinerows__rosidl_typesupport_introspection_c__get_const_function__Vinerow__vinerows(
  const void * untyped_member, size_t index)
{
  const sensor_fusion_msg_types__msg__Vinerow__Sequence * member =
    (const sensor_fusion_msg_types__msg__Vinerow__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Vinerows__rosidl_typesupport_introspection_c__get_function__Vinerow__vinerows(
  void * untyped_member, size_t index)
{
  sensor_fusion_msg_types__msg__Vinerow__Sequence * member =
    (sensor_fusion_msg_types__msg__Vinerow__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Vinerows__rosidl_typesupport_introspection_c__resize_function__Vinerow__vinerows(
  void * untyped_member, size_t size)
{
  sensor_fusion_msg_types__msg__Vinerow__Sequence * member =
    (sensor_fusion_msg_types__msg__Vinerow__Sequence *)(untyped_member);
  sensor_fusion_msg_types__msg__Vinerow__Sequence__fini(member);
  return sensor_fusion_msg_types__msg__Vinerow__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor_fusion_msgs__msg__Vinerows, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vinerows",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor_fusion_msgs__msg__Vinerows, vinerows),  // bytes offset in struct
    NULL,  // default value
    Vinerows__rosidl_typesupport_introspection_c__size_function__Vinerow__vinerows,  // size() function pointer
    Vinerows__rosidl_typesupport_introspection_c__get_const_function__Vinerow__vinerows,  // get_const(index) function pointer
    Vinerows__rosidl_typesupport_introspection_c__get_function__Vinerow__vinerows,  // get(index) function pointer
    Vinerows__rosidl_typesupport_introspection_c__resize_function__Vinerow__vinerows  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_members = {
  "sensor_fusion_msgs__msg",  // message namespace
  "Vinerows",  // message name
  2,  // number of fields
  sizeof(sensor_fusion_msgs__msg__Vinerows),
  Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_member_array,  // message members
  Vinerows__rosidl_typesupport_introspection_c__Vinerows_init_function,  // function to initialize message memory (memory has to be allocated)
  Vinerows__rosidl_typesupport_introspection_c__Vinerows_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_type_support_handle = {
  0,
  &Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sensor_fusion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_fusion_msgs, msg, Vinerows)() {
  Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_fusion_msg_types, msg, Vinerow)();
  if (!Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_type_support_handle.typesupport_identifier) {
    Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Vinerows__rosidl_typesupport_introspection_c__Vinerows_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
