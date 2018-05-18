/**
  MapSensor.h - Reads a signal from a delegated sensor,
	maps the signal and return it.

	Instantiation:
	  Sensor otherSensor();
		MapSensor sensor(otherSensor, 0, 1023, 0, 100);

	Read signal:
		sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef MAP_SENSOR_H
#define MAP_SENSOR_H

#include "Sensor.h"

class MapSensor final :
	public Sensor {

	private:
		const Sensor* sensor;
    int fromLow = 0;
    int fromHigh = 0;
    int toLow = 0;
    int toHigh = 0;

	public:
		MapSensor(
      const Sensor* sensor,
      const int fromLow, const int fromHigh,
      const int toLow, const int toHigh
    );

		int read() override;
};

#endif
