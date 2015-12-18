// HOURLY1.CPP
// Member functions for class HourlyWorker
#include <iostream.h>
#include "hourly1.h"

// Constructor for class HourlyWorker
HourlyWorker::HourlyWorker(const char *first, const char *last,
                           float w, float h)
   : Employee(first, last)   // call base-class constructor
{
   wage = w > 0 ? w : 0;
   hours = h >= 0 && h < 168 ? h : 0;
}

// Set the wage
void HourlyWorker::setWage(float w) { wage = w > 0 ? w : 0; }

// Set the hours worked
void HourlyWorker::setHours(float h)
{ hours = h >= 0 && h < 168 ? h : 0; }

// Get the HourlyWorker's pay
float HourlyWorker::earnings() const { return wage * hours; }

// Print the HourlyWorker's name and pay
void HourlyWorker::print() const
{
   cout << "\n    Hourly worker: " << getFirstName()
	<< ' ' << getLastName();
}
