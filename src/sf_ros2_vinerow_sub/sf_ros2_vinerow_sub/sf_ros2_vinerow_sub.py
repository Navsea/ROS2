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

import threading

import rclpy
from rclpy.node import Node
from dataclasses import dataclass
import numpy as np

from sensor_fusion_msgs.msg import Vinerows

import sf_ros2_vinerow_sub.kalman.vinerow_filter as vinerow_filter

class VinerowSub(Node):

    def __init__(self):
        super().__init__('receive_sensor_fusion_data')
        self.subscription = self.create_subscription(
            Vinerows,
            'sensorFusion',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.msg_flg = False
        self.msg = None


    def listener_callback(self, msg):
        self.msg = msg
        for vinerow in msg.vinerows:
            self.get_logger().info('Vinerow:\n' +
                                   'Direction: {dir_x} {dir_y} {dir_z}\n'.format(dir_x=vinerow.direction.x,
                                                                                 dir_y=vinerow.direction.y,
                                                                                 dir_z=vinerow.direction.z) +
                                   'Center: {center_x} {center_y} {center_z}\n'.format(center_x=vinerow.center.x,
                                                                                       center_y=vinerow.center.y,
                                                                                       center_z=vinerow.center.z) +
                                   'Distance: {dist}\n'.format(dist=vinerow.distance) +
                                   'Variance: {var}'.format(
                                       var=vinerow.variance) if vinerow.is_valid else 'None valid vinerow data')

        # indicate that we received a message
        self.msg_flg = True


def main(args=None):
    rclpy.init(args=args)

    vinerow_subscriber = VinerowSub()

    kf_vinerow = vinerow_filter.SfVinerow()

    while rclpy.ok():
        rclpy.spin_once(vinerow_subscriber)

        if vinerow_subscriber.msg_flg:
            vinerow_subscriber.msg_flg = False
            kf_vinerow.process_measurements(vinerow_subscriber.msg)
            kf_vinerow.predict()
            print("after predict sate vector: ", kf_vinerow.kfs[0].x)
            kf_vinerow.update()
            print("after update sate vector: ", kf_vinerow.kfs[0].x)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    vinerow_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
