/**
	AverageSensor.h - Reads a signal from a delegated sensor,
	averages the signal and return it.

	Instantiation:
	  Sensor otherSensor();
		AverageSensor sensor(otherSensor, 0, 100);

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
		const Sensor* sensor;
		int counter;
		int delayTime;

	public:
		/**
		  Constructor.
		  @param counter - number of readings;
		  @param delayTime - delay time between readings.
		*/
		AverageSensor(
			Sensor* delegateSensor,
			int counter,
			int delayTime
		);

		~AverageSensor() override;

		/**
		  Reads a signal from a delegated sensor,
		  averages the signal and return it.
		*/
		int read() override;

	private:
		inline void sleep();
};

#endif
