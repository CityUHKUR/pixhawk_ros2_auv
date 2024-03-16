import time
import rclpy

class bank_msg:
    def __init__(self, x=0, y=0, z=0, turn_mode=False, distance=0, time_=0):
        self.x = x
        self.y = y
        self.z = z
        self.turn_mode = turn_mode
        self.distance = distance
        self.time = time_
            
        self.start_time = 0
        self.end_time = 0
        self.init_time = time.time()
    
    
    def to_xyzr(self):
        if self.turn_mode:
            __x = 0
            __y = 0
            __z = 500
            __r = map_to_range(self.y)
        else:
            __x = map_to_range(self.x)
            __y = map_to_range(self.y)
            __z = map_to_range(self.z, new_min=0)
            __r = 0
            
        return __x, __y, __z, __r

def map_to_range(value, old_min=-1, old_max=1, new_min=-1000, new_max=1000):
    # if value type is not float, convert it to float
    try:
        if type(value) != float:
            value = float(value)
    except ValueError:
        rclpy.get_logger().error(f"ValueError: {value} is not a number.")
        return 0
    return int(((value - old_min) / (old_max - old_min)) * (new_max - new_min) + new_min)