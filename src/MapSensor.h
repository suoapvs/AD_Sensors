/**
	MapSensor - class-wrapper allows to map
	a signal value of origin Sensor instance.
	Re-maps the signal from one range to another.
	That is, a signal of fromLow would get mapped to toLow,
	a signal of fromHigh to toHigh, signals in-between to signals in-between, etc.

	Instantiation:
	Sensor* mapSensor = new MapSensor(
		SENSOR,
		FROM_LOW, FROM_HIGH,
		TO_LOW, TO_HIGH,
	);

	Where,
	SENSOR - origin Sensor instance.
	FROM_LOW - the lower bound of the value’s CURRENT range
	FROM_HIGH - the upper bound of the value’s CURRENT range
	TO_LOW - the lower bound of the value’s TARGET range
	TO_HIGH - the upper bound of the value’s TARGET range

	Read signal:
	int value = mapSensor->read();

	v.1.3.3
	- optimized read(*) method;
	- updated documentation.

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef MAP_SENSOR_H
#define MAP_SENSOR_H

#include "Sensor.h"

class MapSensor final : public Sensor {

	private:
		Sensor* origin;
		int fromLow;
		int fromHigh;
		int toLow;
		int toHigh;

	public:
		/**
			Constructor

			@param origin - the origin sensor (not NULL)
			@param fromLow - the lower bound of the value’s current range
			@param fromHigh - the upper bound of the value’s current range
			@param toLow - the lower bound of the value’s target range
			@param toHigh - the upper bound of the value’s target range
		*/
		MapSensor(
			Sensor* origin,
			int fromLow, int fromHigh,
			int toLow, int toHigh
		);

		~MapSensor();

		/**
			Reads a signal from a origin sensor,
			maps the signal and return it.

			@return the mapped signal value.
		*/
		int read() override;
};

#endif
