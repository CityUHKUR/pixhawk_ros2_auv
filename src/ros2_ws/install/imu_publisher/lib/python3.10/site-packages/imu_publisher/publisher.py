from pymavlink import mavutil
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu

class IMUPublisher(Node):

    def __init__(self):
        super().__init__('imu_publisher')
        # Changed to publish Imu type instead of String
        self.publisher_ = self.create_publisher(Imu, 'imu_data', 10)
        # Data rate (in seconds) - Adjust as needed for your application
        timer_period = 0.1  # 10 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.__status = False

    def timer_callback(self):
        if not self.__status:
            self.__connect()
        try:
            msg = self.__mavlink_connection.recv_match(type='RAW_IMU', blocking=False)
            if msg:
                imu_msg = Imu()
                imu_msg.linear_acceleration.x = msg.xacc / 1000.0
                imu_msg.linear_acceleration.y = msg.yacc / 1000.0
                imu_msg.linear_acceleration.z = msg.zacc / 1000.0
                imu_msg.angular_velocity.x = msg.xgyro / 1000.0  
                imu_msg.angular_velocity.y = msg.ygyro / 1000.0
                imu_msg.angular_velocity.z = msg.zgyro / 1000.0
                imu_msg.header.stamp = self.get_clock().now().to_msg()
                imu_msg.header.frame_id = 'imu_link'  
                self.publisher_.publish(imu_msg)
        except Exception as e:
            self.__status = False
            self.get_logger().error('Failed to read IMU data: {}'.format(e))
            time.sleep(1)
        
    def __connect(self):
        try:
            self.__mavlink_connection = mavutil.mavlink_connection('/dev/ttyACM0', baud=115200)
            self.__mavlink_connection.wait_heartbeat()
            # Request IMU data at an appropriate data rate
            self.__mavlink_connection.mav.request_data_stream_send(self.__mavlink_connection.target_system,
                                                            self.__mavlink_connection.target_component,
                                                            mavutil.mavlink.MAV_DATA_STREAM_RAW_SENSORS,
                                                            10, 1)  # Adjust rate as needed
            self.__status = True
        except Exception as e:
            self.get_logger().error('Failed to connect to Pixhawk: {}'.format(e))
            self.__status = False

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = IMUPublisher()
    rclpy.spin(imu_publisher)
    imu_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
