# Defines a standard motion command send to pixhawk/motion control node
std_msgs/Header header

# is pure turning/yaw or displacement included
bool turn_mode

# x,y,z value must between [-1, 1]
# x is frontward and backward
# y is horizontal movement, positive is right
# z is up and down
geometry_msgs/Vector3 direction


# Distance mode and Time mode is exclusive 
# -1 to disable distance mode, measure in meter
float32 distance

# -1 to disable time mode, measure in sec
float32 time