// TIME2.CPP  --> cpp_htp\classes\ex06
// Member function definitions for Time class.
#include "time2.h"
#include <iostream.h>

// Constructor function to initialize private data.
// Default values are 0 (see class definition).
Time::Time(int hr, int min, int sec)
{
   hour = (hr >= 0 && hr < 24) ? hr : 0;
   minute = (min >= 0 && min < 60) ? min : 0;
   second = (sec >= 0 && sec < 60) ? sec : 0;
}

// Set values of hour, minute, and second.
// Invalid values are set to 0.
void Time::setTime(int h, int m, int s)
{
   hour = (h >= 0 && h < 24) ? h : 0;
   minute = (m >= 0 && m < 60) ? m : 0;
   second = (s >= 0 && s < 60) ? s : 0;
}

// Display time in military format: HH:MM:SS
void Time::printMilitary()
{
   cout << (hour < 10 ? "0" : "") << hour << ":"
	<< (minute < 10 ? "0" : "") << minute << ":"
	<< (second < 10 ? "0" : "") << second;
}

// Display time in standard format: HH:MM:SS AM (or PM)
void Time::printStandard()
{
   cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
	<< ":" << (minute < 10 ? "0" : "") << minute
	<< ":" << (second < 10 ? "0" : "") << second
	<< (hour < 12 ? " AM" : " PM");
}
