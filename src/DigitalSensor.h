/**
	DigitalSensor - class describes
	a set of methods for working with a digital sensor.

	Instantiation:
	Sensor* digitalSensor = new DigitalSensor(2);

	Read signal:
	int value = digitalSensor->read();
	boolean value = digitalSensor->isHigh();
	boolean value = digitalSensor->isLow();

	v.1.3.3
	Updated documentation.

	v.1.3.4
	Replaced "define" constants with "static const".

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Sensor.h"

class DigitalSensor final : public Sensor {

	private:
		static const boolean DEFAULT_INVERT_SIGNAL = false;

		int pin;

		/**
		Actuation signal.
		If invert signal: signal = LOW
		If not invert signal: signal = HIGH
		*/
		int signal;

	public:
		/**
			Constructor

			@param pin - a digital port number
			that is attached to the sensor
			@param invert - invert sensor signal (default, false)
		*/
		DigitalSensor(
			int pin,
			boolean invert = DEFAULT_INVERT_SIGNAL
		);

		/**
			Reads and return a signal from the digital sensor,
			from a digital port.

			@return 0 or 1 (0 == LOW, 1 == HIGH)
		*/
		int read() override;

		/**
			Checks a signal on the digital sensor,
			on the digital port.

			@return true if the sensor signal is high,
			false - otherwise
		*/
		boolean isHigh();

		/**
			Checks a signal on the digital sensor,
			on the digital port.

			@return true if the sensor signal is low,
			false - otherwise
		*/
		boolean isLow();

		/**
			Inverts sensor signal.

			@param invert - invert sensor signal
		*/
		void invertSignal(boolean invert);
};

#endif
