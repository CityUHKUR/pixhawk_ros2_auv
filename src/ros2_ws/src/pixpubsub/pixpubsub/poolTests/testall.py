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

def send_manual_control(x, y, z, r):
    master.mav.manual_control_send(
        master.target_system,
        x, # forward/background
        y, # strafe left/right
        z, # up/down
        r, # turn left/right
        0)
    
def moveForward():
    send_manual_control(500, 0, 500, 0)
def moveBackward():
    send_manual_control(-500, 0, 500,0)
    
def strafeRight():
    send_manual_control(0, 500, 500, 0)
def strafeLeft():
    send_manual_control(0, -500, 500, 0)
    
def moveUp():
    send_manual_control(0,0,700,0)
def moveDown(): 
    send_manual_control(0,0,300,0)    
    
def turnLeft():
    send_manual_control(0,0,500,500)
def turnRight():
    send_manual_control(0,0,500,-500) 
    
# Arm
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

# Disarm
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
    
# modeSetFunc()
armFunc()
modeSetFunc()
time.sleep(10)

#in theory should do all movement and return to original place
moveDown()
time.sleep(2)
moveUp()
time.sleep(2)
moveForward()
time.sleep(2)
moveBackward()
time.sleep(2)
strafeLeft()
time.sleep(2)
strafeRight()
time.sleep(2)
turnRight()
time.sleep(2)
turnLeft()
time.sleep(2)
# for i in range(0, 10):
#     turnLeft()
#     print('moving ')
#     time.sleep(1.5)

disarmFunc()