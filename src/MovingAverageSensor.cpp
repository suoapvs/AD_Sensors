#include "MovingAverageSensor.h"

MovingAverageSensor::MovingAverageSensor(
  Sensor* origin,
  const int smoothingFactor
) {
  this->origin = origin;
  this->smoothingFactor = smoothingFactor;
  init();
}

inline void MovingAverageSensor::init() {
  this->data = this->origin->read();
}

MovingAverageSensor::~MovingAverageSensor() {
  delete this->origin;
}

int MovingAverageSensor::read() {
  return movingAverage(this->origin->read());
}

inline int MovingAverageSensor::movingAverage(const int input) {
  if (this->smoothingFactor > 0) {
    this->data = (this->data * (this->smoothingFactor - 1) + input) / this->smoothingFactor;
  } else {
    this->data = input;
  }
  return this->data;
}
