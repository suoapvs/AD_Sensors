#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(const int pin) {
	this->pin = pin;
	pinMode(this->pin, INPUT);
}

int AnalogSensor::read() {
	return analogRead(this->pin);
}
