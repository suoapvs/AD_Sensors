/**
	MovingAverageSensor.h - Reads a signal from a origin sensor,
	averages (moving average, rolling average or running average)
	the signal and return it.
	Wiki: https://en.wikipedia.org/wiki/Moving_average

	Instantiation:
		Sensor origin();
		MovingAverageSensor sensor(origin, 5);

	Read signal:
		int value = sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, January, 2019.
	Released into the public domain.
*/
#ifndef MOVING_AVERAGE_SENSOR_H
#define MOVING_AVERAGE_SENSOR_H

#include "Sensor.h"

class MovingAverageSensor final : public Sensor {

	private:
		Sensor* origin;
		int smoothingFactor;
		int data;

	public:
		/**
			Constructor.
			@param origin - the origin sensor;
			@param smoothingFactor - smoothing factor of readings (0 = not smooth)
		*/
		MovingAverageSensor(Sensor* origin, int smoothingFactor);

		~MovingAverageSensor();

		/**
			Reads a signal from a origin sensor,
			averages the signal and return it.
			@return the average signal value.
		*/
		int read() override;

	private:
		inline void init();

		inline int movingAverage(int input);
};

#endif
