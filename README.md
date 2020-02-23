# 2020-TOF-Sensors

Our robot for 2020 has an indexer that stores and gets balls ready for the shooter. To make sure that they don't get stuck, we use sensors to control the movement of the belts and motors of our indexer.

With up to 8 sensors we knew that we would need a way to keep the wiring lined up and under control. So we decided to create a custom board that plugs into the MPX connector on the RoboRio. 

This board would have a Microcontroler (Arduino compatible) and locking connectors for our chosen sensor. After trying a few we went with the Adafruit VL6180x Time of Flight sensor.

Unfortunately this sensor has a non changeable I2C address, so we needed to also stick a multiplexer in there.

So this is what we decided to create:

A custom board based on an Adafruit ItsyBitsy, with an Adafruit CA9548A 1-to-8 I2C Multiplexer Breakout, reading data from an Adafruit VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout, sending data to a RoboRio.

The objective was to 1) use multiple VL8180 sensors that have a fixed I2C address, and 2) free up the RoboRio code to simply need to check a digitalInput as you would a limit switch.

There is more documentation in the Arduino code.
