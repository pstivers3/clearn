// TIME4.H
// Declaration of the Time class.
// Member functions defined in TIME4.CPP

// prevent multiple inclusions of header file
#ifndef TIME4_H
#define TIME4_H

class Time {
public:
   Time(int = 0, int = 0, int = 0);
   void setTime(int, int, int);
   int getHour();
   int &badSetHour(int);  // DANGEROUS reference return
private:
   int hour;
   int minute;
   int second;
};

#endif