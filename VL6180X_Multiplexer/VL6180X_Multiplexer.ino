/**
 * Code to read data from multiple VL8180 distance sensors using a I2C multiplexor.
 * In this code we are using it as an accurate presense detector - yes/no.
 * Each sensor will be read, and a 1 or 0 will be written to a pin that is
 * connected to the DIO of the robot via the MPX port on the RoboRio. The purpose
 * was to 1) use multiple VL8180 sensors that have a fixed I2C address, and 2) free
 * up the RoboRio code to simply need to check a digitalInput as you would a limit switch.
 * 
 * For each sensor, you will need to create a sensor object.
 * For each sensor, you will have to call the setupSensor function from setup()
 * For each sensor, you will have to call the checkSensor function from the loop()
 * 
 * This code was written to be run on an Adafruit ItsyBitsy, with an Adafruit
 * CA9548A 1-to-8 I2C Multiplexer Breakout, reading data from an Adafruit 
 * VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout, sending data to
 * a RoboRio. This code could easily be changed to use a different microcontroller,
 * multiplexor, or sensor. 
 */
#include "Adafruit_VL6180X.h"

// default address of the multiplexor
#define TCAADDR 0x70

// will print the distance (on a true) for each checkSensor call to console if true
// will slow code a tiny bit, so set to false when everything is working
#define DEBUG true

// create a sensor object for each sensor
// naming should make sense, such as vl(sensorId) like here
Adafruit_VL6180X vl5 = Adafruit_VL6180X();
Adafruit_VL6180X vl7 = Adafruit_VL6180X();

/**
 * Function used to pick a sensor to read. This sends a simple command to the 
 * multiplexor to pick the correct sensor. From 0 to 7 (eight in total)
 */
void tcaselect(int i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

/**
 * Common function for setting up a sensor.
 * param1 is the id of the sensor that matches the ports on the multiplexor
 * param2 is the object that represents the sensor that has been initialized
 * param3 is the output pin that will show a true/false on it for the sensor
 * Make sure you keep these values consistant with those in checkSensor
 */
void setupSensor(int sensorId, Adafruit_VL6180X &sensor, int outputPin) {
  pinMode(outputPin, OUTPUT);
  tcaselect(sensorId);
  if (! sensor.begin()) {
    Serial.print("Failed to find sensor ");
    Serial.println(sensorId);
  } else {
    Serial.print("Sensor ");
    Serial.print(sensorId);
    Serial.println(" found!");
  }
}

/**
 * This code is run once on start up.
 * The sensors are initialized. Message of error or found for each sensor shown in console.
 */
void setup() {
  Serial.begin(115200);
  Wire.begin();

  delay(100);
  Serial.println("VL6180X Sensor Multiplexor Reader");

  // Call setupSensor for each sensor you want to check
  setupSensor(5, vl5, 9);
  setupSensor(7, vl7, 11);

  // output indicator
  pinMode(13, OUTPUT);
}

/**
 * Call this function to check one sensor and set its status on the outputPin
 * param1 is the id of the sensor that matches the ports on the multiplexor
 * param2 is the object that represents the sensor that has been initialized
 * param3 is the output pin that will show a true/false on it for the sensor
 * Make sure you keep these values consistant with those in setupSensor
 */
void checkSensor(int sensorId, Adafruit_VL6180X &sensor, int outputPin) {
  tcaselect(sensorId);
  uint8_t range = sensor.readRange();
  uint8_t status = sensor.readRangeStatus();
  if (status == VL6180X_ERROR_NONE) {
    if (DEBUG) {
      Serial.print("Range ");
      Serial.print(sensorId);
      Serial.print(" : ");
      Serial.println(range);
    }
    digitalWrite(outputPin, HIGH);
  } else {
    digitalWrite(outputPin, LOW);
  }
}

/**
 * This code is run constantly. It checks every sensor and sets the true/false,
 * high/low on the output pins. You should have checkSensor calls here for every sensor 
 * that you want to read from.
 * If you put a delay in here you can see the led on pin 13 flash each time around the
 * loop to debug that the code is infact looping. If speed is critical, leave this commented out.
 */
void loop() {
  digitalWrite(13, HIGH);
  checkSensor(5, vl5, 9);
  checkSensor(7, vl7, 11);
  digitalWrite(13, LOW);
  // delay(100); // only use to slow code to see pin 13 blinking (running)
}
