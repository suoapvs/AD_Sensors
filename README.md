# Analog-Digital Sensors Library

For Arduino boards.

The Library implements a set of methods for working with 
a digital and analog sensors.

## Installation

1. [Download](https://github.com/YuriiSalimov/AD_Sensors/releases) the Latest release from GitHub.
2. Unzip and modify the Folder name to "AD_Sensors" (Remove the '-version')
3. Paste the modified folder on your Library folder 
(On your `libraries` folder inside Sketchbooks or Arduino software).
4. Restart the Arduino IDE.

## Methods

AnalogSensor - the library describes 
a set of methods for working with an analog sensor.

```cpp
	/**
		ANALOG_PIN - an analog port number that 
		is attached to the sensor.
	*/
	AnalogSensor sensor(ANALOG_PIN);

	/**
		Reads and return a signal from the analog sensor, 
		from an analog port.
	*/
	sensor.read();
```

DigitalSensor - the library describes 
a set of methods for working with a digital sensor.

```cpp
	/**
		DIGITAL_PIN - a digital port number that 
		is attached to the sensor.
	*/
	DigitalSensor sensor(DIGITAL_PIN);
	
	/**
		If you want to invert a sensor signal:
		INVERT_SIGNAL:
			true - invert a signal;
			false - not invert a signal.
	*/
	DigitalSensor sensor(DIGITAL_PIN, INVERT_SIGNAL);

	/**
		Checks a signal on the digital sensor,
		on the digital port. Return true if 
		the sensor signal is high, false - otherwise.
	*/
	sensor.isHigh();

	/**
		Checks a signal on the digital sensor,
		on the digital port. Return true if 
		the sensor signal is low, false - otherwise.
	*/
	sensor.isLow();
```

Created by Yurii Salimov.
