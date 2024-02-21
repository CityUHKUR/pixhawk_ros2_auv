from pymavlink import mavutil
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
# from std_msgs.msg import String
from pioneer_msgs.msg import MotionCommand

import sys
import serial

class PixhawkModule(Node):

    def __init__(self):
        super().__init__('pixhawk_module')
        # # Changed to publish Imu type instead of String
        # self.publisher_ = self.create_publisher(Imu, 'imu_data', 1)
        # # Data rate (in seconds) - Adjust as needed for your application
        # timer_period = 0.1  # 10 Hz
        # self.timer = self.create_timer(timer_period, self.timer_callback)
        # self.__status = False
        
        self.subscription = self.create_subscription(
            MotionCommand,
            'movement_topic',
            self.listener_callback,
            10)
        self.subscription # prevent unused variable warning


    # def timer_callback(self):
    #     if not self.__status:
    #         self.__connect()
    #     try:
    #         msg = self.__mavlink_connection.recv_match(type='RAW_IMU', blocking=False)
    #         if msg:
    #             imu_msg = Imu()
    #             imu_msg.linear_acceleration.x = msg.xacc / 1000.0
    #             imu_msg.linear_acceleration.y = msg.yacc / 1000.0
    #             imu_msg.linear_acceleration.z = msg.zacc / 1000.0
    #             imu_msg.angular_velocity.x = msg.xgyro / 1000.0  
    #             imu_msg.angular_velocity.y = msg.ygyro / 1000.0
    #             imu_msg.angular_velocity.z = msg.zgyro / 1000.0
    #             imu_msg.header.stamp = self.get_clock().now().to_msg()
    #             imu_msg.header.frame_id = 'imu_link'  
    #             self.publisher_.publish(imu_msg)
    #     except Exception as e:
    #         self.__status = False
    #         self.get_logger().error('Failed to read IMU data: {}'.format(e))
    #         time.sleep(1)
        
    # def __connect(self):
    #     print("Connecting to Pixhawk...")
    #     try:
    #         self.__mavlink_connection = mavutil.mavlink_connection('/dev/ttyACM0', baud=115200)
    #         self.__mavlink_connection.wait_heartbeat()
    #         # Request IMU data at an appropriate data rate
    #         self.__mavlink_connection.mav.request_data_stream_send(self.__mavlink_connection.target_system,
    #                                                         self.__mavlink_connection.target_component,
    #                                                         mavutil.mavlink.MAV_DATA_STREAM_RAW_SENSORS,
    #                                                         10, 1)  # Adjust rate as needed
    #         self.__status = True
    #         print("Connected to Pixhawk!")
    #     except Exception as e:
    #         self.get_logger().error('Failed to connect to Pixhawk: {}'.format(e))
    #         self.__status = False

    def send_manual_control(self, x, y, z, r):
        self.master.mav.manual_control_send(
            self.target_system,
            x, # forward/background
            y, # strafe left/right
            z, # up/down
            r, # turn left/right
            0)

    def map_to_range(self, value, old_min, old_max, new_min, new_max):
        return ((value - old_min) / (old_max - old_min)) * (new_max - new_min) + new_min    
    
    def listener_callback(self, msg):
        vecx_in = msg.direction.x
        vecy_in = msg.direction.y
        vecz_in = msg.direction.z
        turn_bool = msg.turn_mode
        distance = msg.distance
        time = msg.time
        
        # veclist = msg.split()
        if turn_bool == True:
            vecx = self.map_to_range(float(0), -1,  1, -1000,  1000)
            vecy = self.map_to_range(float(0), -1,  1, -1000,  1000)
            vecz = self.map_to_range(float(0), -1,  1,  0,  1000)
            vecr = self.map_to_range(float(vecy_in), -1,  1, -1000,  1000)
        else:    
            vecx = self.map_to_range(float(vecx_in), -1,  1, -1000,  1000)
            vecy = self.map_to_range(float(vecy_in), -1,  1, -1000,  1000)
            vecz = self.map_to_range(float(vecz_in), -1,  1,  0,  1000)
            vecr = self.map_to_range(float(0), -1,  1, -1000,  1000)
        
            
        print(vecx, vecy, vecz, vecr, turn_bool, distance, time)
        # self.send_manual_control(vecx, vecy, vecz, vecr)

    
    # def vector_control_tl():
    #     while True:  # Keep running until a non-number input is given
    #         try:
    #             print("Please enter four floats between -1 and 1:")
    #             vecstr = input() 
    #             veclist = vecstr.split()
    #             #  vectors = get_float_input("Float 1: ")
    #             # Map each float to the range -1000 to 1000
    #             vecx = map_to_range(float(veclist[0]), -1, 1, -1000, 1000)
    #             vecy = map_to_range(float(veclist[1]), -1, 1, -1000, 1000)
    #             vecz = map_to_range(float(veclist[2]), -1, 1, 0, 1000)
    #             vecr = map_to_range(float(veclist[3]), -1, 1, -1000, 1000)
    #             print(vecx,vecy,vecz,vecr)
    #             send_manual_control(vecx, vecy, vecz, vecr)
    #         except ValueError:
    #             print("Non-number input detected. Exiting the program.")
    #             break  # Exit the loop when a non-number input is given
    
    
        

def main(args=None):
    rclpy.init(args=args)
    pixhawk_module = PixhawkModule()
    rclpy.spin(pixhawk_module)
    pixhawk_module.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
