// FIG5_8.CPP
// Demonstrating a default constructor
// function for class Time.
#include <iostream.h>
#include "time2.h"

main()
{
   Time t1, t2(2), t3(21, 34), t4(12, 25, 42),
        t5(27, 74, 99);

   cout << "Constructed with:\n"
        << "all arguments defaulted:\n   ";
   t1.printMilitary();
   cout << "\n   ";
   t1.printStandard();
   cout << "\nhour specified; minute and second defaulted:\n   ";
   t2.printMilitary();
   cout << "\n   ";
   t2.printStandard();
   cout << "\nhour and minute specified; second defaulted:\n   ";
   t3.printMilitary();
   cout << "\n   ";
   t3.printStandard();
   cout << "\nhour, minute, and second specified:\n   ";
   t4.printMilitary();
   cout << "\n   ";
   t4.printStandard();
   cout << "\nall invalid values specified:\n   ";
   t5.printMilitary();
   cout << "\n   ";
   t5.printStandard();
   cout << endl;

   return 0;
}