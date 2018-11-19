/**
	DigitalSensor.h - The library describes
	a set of methods for working with a digital sensor.

	Instantiation:
		DigitalSensor sensor(2);

	Read signal:
		int value = sensor.read();
		boolean value = sensor.isHigh();
		boolean value = sensor.isLow();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Sensor.h"

class DigitalSensor final : public Sensor {

	private:
		/**
			Port number that is attached to the sensor.
		*/
		int pin;

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
		DigitalSensor(int pin);

		/**
			Constructor.
			@param pin - a digital port number
				that is attached to the sensor.
			@param invert - invert sensor signal.
		*/
		DigitalSensor(int pin, boolean invert);

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
		void invertSignal(boolean invert);

	private:
		/**
			Initialization of module.
		*/
		inline void init();
};

#endif
