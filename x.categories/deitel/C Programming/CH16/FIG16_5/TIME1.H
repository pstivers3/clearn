// TIME1.H
// Declaration of the Time class.
// Member functions are defined in TIME.CPP

// prevent multiple inclusions of header file
#ifndef TIME1_H
#define TIME1_H

// Time abstract data type definition
class Time {
public:
   Time();                       // default constructor
   void setTime(int, int, int);  // set hour, minute and second
   void printMilitary();         // print military time format
   void printStandard();         // print standard time format
private:
   int hour;     // 0 - 23
   int minute;   // 0 - 59
   int second;   // 0 - 59
};

#endif