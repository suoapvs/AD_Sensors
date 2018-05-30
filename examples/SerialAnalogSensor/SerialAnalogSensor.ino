/*
  Serial Analog Sensor

  Reads a signal of the analog sensor and displays
  information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <AnalogSensor.h>

#define ANALOG_PIN A1

AnalogSensor* sensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new AnalogSensor(ANALOG_PIN);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Analog Sensor: ");
  Serial.println(sensor->read());
  delay(500);
}
