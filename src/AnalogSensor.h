/**
	AnalogSensor.h - The library describes 
	a set of methods for working with an analog sensor.

	Instantiation:
		AnalogSensor sensor(A1);

	Read signal:
		sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif 

class AnalogSensor final {
	
	private:
		/**
			Port number that is attached to the sensor.
		*/
		int pin = 0;
	
	public:
		/**
			Constructor.
			@param pin - an analog port number 
			that is attached to the sensor.
		*/
		AnalogSensor(const int pin);

		/**
			Reads and return a signal from the analog sensor, 
			from an analog port.
			@return the analog sensor signal.
		*/
		int read();
};

#endif
