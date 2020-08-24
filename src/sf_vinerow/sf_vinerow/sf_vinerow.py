import rclpy
from rclpy.node import Node
from vinerows_msgs.msg import Vinerow
from vinerows_msgs.msg import Vinerowlist
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
import sf_vinerow.kalman.vinerow_filter as vinerow_filter
import numpy as np

ENABLE_REPORTING = True


# vinerow lidar ros2 subscriber module
class VinerowLidarSub(Node):
    def __init__(self):
        super().__init__('Initializing_ROS2_lidar_receive_module')
        self.subscription = self.create_subscription(
            Vinerowlist,
            'lidarVinerows',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.msg_flg = False
        self.msg = None
        self.ENABLE_RECEIVE_REPORTING = False

    def listener_callback(self, msg):
        self.msg = msg
        if self.ENABLE_RECEIVE_REPORTING:
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


# vinerow camera ros2 module
class VinerowCameraSub(Node):
    def __init__(self):
        super().__init__('Initializing_ROS2_vinerow_camera_receive_module')
        self.subscription = self.create_subscription(
            Vinerowlist,
            'cameraVinerows',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.msg_flg = False
        self.msg = None
        self.ENABLE_RECEIVE_REPORTING = False

    def listener_callback(self, msg):
        self.msg = msg
        if self.ENABLE_RECEIVE_REPORTING:
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


class VinerowFusionPub(Node):

    def __init__(self):
        super().__init__('Initializing_ROS2_vinerow_sf_module')
        self.publisher_ = self.create_publisher(Vinerowlist, 'fusionVinerows', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.send = False
        self.msg = None

    def timer_callback(self):
        self.send = True
        self.msg = Vinerowlist()
        self.msg.header.stamp = self.get_clock().now().to_msg()
        self.msg.header.frame_id = str(self.i)

        self.i += 1


class VinerowFusionVizPub(Node):

    def __init__(self):
        super().__init__('Initializing_ROS2_vinerow_sf_vizualization_module')
        self.publisher_ = self.create_publisher(Marker, 'rviz_fusion_vinerows', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.send = False
        self.msg = None

    def timer_callback(self):
        self.send = True
        self.msg = Marker()
        self.msg.header.stamp = self.get_clock().now().to_msg()
        self.msg.header.frame_id = "rig"

        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    # instantiate all ROS components
    vinerow_lidar_subscriber = VinerowLidarSub()
    vinerow_camera_subscriber = VinerowCameraSub()
    vinerow_fusion_publisher = VinerowFusionPub()
    vinerow_fusion_viz_publisher = VinerowFusionVizPub()

    # instantiate the executor that will handle all the component callbacks
    executor = rclpy.executors.SingleThreadedExecutor()

    # add all ROS components to the executor
    executor.add_node(vinerow_lidar_subscriber)
    executor.add_node(vinerow_camera_subscriber)
    executor.add_node(vinerow_fusion_publisher)
    executor.add_node(vinerow_fusion_viz_publisher)

    # instantiate the vinerow filter
    kf_vinerow = vinerow_filter.VinerowFilter()

    while rclpy.ok():
        # execute one of the callbacks
        executor.spin_once()

        if vinerow_lidar_subscriber.msg_flg:
            if ENABLE_REPORTING:
                print("received lidar message")
            vinerow_lidar_subscriber.msg_flg = False
            kf_vinerow.process_measurements(vinerow_lidar_subscriber.msg)
            kf_vinerow.predict()
            if ENABLE_REPORTING:
                print("after predict sate vector: ", kf_vinerow.kfs[3].x)
            kf_vinerow.update()
            if ENABLE_REPORTING:
                print("after update sate vector: ", kf_vinerow.kfs[3].x)

        if vinerow_camera_subscriber.msg_flg:
            if ENABLE_REPORTING:
                print("received camera message")
            vinerow_camera_subscriber.msg_flg = False
            kf_vinerow.process_measurements(vinerow_camera_subscriber.msg)
            kf_vinerow.predict()
            if ENABLE_REPORTING:
                print("after predict sate vector: ", kf_vinerow.kfs[3].x)
            kf_vinerow.update()
            if ENABLE_REPORTING:
                print("after update sate vector: ", kf_vinerow.kfs[3].x)

        # sf publisher callback was triggered
        if vinerow_fusion_viz_publisher.send:
            print("SENDING VIZ")
            vinerow_fusion_viz_publisher.send = False

            # set namespace, id, type of shape and action type
            vinerow_fusion_viz_publisher.msg.ns = "rviz_fusion_vinerows"
            vinerow_fusion_viz_publisher.msg.id = 0
            vinerow_fusion_viz_publisher.msg.type = vinerow_fusion_viz_publisher.msg.LINE_LIST
            vinerow_fusion_viz_publisher.msg.action = vinerow_fusion_viz_publisher.msg.ADD

            # set color & alpha
            vinerow_fusion_viz_publisher.msg.color.r = 0.
            vinerow_fusion_viz_publisher.msg.color.g = 1.
            vinerow_fusion_viz_publisher.msg.color.b = 0.
            vinerow_fusion_viz_publisher.msg.color.a = .5

            # set up shape
            vinerow_fusion_viz_publisher.msg.pose.position.x = 0.
            vinerow_fusion_viz_publisher.msg.pose.position.y = 0.
            vinerow_fusion_viz_publisher.msg.pose.position.z = 0.
            vinerow_fusion_viz_publisher.msg.pose.orientation.x = 0.
            vinerow_fusion_viz_publisher.msg.pose.orientation.y = 0.
            vinerow_fusion_viz_publisher.msg.pose.orientation.z = 0.
            vinerow_fusion_viz_publisher.msg.pose.orientation.w = 1.

            vinerow_fusion_viz_publisher.msg.scale.x = 1.
            vinerow_fusion_viz_publisher.msg.scale.y = 1.
            vinerow_fusion_viz_publisher.msg.scale.z = 1.

            for i,kf in enumerate(kf_vinerow.kfs):
                if kf_vinerow.z[i][7]:
                    point = Point(x=0., y=0., z=0.)
                    point.x = kf.x[0] - 3 * kf.x[3]
                    point.y = kf.x[1] - 3 * kf.x[4]
                    point.z = kf.x[2] - 3 * kf.x[5]
                    point2 = Point(x=0., y=0., z=0.)
                    point2.x = kf.x[0] + 3 * kf.x[3]
                    point2.y = kf.x[1] + 3 * kf.x[4]
                    point2.z = kf.x[2] + 3 * kf.x[5]
                    vinerow_fusion_viz_publisher.msg.points.append(point)
                    vinerow_fusion_viz_publisher.msg.points.append(point2)

            vinerow_fusion_viz_publisher.publisher_.publish(vinerow_fusion_viz_publisher.msg)

        # sf publisher callback was triggered
        if vinerow_fusion_publisher.send:
            print("SENDING")
            kf_vinerow.predict()
            vinerow_fusion_publisher.send = False
            base_msg = Vinerow()
            for kf in kf_vinerow.kfs:
                base_msg.center.x = kf.x[0]
                base_msg.center.y = kf.x[1]
                base_msg.center.z = kf.x[2]
                base_msg.direction.x = kf.x[3]
                base_msg.direction.y = kf.x[4]
                base_msg.direction.z = kf.x[5]
                base_msg.distance = kf.x[6]
                base_msg.variance = np.diagonal(kf.P)
                base_msg.is_valid = 1.

                vinerow_fusion_publisher.msg.vinerows.append(base_msg)

            vinerow_fusion_publisher.publisher_.publish(vinerow_fusion_publisher.msg)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    executor.shutdown()
    vinerow_lidar_subscriber.destroy_node()
    vinerow_camera_subscriber.destroy_node()
    vinerow_fusion_publisher.destroy_node()
    vinerow_fusion_viz_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
