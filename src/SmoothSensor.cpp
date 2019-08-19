/**
  Created by Yurii Salimov, January, 2019.
  Released into the public domain.
*/
#include "SmoothSensor.h"

SmoothSensor::SmoothSensor(
  Sensor* origin,
  const int smoothingFactor
) {
  this->origin = origin;
  setSmoothingFactor(smoothingFactor);
}

SmoothSensor::~SmoothSensor() {
  delete this->origin;
}

int SmoothSensor::read() {
  return smoothe(this->origin->read());
}

inline int SmoothSensor::smoothe(const int input) {
  return (this->data =
    (this->data == 0) ? input :
    ((this->data * (this->smoothingFactor - 1) + input) / this->smoothingFactor)
  );
}

/*
  See about the max(*) function:
  https://www.arduino.cc/reference/en/language/functions/math/max/
*/
inline void SmoothSensor::setSmoothingFactor(const int smoothingFactor) {
  this->smoothingFactor = max(smoothingFactor, AD_MIN_SMOOTHING_FACTOR);
}
