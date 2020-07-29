// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_generator_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sensor_fusion_msgs/msg/vinerows__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace sensor_fusion_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Vinerows_init_function(
  void * message_memory, rosidl_generator_cpp::MessageInitialization _init)
{
  new (message_memory) sensor_fusion_msgs::msg::Vinerows(_init);
}

void Vinerows_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sensor_fusion_msgs::msg::Vinerows *>(message_memory);
  typed_message->~Vinerows();
}

size_t size_function__Vinerows__vinerows(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__Vinerows__vinerows(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<sensor_fusion_msg_types::msg::Vinerow, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__Vinerows__vinerows(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<sensor_fusion_msg_types::msg::Vinerow, 7> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Vinerows_message_member_array[1] = {
  {
    "vinerows",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_fusion_msg_types::msg::Vinerow>(),  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(sensor_fusion_msgs::msg::Vinerows, vinerows),  // bytes offset in struct
    nullptr,  // default value
    size_function__Vinerows__vinerows,  // size() function pointer
    get_const_function__Vinerows__vinerows,  // get_const(index) function pointer
    get_function__Vinerows__vinerows,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Vinerows_message_members = {
  "sensor_fusion_msgs::msg",  // message namespace
  "Vinerows",  // message name
  1,  // number of fields
  sizeof(sensor_fusion_msgs::msg::Vinerows),
  Vinerows_message_member_array,  // message members
  Vinerows_init_function,  // function to initialize message memory (memory has to be allocated)
  Vinerows_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Vinerows_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Vinerows_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace sensor_fusion_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sensor_fusion_msgs::msg::Vinerows>()
{
  return &::sensor_fusion_msgs::msg::rosidl_typesupport_introspection_cpp::Vinerows_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sensor_fusion_msgs, msg, Vinerows)() {
  return &::sensor_fusion_msgs::msg::rosidl_typesupport_introspection_cpp::Vinerows_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
