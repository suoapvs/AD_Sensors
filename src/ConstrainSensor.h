/**
  ConstrainSensor - class-wrapper allows to constraint
  a signal value of origin Sensor instance.

  Instantiation:
  Sensor* constrainSensor = new ConstrainSensor(
    SENSOR, LOW, HIGH
  );

  Where,
  SENSOR - origin Sensor instance.
  LOW - the lower end of the constraint range.
  HIGH - the upper end of the constraint range.

  Read signal:
  int value = constrainSensor->read();

  v.1.3.3
  - optimized read() method;
  - updated documentation.

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#ifndef CONSTRAIN_SENSOR_H
#define CONSTRAIN_SENSOR_H

#include "Sensor.h"

class ConstrainSensor final : public Sensor {

  private:
    Sensor* origin;
    int low;
    int high;

  public:
    /**
      Constructor

      @param origin - the origin sensor (not NULL)
      @param low - the lower end of the constraint range
      @param high - the upper end of the constraint range
    */
    ConstrainSensor(Sensor* origin, int low, int high);

    /**
      Destructor
      Deletes the origin Sensor instance.
    */
    ~ConstrainSensor();

    /**
      Reads a signal from the origin sensor,
      constrains the signal and return it.
      Example,
      x = the sensor signal;
      a = low end of the constraint range;
      b = high end of the constraint range.

      @return the constrained signal value:
      x: if x is between a and b;
      a: if x is less than a;
      b: if x is greater than b.
    */
    int read() override;
};

#endif
