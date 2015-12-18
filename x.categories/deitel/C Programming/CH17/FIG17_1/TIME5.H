// TIME5.H
// Declaration of the Time class.
// Member functions defined in TIME5.CPP

#ifndef TIME5_H
#define TIME5_H

class Time {
public:
   Time(int = 0, int = 0, int = 0);  // default constructor

   // set functions
   void setTime(int, int, int);  // set time
   void setHour(int);     // set hour
   void setMinute(int);   // set minute
   void setSecond(int);   // set second

   // get functions normally declared const
   int getHour() const;   // return hour
   int getMinute() const; // return minute
   int getSecond() const; // return second

   // print functions normally declared const
   void printMilitary() const;  // print military time
   void printStandard() const;  // print standard time
private:
   int hour;              // 0 - 23
   int minute;            // 0 - 59
   int second;            // 0 - 59
};

#endif