# Analog-Digital Sensors Library

For Arduino boards.

The Library implements a set of methods for working with digital and analog sensors.

## Installation

1. [Download](https://github.com/YuriiSalimov/AD_Sensors/releases) the Latest release from GitHub.
2. Unzip and modify the Folder name to "AD_Sensors" (Remove the '-version')
3. Paste the modified folder on your Library folder
(On your `libraries` folder inside Sketchbooks or Arduino software).
4. Restart the Arduino IDE.

### [Analog Sensor](/src/AnalogSensor.h)

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

### [Digital Sensor](/src/DigitalSensor.h)

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
    on the digital port.
    Returns true if the sensor signal is high,
    false - otherwise.
*/
boolean value = sensor->isHigh();

/**
    Checks a signal on the digital sensor,
    on the digital port.
    Returns true if the sensor signal is low,
    false - otherwise.
*/
boolean value = sensor->isLow();
```

### [Map Sensor](/src/MapSensor.h)

Reads a signal from a origin sensor, maps the signal and return it.
Re-maps the signal from one range to another.
That is, a signal of fromLow would get mapped to toLow,
a signal of fromHigh to toHigh, signals in-between to signals in-between, etc.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <MapSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

/**
    FROM_LOW - the lower bound of the value’s current range;
    FROM_HIGH - the upper bound of the value’s current range;
    TO_LOW - the lower bound of the value’s target range;
    TO_HIGH - the upper bound of the value’s target range.
*/
Sensor* sensor = new MapSensor(
    origin,
    FROM_LOW, FROM_HIGH,
    TO_LOW, TO_HIGH
);

/**
    Returns the mapped signal value.
*/
int value = sensor->read();
```

### [Average Sensor](/src/AverageSensor.h)

Reads a signal from a origin sensor,
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

/**
    Returns the average signal value.
*/
int value = sensor->read();
```

### [SmoothSensor](/src/SmoothSensor.h)

Reads a signal from a origin sensor,
smoothes (moving average, rolling average or running average)
the signal and return it.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <SmoothSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

/**
    SMOOTHING_FACTOR - smoothing factor of readings (0 = not smooth).
*/
Sensor* sensor = new SmoothSensor(origin, SMOOTHING_FACTOR);

/**
    Return the average signal value.
*/
int value = sensor->read();
```

### [Constrain Sensor](/src/ConstrainSensor.h)

Reads a signal from a origin sensor,
constrains the signal and return it.

```cpp
#include <Sensor.h>
#include <AnalogSensor.h>
#include <ConstrainSensor.h>

Sensor* origin = new AnalogSensor(ANALOG_PIN);

/**
    LOW - the lower end of the constraint range;
    HIGH - the upper end of the constraint range.
*/
Sensor* sensor = new ConstrainSensor(origin, LOW, HIGH);

/**
    Returns the constrained signal value.
*/
int value = sensor->read();
```

See [examples](/examples)...

Created by Yurii Salimov.
