import sys
from pymavlink import mavutil
import time
import serial

SERIALPORT='/dev/ttyACM0'
baud = 115200
timex = 5
ser = serial.Serial(port=SERIALPORT, baudrate=baud, timeout=timex)
ser.write("1\n".encode())
master = mavutil.mavlink_connection('/dev/ttyACM1')
master.wait_heartbeat()
print('heartbeat OK')

def armFunc():
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
    
def modeSetFunc():
    # mode section, tbh dont get
    # mode = 'STABILIZE'
    mode = 'MANUAL'
    mode_id = master.mode_mapping()[mode]
    print(mode_id)
    master.mav.set_mode_send(
        master.target_system,
        mavutil.mavlink.MAV_MODE_FLAG_CUSTOM_MODE_ENABLED,
        mode_id)
    print('mode set!')
    
def disarmFunc():
    master.mav.command_long_send(
        master.target_system,
        master.target_component,
        mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
        0,
        0, 0, 0, 0, 0, 0, 0)
    # wait until disarming confirmed
    master.motors_disarmed_wait()
    print('Disarming...')        

def send_manual_control(x, y, z, r):
    master.mav.manual_control_send(
        master.target_system,
        x, # forward/background
        y, # strafe left/right
        z, # up/down
        r, # turn left/right
        0)

def map_to_range(value, old_min, old_max, new_min, new_max):
    return ((value - old_min) / (old_max - old_min)) * (new_max - new_min) + new_min

def vector_control_tl():
    while True:  # Keep running until a non-number input is given
        try:
            print("Please enter four floats between -1 and 1:")
            vecstr = input() 
            veclist = vecstr.split()
            #  vectors = get_float_input("Float 1: ")

            # Map each float to the range -1000 to 1000
            vecx = map_to_range(float(veclist[0]), -1, 1, -1000, 1000)
            vecy = map_to_range(float(veclist[1]), -1, 1, -1000, 1000)
            vecz = map_to_range(float(veclist[2]), -1, 1, 0, 1000)
            vecr = map_to_range(float(veclist[3]), -1, 1, -1000, 1000)
            print(vecx,vecy,vecz,vecr)
            send_manual_control(vecx, vecy, vecz, vecr)
        except ValueError:
            print("Non-number input detected. Exiting the program.")
            break  # Exit the loop when a non-number input is given
    
armFunc()
modeSetFunc()
time.sleep(10)

vector_control_tl()
time.sleep(2)
disarmFunc()
