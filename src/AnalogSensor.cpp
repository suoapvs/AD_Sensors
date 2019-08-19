/**
	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(const int pin) {
	pinMode(this->pin = pin, INPUT);
}

int AnalogSensor::read() {
	return analogRead(this->pin);
}
