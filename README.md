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
## docker
- docker ps
- docker compose up --build
- vscode attach to dev container
- 
## Movement part
- package.xml needs to have ```<exec_depend>pioneer_msgs</exec_depend> ```
- topic should be ```movement_topic ```
    - topic type should be MotionCommand
- ``` ros2 pkg executables pixpubsub``` to see available exec
- ```ros2 run pixpubsub publisher```
- in another terminal ```ros2 run pixpubsub move_pub``` testing code, which sends hardcode values to topic, can change the value manually
- may need to manually uncomment `self.send_manual_control(vecx, vecy, vecz, vecr)` as this for testing without pixhawk
- may need to uncomment other code also
  
