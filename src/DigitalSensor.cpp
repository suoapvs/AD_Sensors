/**
	The class implements a set of methods of the DigitalSensor.h 
	library for working with a digital sensor.

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(const int pin) 
 : DigitalSensor::DigitalSensor(pin, false){
}
		
DigitalSensor::DigitalSensor(const int pin, const boolean invert) {
	this->pin = pin;
	this->signal = (invert ? LOW : HIGH);
	pinMode(this->pin, INPUT_PULLUP);
}

boolean DigitalSensor::isHigh() {
	return digitalRead(this->pin) == this->signal;
}

boolean DigitalSensor::isLow() {
	return !isHigh();
}
