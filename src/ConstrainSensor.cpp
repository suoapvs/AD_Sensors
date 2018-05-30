#include "ConstrainSensor.h"

ConstrainSensor::ConstrainSensor(
  const Sensor* delegateSensor,
  const int low,
  const int high
) {
  this->sensor = delegateSensor;
  this->low = low;
  this->high = high;
}

ConstrainSensor::~ConstrainSensor() {
  delete this->sensor;
}

int ConstrainSensor::read() {
  return constrain(this->sensor->read(), this->low, this->high);
}
