/**
	ConstrainSensor.h - Reads a signal from a delegated sensor,
	constrains the signal and return it.

	Instantiation:
	  Sensor otherSensor();
		ConstrainSensor sensor(otherSensor, 0, 100);

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
		const Sensor* sensor;
		int low;
		int high;

	public:
		ConstrainSensor(
			const Sensor* delegateSensor,
			int low,
			int high
		);

		~ConstrainSensor() override;

		/**
			Reads a signal from a delegated sensor,
			constrains the signal and return it.
		*/
		int read() override;
};

#endif
