// FIG19_5.CPP
// Redefining a base class member function in a
// derived class.
#include <iostream.h>
#include "hourly.h"

main()
{
   HourlyWorker h("Bob", "Smith", 40.0, 7.50);
   h.print();
   return 0;
}