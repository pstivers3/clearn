// DATE1.CPP
// Member function definitions for Date class.
#include <iostream.h>
#include "date1.h"

// Constructor: Confirm proper value for month;
// call utility function checkDay to confirm proper
// value for day.
Date::Date(int mn, int dy, int yr)
{
   month = (mn > 0 && mn <= 12) ? mn : 1;  // validate
   year = yr;                      // could also check
   day = checkDay(dy);                     // validate

   cout << "Date object constructor for date ";
   print();
   cout << endl;
}

// Utility function to confirm proper day value
// based on month and year.
int Date::checkDay(int testDay)
{
   static int daysPerMonth[13] = {0, 31, 28, 31, 30,
                                  31, 30, 31, 31, 30,
                                  31, 30, 31};

   if (month != 2)

      if (testDay > 0 && testDay < daysPerMonth[month])
         return testDay;

   else {  // February: Check for possible leap year
      int days = (year % 400 == 0 ||
		 (year % 4 == 0 && year % 100 != 0) ? 29 : 28);

      if (testDay > 0 && testDay < days)
         return testDay;
   }

   cout << "Day " << testDay << " invalid. Set to day 1.\n";
   return 1;  // leave object in consistent state if bad value
}

// Print Date object in form  month/day/year
void Date::print() const
   { cout << month << '/' << day << '/' << year; }
