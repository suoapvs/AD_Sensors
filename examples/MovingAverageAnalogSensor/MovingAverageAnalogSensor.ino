/*
  Serial Average Analog Sensor

  Reads a signal from an analog sensor, averages the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <MovingAverageSensor.h>

#define ANALOG_PIN A1
#define SMOOTHING_FACTOR 5

Sensor* sensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new MovingAverageSensor(
    new AnalogSensor(ANALOG_PIN),
    SMOOTHING_FACTOR
  );
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Averaged: ");
  Serial.println(sensor->read());
  delay(500);
}
