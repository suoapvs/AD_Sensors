/*
  Serial Map Analog Sensor

  Reads a signal from an analog sensor, maps the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <MapSensor.h>
#include <AnalogSensor.h>

#define ANALOG_PIN A1

#define FROM_LOW 0
#define FROM_HIGH 1023
#define TO_LOW 0
#define TO_HIGH 100

Sensor* analogSensor;
Sensor* mapSensor;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  analogSensor = new AnalogSensor(ANALOG_PIN);
  mapSensor = new MapSensor(analogSensor, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Original: " + String(analogSensor->read()));
  Serial.println(" | Maped: " + String(mapSensor->read()));
  delay(500);
}
