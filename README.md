<div align=center>
<img src="assets/UR_Git_Logo_banner.png", height=130>
<h1>ROS2 Pixhawk Node</h1>
A docker service containing ROS2 packages for interfacing with Pixhawk.
</div>

## Dependencies
1. Docker

## Topics
- `/imu_data` - sensor_msgs/Imu
    - Only linear acceleration and angular velocity available
      
## Movement part
- package.xml needs to have ```<exec_depend>pioneer_msgs</exec_depend> ```
- topic should be ```movement_topic ```
    - topic type should be MotionCommand
- ```ros2 pkg executables pixpubsub``` to see available exec
- ```ros2 run pixpubsub pixhawk_worker```
- in another terminal ```ros2 run pixpubsub testing_node``` testing code, which sends movement, front/back, left/right, up/down, turn left/right
- may need to manually uncomment `self.send_manual_control(vecx, vecy, vecz, vecr)` as this for testing without pixhawk
- may need to uncomment other code also

## Param cmds
- `ros2 param list`
- `ros2 run pixpubsub pixhawk_worker --ros-args -p "mode_param:=MANUAL"`change mode at start switch the MANUAL with other mode names
- `ros2 param get /pixhawk_module mode_param` get current mode
- `ros2 param set /pixhawk_module mode_param "MANUAL"`set mode when node is running
- `ros2 run pixpubsub testing_node --ros-args -p bool_param:=False -p arr_param:="[1.0, 1.0, 1.0]"` testing node param run

## misc cmds
-`git config --global core.autocrlf true`
-`find . -name "*.*" -exec dos2unix {} +`
-`sudo chmod 777 . -R`


  
