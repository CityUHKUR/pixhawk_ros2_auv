class bank_msg:
    def __init__(self, x=0, y=0, z=0, turn_mode=False, distance=0, time=0):
        self.x = x
        self.y = y
        self.z = z
        self.turn_mode = turn_mode
        self.distance = distance
        self.time = time
            
        self.start_time = 0
        self.end_time = 0
        self.init_time = time.time()
        