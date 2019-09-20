/**
  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(const int pin, const boolean invert) {
  pinMode(this->pin = pin, INPUT_PULLUP);
  invertSignal(invert);
}

int DigitalSensor::read() {
  return digitalRead(this->pin);
}

boolean DigitalSensor::isHigh() {
  return read() == this->signal;
}

boolean DigitalSensor::isLow() {
  return !isHigh();
}

void DigitalSensor::invertSignal(const boolean invert) {
  this->signal = (invert ? LOW : HIGH);
}
