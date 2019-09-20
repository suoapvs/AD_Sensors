/**
	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#include "AverageSensor.h"

AverageSensor::AverageSensor(
	Sensor* origin,
	const int readingsNumber,
	const int delayTime
) {
	this->origin = origin;
	this->readingsNumber = validate(readingsNumber, DEFAULT_READINGS_NUMBER);
	this->delayTime = validate(delayTime, DEFAULT_DELAY_TIME);
}

AverageSensor::~AverageSensor() {
	delete this->origin;
}

int AverageSensor::read() {
	int sum = 0;
	for (int i = 0; i < this->readingsNumber; ++i) {
		sum += this->origin->read();
		sleep();
	}
	return (sum / this->readingsNumber);
}

inline void AverageSensor::sleep() {
	delay(this->delayTime);
}

template <typename A, typename B>
inline A AverageSensor::validate(A data, B alternative) {
	return (data > 0) ? data : alternative;
}
