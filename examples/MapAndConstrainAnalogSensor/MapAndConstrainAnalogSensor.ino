/*
  Serial Constrain Map Analog Sensor

  Reads a signal from an analog sensor,
  maps and constrains the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <MapSensor.h>
#include <ConstrainSensor.h>

#define ANALOG_PIN A1
#define FROM_LOW 100
#define FROM_HIGH 900
#define TO_LOW 0
#define TO_HIGH 100
#define MIN 0
#define MAX 100

Sensor* analogSensor = NULL;
Sensor* mapSensor = NULL;
Sensor* constrainSensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  analogSensor = new AnalogSensor(ANALOG_PIN);
  mapSensor = new MapSensor(analogSensor, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
  constrainSensor = new ConstrainSensor(mapSensor, MIN, MAX);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Original: ");
  Serial.print(analogSensor->read());
  Serial.print(", Maped: ");
  Serial.print(mapSensor->read());
  Serial.print(", Constrained: ");
  Serial.println(constrainSensor->read());

  delay(500); // optionally, only to delay the output of information in the example
}
