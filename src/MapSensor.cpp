#include "MapSensor.h"

MapSensor::MapSensor(
  const Sensor* sensor,
  const int fromLow, const int fromHigh,
  const int toLow, const int toHigh
) {
  this->sensor = sensor;
  this->fromLow = fromLow;
  this->fromHigh = fromHigh;
  this->toLow = toLow;
  this->toHigh = toHigh;
}

int MapSensor::read() {
  return map(
    this->sensor->read(),
    this->fromLow, this->fromHigh,
    this->toLow, this->toHigh
  );
}
