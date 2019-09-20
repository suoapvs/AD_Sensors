/**
  AnalogSensor - class describes
  a set of methods for working with an analog sensor.

  Instantiation:
  Sensor* analogSensor = new AnalogSensor(A1);

  Read signal:
  int value = sensor->read();

  v.1.3.3
  - updated documentation

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "Sensor.h"

class AnalogSensor final : public Sensor {

  private:
    int pin;

  public:
    /**
      Constructor

      @param pin - an analog port number
      that is attached to the sensor
    */
    AnalogSensor(int pin);

    /**
      Reads and return a signal from the analog sensor,
      from an analog port.

      @return the analog sensor signal.
    */
    int read() override;
};

#endif
