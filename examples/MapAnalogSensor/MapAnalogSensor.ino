/*
  Serial Map Analog Sensor

  Reads a signal from an analog sensor, maps the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <MapSensor.h>

#define ANALOG_PIN A1
#define FROM_LOW 0
#define FROM_HIGH 1023
#define TO_LOW 0
#define TO_HIGH 100

Sensor* origin = NULL;
Sensor* mapSensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  origin = new AnalogSensor(ANALOG_PIN);
  mapSensor = new MapSensor(origin, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Original: ");
  Serial.print(origin->read());
  Serial.print(", Maped: ");
  Serial.println(mapSensor->read());
  delay(500);
}
