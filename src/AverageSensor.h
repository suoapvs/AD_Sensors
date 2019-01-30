/**
	AverageSensor.h - Reads a signal from a origin sensor,
	averages the signal and return it.

	Instantiation:
		Sensor origin();
		AverageSensor sensor(origin, 0, 100);

	Read signal:
		int value = sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef AVERAGE_SENSOR_H
#define AVERAGE_SENSOR_H

#include "Sensor.h"

#define AVERAGE_SENSOR_MIN_COUNTER 1
#define AVERAGE_SENSOR_MIN_TIME_DELAY 1

class AverageSensor final : public Sensor {

	private:
		Sensor* origin;
		int counter;
		int delayTime;

	public:
		/**
			Constructor.
			@param origin - the origin sensor;
			@param counter - number of readings;
			@param delayTime - delay time between readings.
		*/
		AverageSensor(Sensor* origin, int counter, int delayTime);

		~AverageSensor();

		/**
			Reads a signal from the origin sensor,
			averages the signal and return it.
			@return the average signal value.
		*/
		int read() override;

	private:
		inline void sleep();
};

#endif
