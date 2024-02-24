from pymavlink import mavutil
import time
import rclpy
from rclpy.node import Node
from rclpy.time import Time
from sensor_msgs.msg import Imu
# from std_msgs.msg import String
from pioneer_msgs.msg import MotionCommand
import queue

import sys
import serial

class PixhawkModule(Node):

    def __init__(self):
        super().__init__('pixhawk_module')
        
        self.subscription = self.create_subscription(
            MotionCommand,
            'movement_topic',
            self.listener_callback,
            10)
        self.subscription # prevent unused variable warning
        self.last_msg_time = None
        depth_list= queue.Queue()
        task_list= queue.Queue()
        statem_list= queue.Queue()
        depth_load= None
        task_load= None
        statem_load= None
        

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
    
    # def if time < 2 sec:
    #   send cmd to cut motors
    # else > 2sec run that cmd for that time
    def loader_refresh():
        depth_load = depth_list.get()
        task_load = task_list.get()
        statem_load = statem_list.get()
    
    def listener_callback(self, msg):
        vecx_in = msg.direction.x
        vecy_in = msg.direction.y
        vecz_in = msg.direction.z
        turn_bool = msg.turn_mode
        distance = msg.distance
        time = msg.time
        header_sender = msg.header.frame_id
        
        time_diff = 0
        
        if header_sender == "depth_node":
            depth_list.put(msg)
        elif header_sender == "task_node":
            task_list.put(msg)    
        elif header_sender == "statem_node":
            statem_list.put(msg)    
            
        loader_refresh()
        
        
        current_time = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9 
        if self.last_msg_time is not None:
            time_diff = current_time - self.last_msg_time
        self.last_msg_time = current_time  # Update the last message time
        
        # if header_sender == "depth_node":
        #     depth_list.append(msg)
            
        #     vecx = self.map_to_range(float(vecx_in), -1,  1, -1000,  1000)
        #     vecy = self.map_to_range(float(0), -1,  1, -1000,  1000)
        #     vecz = self.map_to_range(float(vecz_in), -1,  1,  0,  1000)
        #     vecr = self.map_to_range(float(0), -1,  1, -1000,  1000)
        
        
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
          
        print(vecx, vecy, vecz, vecr, turn_bool, distance, time, time_diff, current_time)
        # if time < 2.0:
        #     self.send_manual_control(vecx, vecy, vecz, vecr)
        #     time.sleep(time)
        #     self.send_manual_control(0, 0, 0, 0)
        # else:
                
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
