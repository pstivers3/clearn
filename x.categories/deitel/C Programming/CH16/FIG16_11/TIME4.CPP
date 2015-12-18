// TIME4.CPP
// Member function definitions for Time class.
#include "time4.h"
#include <iostream.h>

// Constructor function to initialize private data.
// Calls member function setTime to set variables.
// Default values are 0 (see class definition).
Time::Time(int hr, int min, int sec)
   { setTime(hr, min, sec); }

// Set the values of hour, minute, and second.
void Time::setTime(int h, int m, int s)
{
   hour = (h >= 0 && h < 24) ? h : 0;
   minute = (m >= 0 && m < 60) ? m : 0;
   second = (s >= 0 && s < 60) ? s : 0;
}

// Get the hour value
int Time::getHour() { return hour; }

// BAD PROGRAMMING PRACTICE:
// Returning a reference to a private data member.
int &Time::badSetHour(int hh)
{
   hour = (hh >= 0 && hh < 24) ? hh : 0;

   return hour;  // DANGEROUS reference return
}
