import rclpy
from rclpy.node import Node
# from std_msgs.msg import String
from pioneer_msgs.msg import MotionCommand

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(MotionCommand, 'movement_topic',  10)
        self.i =  0
        self.timer = self.create_timer(2.0, self.publish_motion_command)

    def publish_motion_command(self):
        msg = MotionCommand()
        msg.header.stamp = self.get_clock().now().to_msg()  # Set the timestamp
        msg.header.frame_id = "testing_node"
        msg.turn_mode = False  # Example value
        msg.direction.x =  1.0  # Example value
        msg.direction.y =  0.9  # Example value
        msg.direction.z =  -0.3  # Example value
        msg.distance =  1.0  # Example value
        msg.time =  0.0  # Example value
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg)

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    while rclpy.ok():
        minimal_publisher.publish_motion_command()

    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
