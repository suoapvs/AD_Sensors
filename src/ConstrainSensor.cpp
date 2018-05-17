#include "ConstrainSensor.h"

ConstrainSensor::ConstrainSensor(
  const Sensor* sensor,
  const int low,
  const int high
) {
  this->sensor = sensor;
  this->low = low;
  this->high = high;
}

int ConstrainSensor::read() {
  return constrain(this->sensor->read(), this->low, this->high);
}
