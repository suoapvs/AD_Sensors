/**
	DigitalSensor.h - The library describes 
	a set of methods for working with a digital sensor.

	Instantiation:
		DigitalSensor sensor(2);

	Read signal:
		sensor.isHigh();
		sensor.isLow();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif 

class DigitalSensor final {

	private:
		/**
			Port number that is attached to the sensor.
		*/
		int pin = 0;
		
		/**
			Invert sensor signal.
		*/
		boolean invert = false;
	
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
		
	private:
		/**
			Returns the sensor high signal.
			@return sensor signal.
		*/
		int signal();
};

#endif

