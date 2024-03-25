# Message of current_state of AUV
# Only publish by state machine

std_msgs/Header header

# State Name Example 
# "state_navigate_task1"
# "recover_mode"
# Detail refer to state machine repo readme 
string current_state

# The node responsible for control AUV, reference only 
string current_control