/*
  Serial Smooth Analog Sensor

  Reads a signal from an analog sensor, smoothes the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, January, 2019.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <SmoothSensor.h>

#define ANALOG_PIN A1
#define SMOOTHING_FACTOR 5

Sensor* origin = NULL;
Sensor* smoothed = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  origin = new AnalogSensor(ANALOG_PIN);
  smoothed = new SmoothSensor(origin, SMOOTHING_FACTOR);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Origin : ");
  Serial.print(origin->read());
  Serial.print(", Smoothed : ");
  Serial.println(smoothed->read());
  delay(500);
}
