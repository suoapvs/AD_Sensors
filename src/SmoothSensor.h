/**
  SmoothSensor - class-wrapper allows to smoothe
  a signal value of origin Sensor instance.
  Wiki: https://en.wikipedia.org/wiki/Moving_average

  Instantiation:
  Sensor* smoothSensor = new SmoothSensor(SENSOR, SMOOTHING_FACTOR);

  Where,
  SENSOR - origin Sensor instance.
  SMOOTHING_FACTOR - smoothing factor of readings.

  Read signal:
  int value = smoothSensor->read();

  v.1.3.3
  - optimized smoothe(*) method;
  - renamed default constants;
  - added default value of constructor parameters;
  - updated documentation.

  v.1.3.4
  Replaced "define" constants with "static const".

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, January, 2019.
  Released into the public domain.
*/
#ifndef SMOOTH_SENSOR_H
#define SMOOTH_SENSOR_H

#include "Sensor.h"

class SmoothSensor final : public Sensor {

  private:
    // Minimum smoothing factor.
    static const int MIN_SMOOTHING_FACTOR = 2;

    Sensor* origin;
    int smoothingFactor;
    int data;

  public:
    /**
      Constructor

      @param origin - the origin sensor (not NULL)
      @param smoothingFactor - smoothing factor of readings (default, 2)
    */
    SmoothSensor(
      Sensor* origin,
      int smoothingFactor = MIN_SMOOTHING_FACTOR
    );

    /**
      Destructor
      Deletes the origin Sensor instance.
    */
    ~SmoothSensor();

    /**
      Reads a signal from a origin sensor,
      averages the signal and return it.

      @return the average signal value.
    */
    int read() override;

  private:
    /**
      Perform smoothing of the input value.

      @param input - the value to smooth
      @return smoothed value or the input value
      if the data is 0.
    */
    inline int smoothe(int input);

    /**
      Sets the smoothing factor.
      If the input value is less than NTC_MIN_SMOOTHING_FACTOR,
      then sets NTC_MIN_SMOOTHING_FACTOR.

      @param smoothingFactor - new smoothing factor
    */
    inline void setSmoothingFactor(int smoothingFactor);
};

#endif
