/**
	AnalogSensor.h - The library describes
	a set of methods for working with an analog sensor.

	Instantiation:
		AnalogSensor sensor(A1);

	Read signal:
		int value = sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "Sensor.h"

class AnalogSensor final : public Sensor {

	private:
		int pin;

	public:
		/**
			Constructor.
			@param pin - an analog port number
			that is attached to the sensor.
		*/
		AnalogSensor(int pin);

		/**
			Reads and return a signal from the analog sensor,
			from an analog port.
			@return the analog sensor signal.
		*/
		int read() override;
};

#endif
