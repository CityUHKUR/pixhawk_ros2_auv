from pymavlink import mavutil
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, FluidPressure
from pioneer_msgs.msg import MotionCommand
from .bank_msg import bank_msg

class PixhawkModule(Node):

    def __init__(self):
        super().__init__('pixhawk_module')
        # init movtion command list as a dictionary
        # each key corresponds to a list of commands recieved from a specific node
        self.command_bank = {
            "depth_node": [],
            "task_node": [],
            "sm_node": []
        }       
        self.command_loader = {}
        self.ALLOW_RANGE = 0.5
        
        # Changed to publish Imu type instead of String
        self.publisher_imu = self.create_publisher(Imu, 'imu_data', 1)
        self.publisher_sensor = self.create_publisher(FluidPressure, 'sensor_data', 1)
        # Data rate (in seconds) - Adjust as needed for your application
        timer_period = 0.1  # 10 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.__status = False
        rate = 0.1
        self.control_timer = self.create_timer(rate, self.control_callback)
        
        self.subscription = self.create_subscription(
            MotionCommand,
            'movement_cmd',
            self.listener_callback,
            10)
        self.subscription # prevent unused variable warning
    
    def armFunc(self):
        master = self.__mavlink_connection
        master.mav.command_long_send(
            master.target_system,
            master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            1, 0, 0, 0, 0, 0, 0)
        # wait until arming confirmed (can manually check with master.motors_armed())
        print("Waiting for the vehicle to arm")
        master.motors_armed_wait()
        print('Armed!')
        
    
    def modeSetFunc(self, mode='MANUAL'):
        # mode section, tbh dont get
        # mode = 'STABILIZE'
        # mode = 'MANUAL'
        # mode = 'ALT_HOLD'
        mode_id = self.__mavlink_connection.mode_mapping()[mode]
        self.__mavlink_connection.mav.set_mode_send(
            self.__mavlink_connection.target_system,
            mavutil.mavlink.MAV_MODE_FLAG_CUSTOM_MODE_ENABLED,
            mode_id)
        self.get_logger().info('{} mode set!'.format(mode))
        
    def timer_callback(self):
        if not self.__status:
            self.__connect()
            
        
        try:
            self.send_imu_msg()
            self.send_sensor_msg()
        except Exception as e:
            self.__status = False
            self.get_logger().error('Failed to read IMU data: {}'.format(e))
            time.sleep(1)

    def send_imu_msg(self):
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
            self.publisher_imu.publish(imu_msg)
    
    def send_sensor_msg(self):
        msg = self.__mavlink_connection.recv_match(type='RAW_PRESSURE', blocking=False)
        if msg:
            sensor_msg = FluidPressure()
            sensor_msg.fluid_pressure = msg.press_abs
            sensor_msg.header.stamp = self.get_clock().now().to_msg()
            sensor_msg.header.frame_id = 'pixhawk_node'
            sensor_msg.variance = 0.0
            self.publisher_sensor.publish(sensor_msg)
    
    def __connect(self):
        print("Connecting to Pixhawk...")
        try:
            self.__mavlink_connection = mavutil.mavlink_connection('/dev/ttyACM1', baud=115200)
            self.__mavlink_connection.wait_heartbeat()
            # Request IMU data at an appropriate data rate
            self.__mavlink_connection.mav.request_data_stream_send(self.__mavlink_connection.target_system,
                                                            self.__mavlink_connection.target_component,
                                                            mavutil.mavlink.MAV_DATA_STREAM_RAW_SENSORS,
                                                            10, 1)  # Adjust rate as needed
            self.__status = True
            print("Connected to Pixhawk!")
            self.modeSetFunc(mode='ALT_HOLD')
            self.armFunc()
        except Exception as e:
            self.get_logger().error('Failed to connect to Pixhawk: {}'.format(e))
            self.__status = False



    def load_command(self, node_name,preepmtive=False):
        if len(self.command_bank[node_name]) <= 0: return
        if preepmtive:
            self.command_loader[node_name] = self.command_bank[node_name].pop(0)
            self.command_loader[node_name].start_time = time.time()
            self.command_loader[node_name].end_time = time.time() + self.command_loader[node_name].time
        
        # TODO: implement time based command loading
        if self.command_loader[node_name].end_time < time.time():
            self.command_loader[node_name] = self.command_bank[node_name].pop(0)
            self.command_loader[node_name].start_time = time.time()

        

    def control_callback(self):
        # remove commands that have expired
        self.get_logger().info(f'Executing: "{self.command_bank}"')
        for key in self.command_bank:
            if len(self.command_bank[key]) <= 0: continue
            # find all index of the expired command
            __expired_index = []
            for i in range(len(self.command_bank[key])):
                if self.command_bank[key][i].end_time < time.time(): __expired_index.append(i)
            # remove all expired commands
            self.command_bank[key].pop(i for i in __expired_index)
        
        # load commands from command bank into command loader
        self.load_command("depth_node", preepmtive=True)
        self.load_command("task_node")
        self.load_command("sm_node")
        
        # compute the command to be executed
        __command = {"x": 0, "y": 0, "z": 0, "r": 0}
        for key in self.command_loader:
            __this_command = self.command_loader[key]
            if __this_command == None: continue
            __x, __y, __z, __r = __this_command.to_xyzr()
            __command["x"] += __x
            __command["y"] += __y
            __command["z"] += __z
            __command["r"] += __r
            
        self.send_manual_control(__command["x"], __command["y"], __command["z"], __command["r"])
        self.get_logger().info(f'Executing: "{__command}"')    



    def send_manual_control(self, x, y, z, r):
        self.__mavlink_connection.mav.manual_control_send(
            self.__mavlink_connection.target_system,
            x, # forward/background
            y, # strafe left/right
            z, # up/down
            r, # turn left/right
            0)
    
    def listener_callback(self, msg):
        __frame_id = msg.header.frame_id
        
        if msg.distance != -1:
            # TODO: implement distance to time conversion
            pass
        
        if msg.time == -1:
            msg.time = 1
        
        msg_ = bank_msg(x=msg.direction.x, y=msg.direction.y, z=msg.direction.z, turn_mode=msg.turn_mode, distance=msg.distance, time_=msg.time) 
        if __frame_id == "depth_node":
            self.command_bank["depth_node"].append(msg_)
        if __frame_id == "task1_node" or __frame_id == "task2_node" or __frame_id == "task4_node":
            self.command_bank["task_node"].append(msg_)
        if __frame_id == "sm_node":
            self.command_bank["sm_node"].append(msg_)

def main(args=None):
    rclpy.init(args=args)
    pixhawk_module = PixhawkModule()
    rclpy.spin(pixhawk_module)
    pixhawk_module.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
