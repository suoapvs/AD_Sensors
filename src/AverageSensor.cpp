#include "AverageSensor.h"

AverageSensor::AverageSensor(
	const Sensor* origin,
	const int counter,
	const int delayTime
) {
	this->origin = origin;
	this->counter = max(counter, AVERAGE_SENSOR_MIN_COUNTER);
	this->delayTime = max(delayTime, AVERAGE_SENSOR_MIN_TIME_DELAY);
}

AverageSensor::~AverageSensor() {
	delete this->origin;
}

int AverageSensor::read() {
	long sum = 0;
	for (int i = 0; i < this->counter; i++) {
		sum += this->origin->read();
		sleep();
	}
	return (sum / this->counter);
}

inline void AverageSensor::sleep() {
	delay(this->delayTime);
}
