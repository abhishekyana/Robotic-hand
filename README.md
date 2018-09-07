# Robotic_hand
This project let's you control a 3d printed robotic hand with your speech commands.<br>
Steps:
1. Clone the repository `git clone https://github.com/abhishekyana/Robotic_hand`
1. 3D print all the robotic hand parts from [here from thingiverse](https://www.thingiverse.com/thing:2171811) and assemble according to the provided instructions.
1. Connect the servos as in the arduino code. Make sure you give external power supply(I used 5V 2A) to the Servos as they draw a lot of current which Arduino can't give.
1. Upload the [code](RobotHand/RobotHand.ino) into Arduino and note down the device port.
1. Make sure you have these python libraries installed serial, speech_recognition.
1. Run the Python code `python speech2command.py`
1. Say the commands and enjoy watching your robot hand in live.

Thank you so much<br>
Please feel free to fork and provide feedback,<br>
Love Open Source
