/*
  Serial Digital Sensor

  Reads a invert signal of the digital sensor and displays
  information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <DigitalSensor.h>

#define DIGITAL_PIN 1
#define INVERT_SIGNAL true

DigitalSensor* sensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new DigitalSensor(DIGITAL_PIN, INVERT_SIGNAL);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Digital Sensor: ");
  Serial.println(sensor->isHigh() ? "HIGH" : "LOW");
  delay(500);
}
