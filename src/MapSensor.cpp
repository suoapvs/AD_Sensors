/**
  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#include "MapSensor.h"

MapSensor::MapSensor(
  Sensor* origin,
  const int fromLow, const int fromHigh,
  const int toLow, const int toHigh
) {
  this->origin = origin;
  this->fromLow = fromLow;
  this->fromHigh = fromHigh;
  this->toLow = toLow;
  this->toHigh = toHigh;
}

MapSensor::~MapSensor() {
  delete this->origin;
}

/**
  See about the map(*) function:
  https://www.arduino.cc/reference/en/language/functions/math/map/
*/
int MapSensor::read() {
  const int originValue = this->origin->read();
  return map(
    originValue,
    this->fromLow, this->fromHigh,
    this->toLow, this->toHigh
  );
}
