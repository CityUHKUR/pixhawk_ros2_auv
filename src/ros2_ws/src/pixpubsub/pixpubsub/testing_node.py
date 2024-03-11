import rclpy
from rclpy.node import Node
# from std_msgs.msg import String
from pioneer_msgs.msg import MotionCommand
import time

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(MotionCommand, 'movement_cmd',  10)
        self.declare_parameter('bool_param', rclpy.Parameter.Type.BOOL, default_value=False)
        self.declare_parameter('double_array_param', rclpy.Parameter.Type.DOUBLE_ARRAY, default_value=[1.0, 0.0, 0.0])

        # param_bl = self.get_parameter('turn_bl')
        # param_arr = self.get_parameter('vector_arr')
        # self.get_logger().info("bool: %s, double[]: %s" %
        #                     (str(param_bl.value),
        #                     str(param_arr.value),))
        self.i =  0

    def send_msg(self, turnin, xin, yin, zin, disin, timein):
        msg = MotionCommand()
        msg.header.stamp = self.get_clock().now().to_msg()  # Set the timestamp
        msg.header.frame_id = "depth_node"
        msg.turn_mode = turnin
        msg.direction.x = xin
        msg.direction.y = yin
        msg.direction.z = zin
        msg.distance = disin
        msg.time = timein
        self.publisher_.publish(msg)
        return msg
        
    # count = 0    
    def cmd_selector(self, count):
        match count:
            case  0:
                return self.send_msg(False,   1.0,   0.0,   0.0,   1.0,   0.0)
            case  1:
                return self.send_msg(False, -1.0,   0.0,   0.0,   1.0,   0.0)
            case  2:
                return self.send_msg(False,   0.0, -1.0,   0.0,   1.0,   0.0)
            case  3:
                return self.send_msg(False,   0.0,   1.0,   0.0,   1.0,   0.0)
            case  4: #go up
                return self.send_msg(False,   0.0,   0.0,   1.0,   1.0,   0.0)
            case  5:
                return self.send_msg(False,   0.0,   0.0, -1.0,   1.0,   0.0)
            case  6:
                return self.send_msg(True,   0.0,   1.0,   0.0,   1.0,   0.0)
            case  7:
                return self.send_msg(True,   0.0, -1.0,   0.0,   1.0,   0.0)
            case  8:  # Use _ for default case in Python  3.10
                return self.send_msg(True,   0.0, 0.0,   0.0,   1.0,   0.0)


    def publish_motion_command(self):
        bool_param = self.get_parameter('bool_param').value
        double_array_param = self.get_parameter('double_array_param').value
        
        self.get_logger().info("bool: %s, double[]: %s" %
                               (str(bool_param),
                                str(double_array_param),))
        
        x, y, z = double_array_param
        while True:
            self.send_msg(bool_param, x, y, z, 1.0, 0.0)

        time.sleep(6)
        # for i in range(8): # should go up
        #     msg = self.cmd_selector(4)
        #     self.get_logger().info(f'Publishing: "{msg}"')
        #     time.sleep(1)
        # self.get_logger().info('Publishing completed.')
        # for i in range(8): # should go up
        #     msg = self.cmd_selector(0)
        #     self.get_logger().info(f'Publishing: "{msg}"')
        #     time.sleep(1)
        # self.get_logger().info('Publishing completed.')
        
        # for i in range(8):  # Loop from  0 to  7
        #     msg = self.cmd_selector(i)
        #     self.get_logger().info(f'Publishing: "{msg}"')
        #     time.sleep(1)
        # self.get_logger().info('Publishing completed.')
        
        # for i in range(8):  # Loop from  0 to  7
        #     msg = self.cmd_selector(i)
        #     self.get_logger().info(f'Publishing: "{msg}"')
        #     time.sleep(5)
        # self.get_logger().info('Publishing completed.')
        
        # msg = self.cmd_selector(8)
        # self.get_logger().info(f'Publishing: "{msg}"')
        # time.sleep(1)
        # self.get_logger().info('Publishing completed.')
        
        


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    minimal_publisher.publish_motion_command()

    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
