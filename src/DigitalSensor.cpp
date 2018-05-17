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
	pinMode(this->pin, INPUT_PULLUP);
	invertSignal(invert);
  Serial.println("DigitalSensor constructor");
}

int DigitalSensor::read() {
  return digitalRead(this->pin);
}

boolean DigitalSensor::isHigh() {
	return read() == this->signal;
}

boolean DigitalSensor::isLow() {
	return !isHigh();
}

void DigitalSensor::invertSignal(const boolean invert) {
	this->signal = (invert ? LOW : HIGH);
}
