// FIG17_1.CPP
// Attempting to access a const object with
// non-const member functions.
#include <iostream.h>
#include "time5.h"

main()
{
   const Time t(19, 33, 52);   // constant object

   t.setHour(12);    // ERROR: non-const member function
   t.setMinute(20);  // ERROR: non-const member function
   t.setSecond(39);  // ERROR: non-const member function

   return 0;
}
