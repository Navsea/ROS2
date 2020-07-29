// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensor_fusion_msg_types:msg/Vinerow.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__FUNCTIONS_H_
#define SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "sensor_fusion_msg_types/msg/rosidl_generator_c__visibility_control.h"

#include "sensor_fusion_msg_types/msg/vinerow__struct.h"

/// Initialize msg/Vinerow message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sensor_fusion_msg_types__msg__Vinerow
 * )) before or use
 * sensor_fusion_msg_types__msg__Vinerow__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
bool
sensor_fusion_msg_types__msg__Vinerow__init(sensor_fusion_msg_types__msg__Vinerow * msg);

/// Finalize msg/Vinerow message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
void
sensor_fusion_msg_types__msg__Vinerow__fini(sensor_fusion_msg_types__msg__Vinerow * msg);

/// Create msg/Vinerow message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sensor_fusion_msg_types__msg__Vinerow__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
sensor_fusion_msg_types__msg__Vinerow *
sensor_fusion_msg_types__msg__Vinerow__create();

/// Destroy msg/Vinerow message.
/**
 * It calls
 * sensor_fusion_msg_types__msg__Vinerow__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
void
sensor_fusion_msg_types__msg__Vinerow__destroy(sensor_fusion_msg_types__msg__Vinerow * msg);


/// Initialize array of msg/Vinerow messages.
/**
 * It allocates the memory for the number of elements and calls
 * sensor_fusion_msg_types__msg__Vinerow__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
bool
sensor_fusion_msg_types__msg__Vinerow__Sequence__init(sensor_fusion_msg_types__msg__Vinerow__Sequence * array, size_t size);

/// Finalize array of msg/Vinerow messages.
/**
 * It calls
 * sensor_fusion_msg_types__msg__Vinerow__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
void
sensor_fusion_msg_types__msg__Vinerow__Sequence__fini(sensor_fusion_msg_types__msg__Vinerow__Sequence * array);

/// Create array of msg/Vinerow messages.
/**
 * It allocates the memory for the array and calls
 * sensor_fusion_msg_types__msg__Vinerow__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
sensor_fusion_msg_types__msg__Vinerow__Sequence *
sensor_fusion_msg_types__msg__Vinerow__Sequence__create(size_t size);

/// Destroy array of msg/Vinerow messages.
/**
 * It calls
 * sensor_fusion_msg_types__msg__Vinerow__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor_fusion_msg_types
void
sensor_fusion_msg_types__msg__Vinerow__Sequence__destroy(sensor_fusion_msg_types__msg__Vinerow__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // SENSOR_FUSION_MSG_TYPES__MSG__VINEROW__FUNCTIONS_H_
