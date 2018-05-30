#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(const int pin)
 : DigitalSensor::DigitalSensor(pin, false){
}

DigitalSensor::DigitalSensor(const int pin, const boolean invert) {
	this->pin = pin;
	pinMode(this->pin, INPUT_PULLUP);
	invertSignal(invert);
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
