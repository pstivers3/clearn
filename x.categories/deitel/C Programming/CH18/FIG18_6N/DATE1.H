// DATE1.H
// Definition of class Date
#ifndef DATE1_H
#define DATE1_H

#include <iostream.h>

class Date {
   friend ostream &operator<<(ostream &, const Date &);
public:
   Date(int m = 1, int d = 1, int y = 1900);  // default constructor
   void setDate(int, int, int);  // set the date
   Date operator++();            // preincrement
   Date operator++(int);         // postincrement
   Date &operator+=(int);        // add days, modify object
private:
   int month;
   int day;
   int year;
   static int days[];     // array of days per month
   void helpIncrement();  // utility function
};

#endif