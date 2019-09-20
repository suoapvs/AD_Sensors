/**
  AverageSensor - class-wrapper allows to average
  a signal value of origin Sensor instance.

  Instantiation:
  Sensor* averageSensor = new AverageSensor(
    SENSOR, READINGS_NUMBER, DELAY_TIME
  );

  Where,
  SENSOR - origin Sensor instance.

  READINGS_NUMBER - How many readings are taken
  to determine a mean signal. The more values,
  the longer a calibration is performed, but the readings
  will be more accurate.

  DELAY_TIME - Delay time between a signal readings
  from the sensor (ms).

  Read signal:
  int value = averageSensor->read();

  v.1.3.3
  - optimized average(*) method;
  - renamed default constants;
  - added default value of constructor parameters;
  - updated documentation.

  v.1.3.4
  Replaced "define" constants with "static const".

  https://github.com/YuriiSalimov/AD_Sensors

  Created by Yurii Salimov, May, 2018.
  Released into the public domain.
*/
#ifndef AVERAGE_SENSOR_H
#define AVERAGE_SENSOR_H

#include "Sensor.h"

class AverageSensor final : public Sensor {

  private:
    // Default number of average readings.
    static const int DEFAULT_READINGS_NUMBER = 1;
    // Default delay time of average readings.
    static const int DEFAULT_DELAY_TIME = 1;

    Sensor* origin;
    int readingsNumber;
    int delayTime;

  public:
    /**
      Constructor

      @param origin - the origin sensor (not NULL)
      @param readingsNumber - number of readings (default, 1)
      @param delayTime - delay time between readings (default, 1)
    */
    AverageSensor(
      Sensor* origin,
      int readingsNumber = DEFAULT_READINGS_NUMBER,
      int delayTime = DEFAULT_DELAY_TIME
    );

    /**
      Destructor
      Deletes the origin Sensor instance.
    */
    ~AverageSensor();

    /**
      Reads a signal from the origin sensor,
      averages the signal and return it.

      @return the average signal value.
    */
    int read() override;

  private:
    /**
      For delay between readings.
    */
    inline void sleep();

    /**
      Validates the input data.

      @param data - value to validate
      @param alternative - alternative value to return
      @returns the data if it is valid (> 0),
      otherwise returns alternative data.
    */
    template <typename A, typename B>
    inline A validate(A data, B alternative);
};

#endif
