/**
	ConstrainSensor.h - Reads a signal from a origin sensor,
	constrains the signal and return it.

	Instantiation:
		Sensor origin();
		ConstrainSensor sensor(origin, 0, 100);

	Read signal:
		int value = sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef CONSTRAIN_SENSOR_H
#define CONSTRAIN_SENSOR_H

#include "Sensor.h"

class ConstrainSensor final : public Sensor {

	private:
		Sensor* origin;
		int low;
		int high;

	public:
		/**
			Constructor.
			@param origin - the origin sensor;
			@param low - the lower end of the constraint range;
			@param high - the upper end of the constraint range.
		*/
		ConstrainSensor(Sensor* origin, int low, int high);

		~ConstrainSensor();

		/**
			Reads a signal from the origin sensor,
			constrains the signal and return it.
			Example,
				x = the sensor signal;
				a = low end of the constraint range;
				b = high end of the constraint range;
			@return the constrained signal value:
				x: if x is between a and b;
				a: if x is less than a;
				b: if x is greater than b.
		*/
		int read() override;
};

#endif
