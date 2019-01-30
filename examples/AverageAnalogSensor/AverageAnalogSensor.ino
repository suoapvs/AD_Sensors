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
#include <AverageSensor.h>

#define ANALOG_PIN A1
#define NUMBER_OF_READINGS 10
#define DELAY_TIME 10

Sensor* origin = NULL;
Sensor* averaged = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  origin = new AnalogSensor(ANALOG_PIN);
  averaged = new AverageSensor(
    origin,
    NUMBER_OF_READINGS,
    DELAY_TIME
  );
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Origin: ");
  Serial.println(origin->read());
  Serial.println(", Averaged: ");
  Serial.println(averaged->read());
  delay(500);
}
