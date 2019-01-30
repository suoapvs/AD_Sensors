#include "SmoothSensor.h"

SmoothSensor::SmoothSensor(
  Sensor* origin,
  const int factor
) {
  this->origin = origin;
  this->factor = factor;
  init();
}

inline void SmoothSensor::init() {
  this->data = this->origin->read();
}

SmoothSensor::~SmoothSensor() {
  delete this->origin;
}

int SmoothSensor::read() {
  return smoothe(this->origin->read());
}

inline int SmoothSensor::smoothe(const int input) {
  if (this->factor > 0) {
    this->data = (this->data * (this->factor - 1) + input) / this->factor;
  } else {
    this->data = input;
  }
  return this->data;
}
