// HOURLY.H
// Definition of class HourlyWorker
#ifndef HOURLY_H
#define HOURLY_H

#include "employ.h"

class HourlyWorker : public Employee {
public:
   HourlyWorker(const char*, const char*, float, float);
   float getPay() const;  // calculate and return salary
   void print() const;    // redefined base-class print
private:
   float wage;            // wage per hour
   float hours;           // hours worked for week
};

#endif