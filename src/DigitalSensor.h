/**
	DigitalSensor.h - The library describes
	a set of methods for working with a digital sensor.

	Instantiation:
		DigitalSensor sensor(2);

	Read signal:
		sensor.read();
		sensor.isHigh();
		sensor.isLow();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Sensor.h"

class DigitalSensor final :
	public Sensor {

	private:
		/**
			Port number that is attached to the sensor.
		*/
		int pin = 0;

		/**
			Actuation signal.
			If invert signal:
				signal = LOW
			If not invert signal:
				signal = HIGH
		*/
		int signal;

	public:
		/**
			Constructor.
			@param pin - a digital port number
			that is attached to the sensor.
		*/
		DigitalSensor(const int pin);

		/**
			Constructor.
			@param pin - a digital port number
			that is attached to the sensor.
			@param invert - invert sensor signal.
		*/
		DigitalSensor(const int pin, const boolean invert);

		/**
			Reads and return a signal from the digital sensor,
			from a digital port.
		*/
		int read() override;

		/**
			Checks a signal on the digital sensor,
			on the digital port.
			@return true if the sensor signal is high,
			false - otherwise.
		*/
		boolean isHigh();

		/**
			Checks a signal on the digital sensor,
			on the digital port.
			@return true if the sensor signal is low,
			false - otherwise.
		*/
		boolean isLow();

		/**
			Inverts sensor signal.
			@param invert - invert sensor signal.
		*/
		void invertSignal(const boolean invert);
};

#endif
