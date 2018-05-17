/**
	The class implements a set of methods of the AnalogSensor.h
	library for working with an analog sensor.

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(const int pin) {
	this->pin = pin;
	pinMode(this->pin, INPUT);
}

int AnalogSensor::read() {
	return analogRead(this->pin);
}
