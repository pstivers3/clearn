// FIG19_7.CPP
// Driver for class Point
#include <iostream.h>
#include "point2.h"

main()
{
   Point p(7.2, 11.5);   // instantiate Point object p

   // protected data of Point inaccessible to main
   cout << "X coordinate is " << p.getX()
        << "\nY coordinate is " << p.getY();

   p.setPoint(10, 10);
   cout << "\n\nThe new location of p is " << p << endl;

   return 0;
}