// TIME2.H
// Declaration of the Time class.
// Member functions defined in TIME2.CPP

// prevent multiple inclusions of header file
#ifndef TIME2_H
#define TIME2_H

class Time {
public:
   Time(int = 0, int = 0, int = 0);  // default constructor
   void setTime(int, int, int);
   void printMilitary();
   void printStandard();
private:
   int hour;
   int minute;
   int second;
};

#endif