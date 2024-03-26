import rclpy
from rclpy.node import Node
from sensor_msgs.msg import FluidPressure
from std_msgs.msg import Header
from pioneer_msgs.msg import MotionCommand

import threading
import time


class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.first_callback = True

    def build_subscriber(self):
        self.get_logger().info("Starting depth node subscriber")
        self.subscription = self.create_subscription(
            FluidPressure,
            'sensor_data',
            self.depth_callback,
            10)
        self.get_logger().info("Movement publisher created")
        self.publisher_ = self.create_publisher(MotionCommand, "movement_cmd", 10)
        
        self.subscription  # prevent unused variable warning
        # Initialize configurable parameters
        self.initialize_parameters()

    def initialize_parameters(self):
        # Configurable parameters
        # self.declare_parameter("surface_pressure", 101325)  # Pa
        self.declare_parameter("fluid_density", 997.04)  # kg/m³
        self.declare_parameter("gravity", 9.81)  # m/s²
        self.declare_parameter("max_depth", 2)  # meters

    def publish_movement(self, movement: MotionCommand):
        self.publisher_.publish(movement)
        self.get_logger().debug("Movement published")

    # Move the robot
    # Input: turn_mode (bool) - Boolean to control y component, True if the robot is turning, False if the robot is translating
    #        x (float, 1, 0, -1) - 1 for forward, -1 for backward
    #        y (float, 1, 0, -1) - Turnmode False: 1 for right, -1 for left / Turnmode True: 1 for clockwise, -1 for counterclockwise
    #        z (float, 1, 0, -1) - 1 for up, -1 for down
    #        distance (float) - Distance to move(meters), -1 to disable
    #        duration (float) - Duration to move(seconds), -1 to disable

    def move(
            self,
            turn_mode: bool,
            x: float,
            y: float,
            z: float,
            distance: float = -1,
            duration: float = -1,
    ):
        self.get_logger().info(f"Running movement command: Turn:{turn_mode} x:{x} y:{y} z:{z} distance:{distance} duration:{duration}")

        movement = MotionCommand()
        movement.turn_mode = bool(turn_mode)
        movement.direction.x = float(x)
        movement.direction.y = float(y)
        movement.direction.z = float(z)
        movement.distance = float(distance)
        movement.time = float(duration)

        # Set header
        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = "fucknode"
        movement.header = header

        self.publish_movement(movement)
        self.get_logger().info("Sending movement command")
        if duration > 0:
            self.get_logger().info(f"Sleeping for {duration} seconds")
            time.sleep(duration)
        self.get_logger().info("Finished movement command")


    def calculate_depth(self, fluid_pressure):
        # Get the configurable parameters
        # surface_pressure = self.get_parameter("surface_pressure").value
        fluid_density = self.get_parameter("fluid_density").value
        gravity = self.get_parameter("gravity").value
        max_depth = self.get_parameter("max_depth").value
        # Calculate the depth
        depth = fluid_pressure / (fluid_density * gravity)
        # Ensure the depth is within the pool's maximum depth
        if depth > max_depth:
            depth = max_depth
        return depth

    def depth_callback(self, msg):
        self.get_logger().info("I heard fluid_pressure {}".format(msg.fluid_pressure))
        if self.first_callback:
            self.get_logger().info("sucessfully enter callback function")
            self.first_callback = False

        if hasattr(msg, 'fluid_pressure'):
            depth = self.calculate_depth(msg.fluid_pressure)
            self.get_logger().info(f'Calculated Depth: {depth} meters')
            if (depth > 1.8):
                self.get_logger().warn("Pioneer, sink up")
                self.move(turn_mode=False, x=0, y=0, z=1, duration=1)

            elif (depth < 1.8):
                self.get_logger().warn("Pioneer, sink down")
                self.move(turn_mode=False, x =0, y=0, z= -1, duration=1)

            else:
                self.get_logger().info("Fine, continue to check for depth")
        else:
            self.get_logger().warn("The message does not contain a fluid_pressure field")

    
            
def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = MinimalSubscriber()
    ros_shutdown = False

    def ros_spin():
        nonlocal ros_shutdown
        print("ROS2 Spins")

        try:
            while rclpy.ok():
                rclpy.spin_once(minimal_subscriber, timeout_sec=0.001)  # or other value
        except KeyboardInterrupt:
            pass

        finally:
            if not ros_shutdown:
                rclpy.shutdown()
                ros_shutdown = True

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

    if not ros_shutdown and rclpy.ok():
        minimal_subscriber.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
