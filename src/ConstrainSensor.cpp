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

int ConstrainSensor::read() {
  return constrain(this->origin->read(), this->low, this->high);
}
