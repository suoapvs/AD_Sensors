#include "SmoothSensor.h"

SmoothSensor::SmoothSensor(
  Sensor* origin,
  const int factor
) {
  this->origin = origin;
  this->factor = factor;
}

SmoothSensor::~SmoothSensor() {
  delete this->origin;
}

int SmoothSensor::read() {
  return smoothe(this->origin->read());
}

inline int SmoothSensor::smoothe(const int input) {
  return this->data = (this->factor > 1) && (this->data != 0) ?
    (this->data * (this->factor - 1) + input) / this->factor :
    input;
}
