#include "MapSensor.h"

MapSensor::MapSensor(
  const Sensor* delegateSensor,
  const int fromLow, const int fromHigh,
  const int toLow, const int toHigh
) {
  this->sensor = delegateSensor;
  this->fromLow = fromLow;
  this->fromHigh = fromHigh;
  this->toLow = toLow;
  this->toHigh = toHigh;
}

MapSensor::~MapSensor() {
  delete this->sensor;
}

int MapSensor::read() {
  return map(
    this->sensor->read(),
    this->fromLow, this->fromHigh,
    this->toLow, this->toHigh
  );
}
