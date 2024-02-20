from pymavlink import mavutil
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu

class IMUPublisher(Node):

    def __init__(self):
        super().__init__('imu_publisher')
        self.publisher_ = self.create_publisher(Imu, 'imu_data', 300)
        timer_period = 1 / 300 # 300hz
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
        print("Connecting to Pixhawk...")
        try:
            self.__init_mavlink()
            self.get_logger().info('Connected to Pixhawk on /dev/ttyACM1')
        except Exception as e:
            try:
                self.__init_mavlink("/dev/ttyACM0")
                self.get_logger().info('Connected to Pixhawk on /dev/ttyACM0')
            except Exception as e:
                self.get_logger().error('Failed to connect to Pixhawk: {}'.format(e))
                self.__status = False
        print("Connected to Pixhawk!")
        self.__status = True
            
    def __init_mavlink(self, device_name="/dev/ttyACM1", rate=300):
        self.__mavlink_connection = mavutil.mavlink_connection(device_name, baud=115200)
        self.__mavlink_connection.wait_heartbeat()
        self.__mavlink_connection.mav.request_data_stream_send(self.__mavlink_connection.target_system,
                                                        self.__mavlink_connection.target_component,
                                                        mavutil.mavlink.MAV_DATA_STREAM_RAW_SENSORS,
                                                        rate, 1)  
        

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = IMUPublisher()
    rclpy.spin(imu_publisher)
    imu_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
