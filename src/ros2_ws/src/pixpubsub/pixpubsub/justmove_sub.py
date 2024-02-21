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

    # priority[] = 
    # depth sensor control
    

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
        header_sender = msg.header.frame_id
        depth_list= []
        task_list= []
        moveguide_list= []
        if header_sender == "depth_node":
            depth_list.append(msg)
            
            vecx = self.map_to_range(float(vecx_in), -1,  1, -1000,  1000)
            vecy = self.map_to_range(float(0), -1,  1, -1000,  1000)
            vecz = self.map_to_range(float(vecz_in), -1,  1,  0,  1000)
            vecr = self.map_to_range(float(0), -1,  1, -1000,  1000)
        
        
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
        
        # for i in range(0, time):
        #     turnLeft()
        #     print('moving ')
        #     time.sleep(1)
          
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
