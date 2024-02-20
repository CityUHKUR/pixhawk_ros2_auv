import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(String, 'topic',  10)
        self.i =  0

    def publish_string(self):
        msg = String()
        msg.data = input("Enter a string to publish: ")
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i +=  1

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    while rclpy.ok():
        minimal_publisher.publish_string()

    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
