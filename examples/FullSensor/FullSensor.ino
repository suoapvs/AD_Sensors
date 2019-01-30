/*
  Serial Full Sensor

  Reads a signal from an analog sensor,
  averages, maps and constrains the signal
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include <Sensor.h>
#include <AnalogSensor.h>
#include <AverageSensor.h>
#include <SmoothSensor.h>
#include <MapSensor.h>
#include <ConstrainSensor.h>

#define ANALOG_PIN A1
#define NUMBER_OF_READINGS 10
#define DELAY_TIME 10
#define SMOOTHING_FACTOR 5
#define FROM_LOW 0
#define FROM_HIGH 1023
#define TO_LOW 100
#define TO_HIGH 1000
#define MIN 200
#define MAX 900

Sensor* sensor = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  sensor = new ConstrainSensor(
    new MapSensor(
      new SmoothSensor(
        new AverageSensor(
          new AnalogSensor(ANALOG_PIN),
          NUMBER_OF_READINGS, DELAY_TIME
        ),
        SMOOTHING_FACTOR
      ),
      FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH
    ),
    MIN, MAX
  );
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Sensor: ");
  Serial.println(sensor->read());
  delay(500);
}
