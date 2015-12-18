// TIME5.CPP
// Member function definitions for Time class.
#include "time5.h"
#include <iostream.h>

// Constructor function to initialize private data.
// Default values are 0 (see class definition).
Time::Time(int hr, int min, int sec)
{
   hour = (hr >= 0 && hr < 24) ? hr : 0;
   minute = (min >= 0 && min < 60) ? min : 0;
   second = (sec >= 0 && sec < 60) ? sec : 0;
}

// Set the values of hour, minute, and second.
void Time::setTime(int h, int m, int s)
{
   hour = (h >= 0 && h < 24) ? h : 0;
   minute = (m >= 0 && m < 60) ? m : 0;
   second = (s >= 0 && s < 60) ? s : 0;
}

// Set the hour value
void Time::setHour(int h)
   { hour = (h >= 0 && h < 24) ? h : 0; }

// Set the minute value
void Time::setMinute(int m)
   { minute = (m >= 0 && m < 60) ? m : 0; }

// Set the second value
void Time::setSecond(int s)
   { second = (s >= 0 && s < 60) ? s : 0; }

// Get the hour value
int Time::getHour() const { return hour; }

// Get the minute value
int Time::getMinute() const { return minute; }

// Get the second value
int Time::getSecond() const { return second; }

// Display military format time: HH:MM:SS
void Time::printMilitary() const
{
   cout << (hour < 10 ? "0" : "") << hour << ":"
	<< (minute < 10 ? "0" : "") << minute << ":"
	<< (second < 10 ? "0" : "") << second;
}

// Display standard format time: HH:MM:SS AM (or PM)
void Time::printStandard() const
{
   cout << ((hour == 12) ? 12 : hour % 12) << ":"
	<< (minute < 10 ? "0" : "") << minute << ":"
	<< (second < 10 ? "0" : "") << second
	<< (hour < 12 ? " AM" : " PM");
}
