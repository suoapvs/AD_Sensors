/**
	SmoothSensor.h - Reads a signal from a origin sensor,
	smoothes (moving average, rolling average or running average)
	the signal and return it.
	Wiki: https://en.wikipedia.org/wiki/Moving_average

	Instantiation:
		Sensor origin();
		SmoothSensor sensor(origin, 5);

	Read signal:
		int value = sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, January, 2019.
	Released into the public domain.
*/
#ifndef SMOOTH_SENSOR_H
#define SMOOTH_SENSOR_H

#include "Sensor.h"

class SmoothSensor final : public Sensor {

	private:
		Sensor* origin;
		int factor;
		int data;

	public:
		/**
			Constructor.
			@param origin - the origin sensor;
			@param factor - smoothing factor of readings (0 = not smooth)
		*/
		SmoothSensor(Sensor* origin, int factor);

		~SmoothSensor();

		/**
			Reads a signal from a origin sensor,
			averages the signal and return it.
			@return the average signal value.
		*/
		int read() override;

	private:
		inline void init();

		inline int smoothe(int input);
};

#endif
