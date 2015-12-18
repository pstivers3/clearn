// HOURLY_B.CPP
// Member functions for class HourlyWorker
#include <iostream.h>
#include <iomanip.h>
#include "hourly.h"

// Constructor for class HourlyWorker
HourlyWorker::HourlyWorker(const char *first, const char *last,
                           float initHours, float initWage)
   : Employee(first, last)   // call base-class constructor
{
   hours = initHours;
   wage = initWage;
}

// Get the HourlyWorker's pay
float HourlyWorker::getPay() const { return wage * hours; }

// Print the HourlyWorker's name and pay
void HourlyWorker::print() const
{
   cout << "HourlyWorker::print()\n\n";

   Employee::print();   // call base-class print function

   cout << " is an hourly worker with pay of"
        << " $" << setiosflags(ios::showpoint)
        << setprecision(2) << getPay() << endl;
}