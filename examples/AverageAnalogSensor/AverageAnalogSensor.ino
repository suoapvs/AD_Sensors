/*
  Serial Average Analog Sensor

  Reads a signal from an analog sensor, averages the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AverageSensor.h>
#include <AnalogSensor.h>

#define ANALOG_PIN A1
#define NUMBER_OF_READINGS 10
#define DELAY_TIME 10

Sensor* sensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new AverageSensor(
    new AnalogSensor(ANALOG_PIN),
    NUMBER_OF_READINGS,
    DELAY_TIME
  );
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Averaged: " + String(sensor->read()));
  delay(500);
}
