// FIG17_4.CPP
// Demonstrating an object with a member object.
#include <iostream.h>
#include "emply1.h"

main()
{
   Employee e("Bob", "Jones", 7, 24, 49, 3, 12, 88);

   cout << endl;
   e.print();

   cout << "\nTest Date constructor with invalid values:\n";
   Date d(14, 35, 94);  // invalid Date values

   return 0;
}