#include "AverageSensor.h"

AverageSensor::AverageSensor(
	const Sensor* sensor,
	const int counter,
	const int delayTime
) {
	this->sensor = sensor;
	this->counter = max(counter, AVERAGE_SENSOR_MIN_COUNTER);
	this->delayTime = max(delayTime, AVERAGE_SENSOR_MIN_TIME_DELAY);
}

int AverageSensor::read() {
	long sum = 0;
	for (int i = 0; i < this->counter; i++) {
		sum += this->sensor->read();
		sleep();
	}
	return (sum / this->counter);
}

void AverageSensor::sleep() {
	delay(this->delayTime);
}
