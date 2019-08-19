/*
  Serial Constrain Analog Sensor

  Reads a signal from an analog sensor, constrains the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <ConstrainSensor.h>

#define ANALOG_PIN A1
#define LOW 0
#define HIGH 100

Sensor* origin = NULL;
Sensor* constrained = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  origin = new AnalogSensor(ANALOG_PIN);
  constrained = new ConstrainSensor(origin, LOW, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Original: ");
  Serial.print(origin->read());
  Serial.print(", Constrained: ");
  Serial.println(constrained->read());

  delay(500); // optionally, only to delay the output of information in the example
}
