# 2020-TOF-Sensors
## VL6180X_Multiplexer

Arduino code to read data from multiple VL8180 distance sensors using a I2C multiplexer.
In this code we are using it as an accurate presence detector - yes/no.
Each sensor will be read, and a 1 or 0 will be written to a pin that is
connected to the DIO of the robot via the MPX port on the RoboRio. The purpose
was to 

1. use multiple VL8180 sensors that have a fixed I2C address, and 
2. free up the RoboRio code to simply need to check a digitalInput as you would a limit switch.

For each sensor, you will need to create a sensor object.
For each sensor, you will have to call the setupSensor function from setup()
For each sensor, you will have to call the checkSensor function from the loop()

This code was written to be run on an Adafruit ItsyBitsy, with an Adafruit
TCA9548A 1-to-8 I2C Multiplexer Breakout, reading data from an Adafruit 
VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout, sending data to
a RoboRio. This code could easily be changed to use a different microcontroller,
multiplexer, or sensor. 

To use this code, open up this .ino file in the Arduino editor, make code changes
related to the number of sensors and the pins you are using, and upload to your micro-controller.

Note: You will need the Adafruit_VL6180X Arduino library
Note: If uploading to the ItsyBitsy, select the 32u4 5v version.

This code is an example and set up to work with the included board. The output pins from the Arduino will be high when the sensor finds something within the sensor range, and low if not. 

The code could be changed to respond to a particular distance. Some of the pins on the ItsyBitsy are analog pins. Therefore, the pin could be set up as analog and a value representing the distance could be sent to the pin. However, not all the pins connected on the MX Port of the Rio are PWM inputs (can read the analog output). 17, 15, 13 might be the only ones connected to analog pins on the Arduino. See chart in Hardware readme. You would have to test the others.

Note: This board gets its power from the RoboRio, therefore it can't be used to read sensors unless connected to the RoboRio, and the RoboRio is provided power.
