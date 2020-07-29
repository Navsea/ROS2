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

from std_msgs.msg import String
from sensor_fusion_msgs.msg import Vinerows

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Vinerows, 'sensorFusion', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg2 = Vinerows()

        msg2.vinerows[0].dir.x = 0.3
        msg2.vinerows[0].dir.y = 0.3
        msg2.vinerows[0].dir.z = 0.3
        msg2.vinerows[0].center.x = 0.10
        msg2.vinerows[0].center.y = 0.10
        msg2.vinerows[0].center.z = -1.05
        msg2.vinerows[0].dist = 20.0
        msg2.vinerows[0].var = [0.3, 0.3, 0.3, 0.03, 0.03, 0.03, 0.15]
        msg2.vinerows[0].is_valid = True
        self.publisher_.publish(msg2)

        for vinerow in msg2.vinerows:
            self.get_logger().info('Vinerow:\n' +
                        'Direction: {dir_x} {dir_y} {dir_z}\n'.format(dir_x=vinerow.dir.x, dir_y=vinerow.dir.y, dir_z=vinerow.dir.z) +
                        'Center: {center_x} {center_y} {center_z}\n'.format(center_x=vinerow.center.x, center_y=vinerow.center.y, center_z=vinerow.center.z) +
                        'Distance: {dist}\n'.format(dist=vinerow.dist) +
                        'Variance: {var}'.format(var=vinerow.var) if vinerow.is_valid else 'None valid vinerow data')
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