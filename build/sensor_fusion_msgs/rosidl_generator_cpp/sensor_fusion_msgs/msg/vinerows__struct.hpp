// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sensor_fusion_msgs:msg/Vinerows.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_HPP_
#define SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/header__struct.hpp"
// Member 'vinerows'
#include "sensor_fusion_msg_types/msg/vinerow__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sensor_fusion_msgs__msg__Vinerows __attribute__((deprecated))
#else
# define DEPRECATED__sensor_fusion_msgs__msg__Vinerows __declspec(deprecated)
#endif

namespace sensor_fusion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vinerows_
{
  using Type = Vinerows_<ContainerAllocator>;

  explicit Vinerows_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Vinerows_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _vinerows_type =
    std::vector<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>::other>;
  _vinerows_type vinerows;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__vinerows(
    const std::vector<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>::other> & _arg)
  {
    this->vinerows = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> *;
  using ConstRawPtr =
    const sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sensor_fusion_msgs__msg__Vinerows
    std::shared_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sensor_fusion_msgs__msg__Vinerows
    std::shared_ptr<sensor_fusion_msgs::msg::Vinerows_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vinerows_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->vinerows != other.vinerows) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vinerows_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vinerows_

// alias to use template instance with default allocator
using Vinerows =
  sensor_fusion_msgs::msg::Vinerows_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sensor_fusion_msgs

#endif  // SENSOR_FUSION_MSGS__MSG__VINEROWS__STRUCT_HPP_
