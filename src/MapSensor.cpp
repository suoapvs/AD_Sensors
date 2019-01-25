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

int MapSensor::read() {
  return map(
    this->origin->read(),
    this->fromLow, this->fromHigh,
    this->toLow, this->toHigh
  );
}
