/**
	ConstrainSensor.h - Reads a signal from a delegated sensor,
	constrains the signal and return it.

	Instantiation:
	  Sensor otherSensor();
		ConstrainSensor sensor(otherSensor, 0, 100);

	Read signal:
		sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef CONSTRAIN_SENSOR_H
#define CONSTRAIN_SENSOR_H

#include "Sensor.h"

class ConstrainSensor final :
	public Sensor {

	private:
		const Sensor* sensor;
    int low = 0;
    int high = 0;

	public:
		ConstrainSensor(const Sensor* sensor, const int low, const int high);

		int read() override;
};

#endif
