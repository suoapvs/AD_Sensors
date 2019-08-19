/**
	Sensor - interface describes a set of methods
	for working with analog and digital sensors.

	https://github.com/YuriiSalimov/AD_Sensors

	v.1.3.3
	- updated documentation

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef SENSOR_H
#define SENSOR_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class Sensor {

	public:
		/**
			Reads and return a signal from a sensor.

			@return the sensor signal
		*/
		virtual int read() = 0;
};

#endif
