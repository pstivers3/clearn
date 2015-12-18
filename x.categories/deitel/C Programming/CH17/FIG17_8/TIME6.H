// TIME6.H
// Declaration of class Time.
// Member functions defined in TIME6.CPP

#ifndef TIME6_H
#define TIME6_H

class Time {
public:
   Time(int = 0, int = 0, int = 0);  // default constructor

   // set functions
   Time &setTime(int, int, int);  // set hour, minute, second
   Time &setHour(int);    // set hour
   Time &setMinute(int);  // set minute
   Time &setSecond(int);  // set second

   // get functions (normally declared const)
   int getHour() const;   // return hour
   int getMinute() const; // return minute
   int getSecond() const; // return second

   // print functions (normally declared const)
   void printMilitary() const;  // print military time
   void printStandard() const;  // print standard time
private:
   int hour;              // 0 - 23
   int minute;            // 0 - 59
   int second;            // 0 - 59
};

#endif