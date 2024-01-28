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

## Sensor connector pins
1. power
2. ground
3. SDA
4. SCL

## Sensor Pins

| Sensor ID | Arduino Pin | MXP Pin | Rio DIO | WPILib Channel |
| --- | --- | --- | --- | --- |
| 1 | D13 13 | 25 | MXP DIO7 | 17 |
| 2 | A0 18 | 23 | MXP DIO6 | 16 |
| 3 | A1 19 | 21 | MXP DIO5 | 15 |
| 4 | A2 20 | 19 | MXP DIO4 | 14 |
| 5 | A3 21 | 17 | MXP DIO3 | 13 |
| 6 | A4 22 | 15 | MXP DIO2 | 12 |
| 7 | A5 23 | 13 | MXP DIO1 | 11 |
| 8 | D5 5 | 11 | MXP DIO0 | 10 |

Note: Because pin 13 on the arduino is also tied to an output led, sensor 6 should be used with caution.
Note: The DIO channel for digital input 0-9 are on-board, 10-25 are on the MXP
