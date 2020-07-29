// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_demo_custommsg_create:msg/Custom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__FUNCTIONS_H_
#define ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "ros2_demo_custommsg_create/msg/rosidl_generator_c__visibility_control.h"

#include "ros2_demo_custommsg_create/msg/custom__struct.h"

/// Initialize msg/Custom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ros2_demo_custommsg_create__msg__Custom
 * )) before or use
 * ros2_demo_custommsg_create__msg__Custom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
bool
ros2_demo_custommsg_create__msg__Custom__init(ros2_demo_custommsg_create__msg__Custom * msg);

/// Finalize msg/Custom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
void
ros2_demo_custommsg_create__msg__Custom__fini(ros2_demo_custommsg_create__msg__Custom * msg);

/// Create msg/Custom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ros2_demo_custommsg_create__msg__Custom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
ros2_demo_custommsg_create__msg__Custom *
ros2_demo_custommsg_create__msg__Custom__create();

/// Destroy msg/Custom message.
/**
 * It calls
 * ros2_demo_custommsg_create__msg__Custom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
void
ros2_demo_custommsg_create__msg__Custom__destroy(ros2_demo_custommsg_create__msg__Custom * msg);


/// Initialize array of msg/Custom messages.
/**
 * It allocates the memory for the number of elements and calls
 * ros2_demo_custommsg_create__msg__Custom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
bool
ros2_demo_custommsg_create__msg__Custom__Sequence__init(ros2_demo_custommsg_create__msg__Custom__Sequence * array, size_t size);

/// Finalize array of msg/Custom messages.
/**
 * It calls
 * ros2_demo_custommsg_create__msg__Custom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
void
ros2_demo_custommsg_create__msg__Custom__Sequence__fini(ros2_demo_custommsg_create__msg__Custom__Sequence * array);

/// Create array of msg/Custom messages.
/**
 * It allocates the memory for the array and calls
 * ros2_demo_custommsg_create__msg__Custom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
ros2_demo_custommsg_create__msg__Custom__Sequence *
ros2_demo_custommsg_create__msg__Custom__Sequence__create(size_t size);

/// Destroy array of msg/Custom messages.
/**
 * It calls
 * ros2_demo_custommsg_create__msg__Custom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_demo_custommsg_create
void
ros2_demo_custommsg_create__msg__Custom__Sequence__destroy(ros2_demo_custommsg_create__msg__Custom__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ROS2_DEMO_CUSTOMMSG_CREATE__MSG__CUSTOM__FUNCTIONS_H_
