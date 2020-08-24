# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from rclpy.time import Time
from rclpy.clock import ClockType

from std_msgs.msg import String
# from sensor_fusion_msgs.msg import Vinerows
# from sensor_fusion_msg_types.msg import Vinerow
from vinerows_msgs.msg import Vinerow
from vinerows_msgs.msg import Vinerowlist


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Vinerowlist, 'lidarVinerows', 10)
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        base_msg = Vinerow()
        base_msg2 = Vinerow()

        msg2 = Vinerowlist()

        base_msg.center.x = 0.10
        base_msg.center.y = 0.10
        base_msg.center.z = -1.05
        base_msg.direction.x = 1.
        base_msg.direction.y = 0.
        base_msg.direction.z = 0.
        base_msg.distance = 20.0
        base_msg.variance = [6.25, 0.0225, 0.0225, 0.0025, 0.0025, 0.0025, 6.25]
        base_msg.is_valid = 1.

        base_msg2.center.x = 0.09
        base_msg2.center.y = 0.65
        base_msg2.center.z = -1.12
        base_msg2.direction.x = 1.
        base_msg2.direction.y = 0.
        base_msg2.direction.z = 0.
        base_msg2.distance = 20.0
        base_msg2.variance = [6.25, 0.0225, 0.0225, 0.0025, 0.0025, 0.0025, 6.25]
        base_msg2.is_valid = 1.

        msg2.header.stamp = self.get_clock().now().to_msg()
        msg2.header.frame_id = str(self.i)

        msg2.vinerows.append(base_msg)
        msg2.vinerows.append(base_msg2)

        self.publisher_.publish(msg2)

        for vinerow in msg2.vinerows:
            self.get_logger().info('Vinerow:\n' +
                        'Direction: {dir_x} {dir_y} {dir_z}\n'.format(dir_x=vinerow.direction.x, dir_y=vinerow.direction.y, dir_z=vinerow.direction.z) +
                        'Center: {center_x} {center_y} {center_z}\n'.format(center_x=vinerow.center.x, center_y=vinerow.center.y, center_z=vinerow.center.z) +
                        'Distance: {dist}\n'.format(dist=vinerow.distance) +
                        'Variance: {var}'.format(var=vinerow.variance)
                         if vinerow.is_valid else 'None valid vinerow data')
        self.get_logger().info('frameID: {id} Time: {sec} {nanosec}'.format(id=msg2.header.frame_id, sec=msg2.header.stamp.sec, nanosec=msg2.header.stamp.nanosec))
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()