/**
  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include "ConstrainSensor.h"

ConstrainSensor::ConstrainSensor(
  Sensor* origin,
  const int low,
  const int high
) {
  this->origin = origin;
  this->low = low;
  this->high = high;
}

ConstrainSensor::~ConstrainSensor() {
  delete this->origin;
}

/**
  See about the constrain(*) function:
  https://www.arduino.cc/reference/en/language/functions/math/constrain/
*/
int ConstrainSensor::read() {
  const int originValue = this->origin->read();
  return constrain(originValue, this->low, this->high);
}
