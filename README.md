# Analog-Digital Sensors Library

For Arduino boards.

The Library implements a set of methods for working with digital and analog sensors.

## Installation

1. [Download](https://github.com/YuriiSalimov/AD_Sensors/releases) the Latest release from GitHub.
2. Unzip and modify the Folder name to "AD_Sensors" (Remove the '-version')
3. Paste the modified folder on your Library folder
(On your `libraries` folder inside Sketchbooks or Arduino software).
4. Restart the Arduino IDE.

### Analog Sensor

Describes a set of methods for working with an analog sensor.

```cpp
#include <AnalogSensor.h>

/**
	ANALOG_PIN - an analog port number that
	is attached to the sensor.
*/
AnalogSensor* sensor = new AnalogSensor(ANALOG_PIN);

/**
	Reads and return a signal from the analog sensor,
	from an analog port.
*/
int value = sensor->read();
```

### Digital Sensor

Describes a set of methods for working with a digital sensor.

```cpp
#include <DigitalSensor.h>

/**
	DIGITAL_PIN - a digital port number that
	is attached to the sensor.
*/
DigitalSensor* sensor = new DigitalSensor(DIGITAL_PIN);

/**
	If you need to invert a sensor signal:
	INVERT_SIGNAL:
		true - invert a signal;
		false - not invert a signal.
*/
DigitalSensor* sensor = new DigitalSensor(DIGITAL_PIN, INVERT_SIGNAL);

/**
	Reads and return a signal from the digital sensor
	(0 or 1, 0 == LOW, 1 == HIGH).
*/
int value = sensor->read();

/**
	Checks a signal on the digital sensor,
	on the digital port. Return true if
	the sensor signal is high, false - otherwise.
*/
boolean value = sensor->isHigh();

/**
	Checks a signal on the digital sensor,
	on the digital port. Return true if
	the sensor signal is low, false - otherwise.
*/
boolean value = sensor->isLow();
```

### Map Sensor

Reads a signal from a delegated sensor,
maps the signal and return it.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <MapSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

Sensor* sensor = new MapSensor(
	origin,
	FROM_LOW, FROM_HIGH,
	TO_LOW, TO_HIGH
);

int value = sensor->read();
```

### Average Sensor

Reads a signal from a delegated sensor,
averages the signal and return it.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <AverageSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

/**
	COUNTER - number of readings;
	DELAY_TIME - delay time between readings.
*/
Sensor* sensor = new AverageSensor(origin, COUNTER, DELAY_TIME);

int value = sensor->read();
```

### Constrain Sensor

Reads a signal from a delegated sensor,
constrains the signal and return it.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <ConstrainSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

/**
	COUNTER - number of readings;
	DELAY_TIME - delay time between readings.
*/
Sensor* sensor = new ConstrainSensor(origin, COUNTER, DELAY_TIME);

int value = sensor->read();
```

## Example

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <AverageSensor.h>
#include <MapSensor.h>
#include <ConstrainSensor.h>

...

Sensor* sensor = new ConstrainSensor(
	new MapSensor(
		new AverageSensor(
			new AnalogSensor(A1),
			10, 10
		),
		0, 1023, 0, 1000
	),
	100, 900
);

int value = sensor->read()
```

Created by Yurii Salimov.
