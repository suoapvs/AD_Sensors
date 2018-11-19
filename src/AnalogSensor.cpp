#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(const int pin) {
	this->pin = pin;
	init();
}

inline void AnalogSensor::init() {
	pinMode(this->pin, INPUT);
}

int AnalogSensor::read() {
	return analogRead(this->pin);
}
