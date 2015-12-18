// FIG19_6.CPP
// Demonstrate when base-class and derived-class
// constructors and destructors are called.
#include <iostream.h>
#include "point2.h"
#include "circle2.h"

main()
{
   // Show constructor and destructor calls for Point
   {
      Point p(1.1, 2.2);
   }

   cout << endl;
   Circle circle1(4.5, 7.2, 2.9);
   cout << endl;
   Circle circle2(10, 5, 5);
   cout << endl;
   return 0;
}