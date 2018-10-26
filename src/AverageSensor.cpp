#include "AverageSensor.h"

AverageSensor::AverageSensor(
	const Sensor* delegateSensor,
	const int counter,
	const int delayTime
) {
	this->sensor = delegateSensor;
	this->counter = max(counter, AVERAGE_SENSOR_MIN_COUNTER);
	this->delayTime = max(delayTime, AVERAGE_SENSOR_MIN_TIME_DELAY);
}

AverageSensor::~AverageSensor() {
	delete this->sensor;
}

int AverageSensor::read() {
	long sum = 0;
	for (int i = 0; i < this->counter; i++) {
		sum += this->sensor->read();
		sleep();
	}
	return (sum / this->counter);
}

inline void AverageSensor::sleep() {
	delay(this->delayTime);
}
