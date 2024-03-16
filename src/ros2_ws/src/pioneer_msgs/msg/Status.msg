# Message for conversation between flow control and AUV specify task algorithm
# Please include your node name as the frame_id

std_msgs/Header header

# State Name Example 
# "state_navigate_task1"
# "recover_mode"
# Detail refer to state machine repo readme 
string current_state

# Status of your algorithm
# "START"
# "IN PROGRESS"
# "FAIL"
# "SUCESS"
string status

# Send this message in /auv_status to report the progress 