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

from sensor_fusion_msgs.msg import Vinerows

global_variable_test = 15

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('receive_sensor_fusion_data')
        self.subscription = self.create_subscription(
            Vinerows,
            'sensorFusion',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        for vinerow in msg.vinerows:
            self.get_logger().info('Vinerow:\n' +
                                   'Direction: {dir_x} {dir_y} {dir_z}\n'.format(dir_x=vinerow.dir.x,
                                                                                 dir_y=vinerow.dir.y,
                                                                                 dir_z=vinerow.dir.z) +
                                   'Center: {center_x} {center_y} {center_z}\n'.format(center_x=vinerow.center.x,
                                                                                       center_y=vinerow.center.y,
                                                                                       center_z=vinerow.center.z) +
                                   'Distance: {dist}\n'.format(dist=vinerow.dist) +
                                   'Variance: {var}'.format(
                                       var=vinerow.var) if vinerow.is_valid else 'None valid vinerow data')


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
