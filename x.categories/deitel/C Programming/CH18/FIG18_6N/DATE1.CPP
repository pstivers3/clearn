// DATE1.CPP
// Member function definitions for Date class
#include <iostream.h>
#include "date1.h"

// Initialize static member at file scope;
// one class-wide copy.
int Date::days[] = {0, 31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31};

// Date constructor
Date::Date(int m, int d, int y) { setDate(m, d, y); }

// Set the date
void Date::setDate(int mm, int dd, int yy)
{
   month = (mm >= 1 && mm <= 12) ? mm : 1;
   year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

   // test for a leap year
   if (month == 2 && year % 4 == 0 && (year % 400 == 0 ||
                                       year % 100 != 0))
      day = (dd >= 1 && dd <= 29) ? dd : 1;
   else
      day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

// Preincrement operator overloaded as a member function.

Date Date::operator++()
{
   helpIncrement();
   return *this;  // value return; not a reference return
}

// Postincrement operator overloaded as a member function.
// Note that the dummy integer parameter does not have a
// parameter name.

Date Date::operator++(int)
{
   Date temp = *this;
   helpIncrement();

   // return non-incremented, saved, temporary object
   return temp;   // value return; not a reference return
}

// Add a specific number of days to a date

Date &Date::operator+=(int additionalDays)
{
   for (int i = 1; i <= additionalDays; i++)
      helpIncrement();

   return *this;    // enables concatenation
}

// Function to help increment the date
void Date::helpIncrement()
{
   // test for a leap year first
   if (month == 2 && day < 29 && year % 4 == 0 &&
       (year % 400 == 0 || year % 100 != 0))
      ++day;
   else if (day < Date::days[month])  // not last day of month
      ++day;
   else if (month < 12) {  // last day of month < December
      ++month;
      day = 1;
   }
   else {                  // December 31
      month = 1;
      day = 1;
      ++year;
   }
}

// Overloaded output operator
ostream &operator<<(ostream &output, const Date &d)
{
   static char *monthName[13] = {"", "January",
      "February", "March", "April", "May", "June",
      "July", "August", "September", "October",
      "November", "December"};

   output << monthName[d.month] << ' '
          << d.day << ", " << d.year;

   return output;   // enables concatenation
}

