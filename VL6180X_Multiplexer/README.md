# 2020-TOF-Sensors
## VL6180X_Multiplexor


Arduino code to read data from multiple VL8180 distance sensors using a I2C multiplexor.
In this code we are using it as an accurate presense detector - yes/no.
Each sensor will be read, and a 1 or 0 will be written to a pin that is
connected to the DIO of the robot via the MPX port on the RoboRio. The purpose
was to 1) use multiple VL8180 sensors that have a fixed I2C address, and 2) free
up the RoboRio code to simply need to check a digitalInput as you would a limit switch.

For each sensor, you will need to create a sensor object.
For each sensor, you will have to call the setupSensor function from setup()
For each sensor, you will have to call the checkSensor function from the loop()

This code was written to be run on an Adafruit ItsyBitsy, with an Adafruit
CA9548A 1-to-8 I2C Multiplexer Breakout, reading data from an Adafruit 
VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout, sending data to
a RoboRio. This code could easily be changed to use a different microcontroller,
multiplexor, or sensor. 

To use this code, open up this .ino file in the Arduino editor, make code changes
related to the number of sensors and the pins you are using, and upload to your microcontroller.