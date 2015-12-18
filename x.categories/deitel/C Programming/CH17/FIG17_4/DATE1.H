// DATE1.H  --> cpp_htp\classes\ex11
// Declaration of the Date class.
// Member functions defined in DATE1.CPP

#ifndef DATE1_H
#define DATE1_H

class Date {
public:
   Date(int = 1, int = 1, int = 1900);  // default constructor
   void print() const;  // print date in month/day/year format
private:
   int month;  // 1-12
   int day;    // 1-31 based on month
   int year;   // any year

   // utility function to test proper day for month and year
   int checkDay(int);
};

#endif
