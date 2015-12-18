// FIG16_1.CPP
// Create a structure, set its members, and print it.
#include <iostream.h>

struct Time {    // structure definition
   int hour;     // 0-23
   int minute;   // 0-59
   int second;   // 0-59
};

void printMilitary(const Time &);  // prototype
void printStandard(const Time &);  // prototype

main()
{
   Time dinnerTime;    // variable of new type Time

   // set members to valid values
   dinnerTime.hour = 18;
   dinnerTime.minute = 30;
   dinnerTime.second = 0;

   cout << "Dinner will be held at ";
   printMilitary(dinnerTime);
   cout << " military time,\nwhich is ";
   printStandard(dinnerTime);
   cout << " standard time." << endl;

   // set members to invalid values
   dinnerTime.hour = 29;
   dinnerTime.minute = 73;
   dinnerTime.second = 103;

   cout << "\nTime with invalid values: ";
   printMilitary(dinnerTime);
   cout << endl;

   return 0;
}

// Print the time in military format
void printMilitary(const Time &t)
{
   cout << (t.hour < 10 ? "0" : "") << t.hour << ":"
	<< (t.minute < 10 ? "0" : "") << t.minute << ":"
	<< (t.second < 10 ? "0" : "") << t.second;
}

// Print the time in standard format
void printStandard(const Time &t)
{
   cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12)
	<< ":" << (t.minute < 10 ? "0" : "") << t.minute
	<< ":" << (t.second < 10 ? "0" : "") << t.second
	<< (t.hour < 12 ? " AM" : " PM");
}
