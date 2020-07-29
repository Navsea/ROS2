// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_HPP_
#define SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'dir'
#include "geometry_msgs/msg/vector3__struct.hpp"
// Member 'center'
#include "geometry_msgs/msg/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sensor_fusion_msg_types__msg__Vinerow __attribute__((deprecated))
#else
# define DEPRECATED__sensor_fusion_msg_types__msg__Vinerow __declspec(deprecated)
#endif

namespace sensor_fusion_msg_types
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vinerow_
{
  using Type = Vinerow_<ContainerAllocator>;

  explicit Vinerow_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  : dir(_init),
    center(_init)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist = 0.0;
      std::fill<typename std::array<double, 7>::iterator, double>(this->var.begin(), this->var.end(), 0.0);
      this->is_valid = false;
    }
  }

  explicit Vinerow_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  : dir(_alloc, _init),
    center(_alloc, _init),
    var(_alloc)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->dist = 0.0;
      std::fill<typename std::array<double, 7>::iterator, double>(this->var.begin(), this->var.end(), 0.0);
      this->is_valid = false;
    }
  }

  // field types and members
  using _dir_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _dir_type dir;
  using _center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_type center;
  using _dist_type =
    double;
  _dist_type dist;
  using _var_type =
    std::array<double, 7>;
  _var_type var;
  using _is_valid_type =
    bool;
  _is_valid_type is_valid;

  // setters for named parameter idiom
  Type & set__dir(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__dist(
    const double & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__var(
    const std::array<double, 7> & _arg)
  {
    this->var = _arg;
    return *this;
  }
  Type & set__is_valid(
    const bool & _arg)
  {
    this->is_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> *;
  using ConstRawPtr =
    const sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sensor_fusion_msg_types__msg__Vinerow
    std::shared_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sensor_fusion_msg_types__msg__Vinerow
    std::shared_ptr<sensor_fusion_msg_types::msg::Vinerow_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vinerow_ & other) const
  {
    if (this->dir != other.dir) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->var != other.var) {
      return false;
    }
    if (this->is_valid != other.is_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vinerow_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vinerow_

// alias to use template instance with default allocator
using Vinerow =
  sensor_fusion_msg_types::msg::Vinerow_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sensor_fusion_msg_types

#endif  // SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__STRUCT_HPP_
