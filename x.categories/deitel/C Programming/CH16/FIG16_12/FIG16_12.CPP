// FIG5_12.CPP
// Demonstrating that class objects can be assigned
// to each other using default memberwise copy
#include <iostream.h>

// Simple Date class
class Date {
public:
   Date(int = 1, int = 1, int = 1990);  // default constructor
   void print();
private:
   int month;
   int day;
   int year;
};

// Simple Date constructor with no range checking
Date::Date(int m, int d, int y)
{
   month = m;
   day = d;
   year = y;
}

// Print the Date in the form mm-dd-yyyy
void Date::print()
{ cout << month << '-' << day << '-' << year; }

main()
{
   Date d1(7, 4, 1993), d2;  // d2 defaults to 1/1/90

   cout << "d1 = ";
   d1.print();
   cout << "\nd2 = ";
   d2.print();

   d2 = d1;     // assignment by default memberwise copy
   cout << "\n\nAfter default memberwise copy, d2 = ";
   d2.print();
   cout << endl;

   return 0;
}