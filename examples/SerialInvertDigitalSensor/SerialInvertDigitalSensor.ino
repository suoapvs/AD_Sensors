/*
  Serial Digital Sensor

  Reads a invert signal of the digital sensor and displays
  information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <DigitalSensor.h>

#define ANALOG_PIN    A1
#define INVERT_SIGNAL true

DigitalSensor* sensor;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new DigitalSensor(ANALOG_PIN, INVERT_SIGNAL);
}

// the loop function runs over and over again forever
void loop() {
  const String signal = sensor->isHigh() ? "HIGH" : "LOW";
  Serial.println("Digital Sensor: " + signal);
  delay(500);
}
