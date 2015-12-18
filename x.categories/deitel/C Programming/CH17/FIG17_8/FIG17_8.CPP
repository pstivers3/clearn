// FIG17_8.CPP
// Chaining member function calls together
// with the this pointer
#include <iostream.h>
#include "time6.h"

main()
{
   Time t;

   t.setHour(18).setMinute(30).setSecond(22);
   cout << "Military time: ";
   t.printMilitary();
   cout << "\nStandard time: ";
   t.printStandard();

   cout << "\n\nNew standard time: ";
   t.setTime(20, 20, 20).printStandard();
   cout << endl;

   return 0;
}
