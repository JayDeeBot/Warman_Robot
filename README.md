# Warman_Robot :smiley:
## <mark>1. Testing instruction :exclamation: :exclamation:

<mark>:point_right:  :pushpin: Note: Please be careful with my little shaft for the scoop... if you want the scoop to tilt down... slowly turn the pinion gear (the red small one at the motor shaft)
### Start form here...
:star: Upload the code to arduino (if you made any changes).

:star: Unplugged the "blue cable" that you used to upload the code. :exclamation:

:star: Connect with the power from the oscilloscope.

:star: Turn the power on.

:star: When you want the robot to do the task, slowly plug the blue cable in your laptop while still keep the power supply turn on. :exclamation:

:star: When you want it to stop, you pull out the blue cable from your laptop. :exclamation:

:question: <mark>Why do we need to do that :question:

:confused: A problem that I had on 15/11/2023 was when I still kept the blue cable power from my laptop and turn off the power supply, after hitting upload and then turn on the power, the program did not start from the start of the void loop. Because once you hit the upload or supply the power to the Arduino, the program runs at that moment, so when we turn on the power supply for the robot, it might run to the half of the void loop already...



## 2. Plan for testing :pencil:

### :point_right: 1. Find the start position to place the chassis. :point_right: The positon to place three squash balls.

### :point_right: 2. Find the delay time for the chassis to move foward and stop and then move backward. 

### :point_right: 3. Test the lift to see if the voltage from the L928N driver is sufficient or not

### :point_right: 4. Test the servo, if there are enough pins or not ... if not ... buy the Mega.

### :point_right: 5. Wire the fuse holder with the buck converter and test the battery. 

## 3. Note :notebook: 

### :hear_no_evil: Do not mind about the button things ... you can remove it...
### :hear_no_evil: Be careful with the aligator clips of the power supply that you test, do not mess up with that.
### :hear_no_evil: If there are some bugs or the code does not work, ... debug it ... 