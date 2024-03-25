import rclpy
from rclpy.node import Node
from sensor_msgs.msg import FluidPressure
import threading
import time

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.last_msg_time = self.get_clock().now()

    def build_subscriber(self):
        self.get_logger().info("Starting depth node")
        self.subscription = self.create_subscription(
            FluidPressure,
            'sensor_data',
            self.depth_callback,
            10)
        
        self.subscription  # prevent unused variable warning
        # Initialize configurable parameters
        self.initialize_parameters()
        self.timer = self.create_timer(1.0, self.check_for_messages)

    def initialize_parameters(self):
        # Configurable parameters
        self.declare_parameter("surface_pressure", 101325)  # Pa
        self.declare_parameter("fluid_density", 1025)  # kg/m³
        self.declare_parameter("gravity", 9.81)  # m/s²
        self.declare_parameter("max_depth", 0.5)  # meters

    def calculate_depth(self, fluid_pressure):
        # Get the configurable parameters
        surface_pressure = self.get_parameter("surface_pressure").value
        fluid_density = self.get_parameter("fluid_density").value
        gravity = self.get_parameter("gravity").value
        max_depth = self.get_parameter("max_depth").value
        # Calculate the depth
        depth = (fluid_pressure - surface_pressure) / (fluid_density * gravity)
        # Ensure the depth is within the pool's maximum depth
        if depth > max_depth:
            depth = max_depth
        return depth

    def depth_callback(self, msg):
        self.get_logger().info("I heard msg {}".format(msg))
        self.last_msg_time = self.get_clock().now()
        # Check if the 'fluid_pressure' field exists in the message
        try:
            if hasattr(msg, 'fluid_pressure'):
                depth = self.calculate_depth(msg.fluid_pressure)
                print(f'Calculated Depth: {depth} meters')
                self.get_logger().info("Float")
            else:
                self.get_logger().info('The message does not contain a fluid_pressure field')
        except:
            self.get_logger().warn("fuck")
            pass

    def check_for_messages(self):
        # If it's been more than a second since the last message
        if self.get_clock().now() - self.last_msg_time > rclpy.duration.Duration(seconds=1):
            self.get_logger().info('The message does not contain a fluid_pressure field')

            
def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = MinimalSubscriber()

    def ros_spin():
        print("ROS2 Spins")
        try:
            while rclpy.ok():
                rclpy.spin_once(minimal_subscriber, timeout_sec=0.001)  # or other value
        except KeyboardInterrupt:
            pass

    ros_thread = threading.Thread(target=ros_spin, args=())
    ros_thread.start()
    time.sleep(0)
    minimal_subscriber.build_subscriber()
    # Main thread
    print("Main thread begins")
    while True:
        try:
            time.sleep(1)
        except KeyboardInterrupt:
            break

    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
