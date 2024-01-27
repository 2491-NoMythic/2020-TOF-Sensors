# 2020-TOF-Sensors
## Hardware

This is a custom board based on an Adafruit ItsyBitsy, with an Adafruit TCA9548A 1-to-8 I2C Multiplexer Breakout, reading data from an Adafruit VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout, sending data to a RoboRio.

This circuit board is pretty much just a bunch of connectors. 
* a place to connect to the RoboRio with an MPX connector on the bottom of the board
* a place to connect the ItsyBitsy with headers
* a place to connect the multiplexer with headers
* a place to connect JST-4pin connectors for each of up to 8 sensors

There are images of the schematic and board layout.

Note: we couldn't figure out how to get a footprint that matched the ItsyBitsy and the multiplexer in KiCad, so we just used two rows of of headers. It looks particularly weird in the schematic, but it works. Pin 1 of each IC is top left of the two rows in the schematic and circuit board. 

## Sensor pins
1. power
2. ground
3. SDA
4. SCL

## Sensor Connectors

| Sensor ID | Arduino Pin | MXP Pin |
| --- | --- | --- |
| 1 | 0 | 0 |
| 2 | 0 | 0 |
