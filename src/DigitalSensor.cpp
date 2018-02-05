/**
	The class implements a set of methods of the DigitalSensor.h 
	library for working with a digital sensor.

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(const int pin) {
	this->pin = pin;
	pinMode(this->pin, INPUT_PULLUP);
}
		
DigitalSensor::DigitalSensor(const int pin, const boolean invert) 
: DigitalSensor::DigitalSensor(pin) {
	this->invert = invert;
}

boolean DigitalSensor::isHigh() {
	return digitalRead(this->pin) == signal();
}

boolean DigitalSensor::isLow() {
	return !isHigh();
}

/**
	Return the sensor high signal.
	@return LOW if the invert value is true,
	HIGH - otherwise.
*/
int DigitalSensor::signal() {
	return (this->invert ? LOW : HIGH);
}
