// FIG19_4.CPP
// Casting base-class pointers to derived class pointers
#include <iostream.h>
#include <iomanip.h>
#include "point.h"
#include "circle.h"

main()
{
   Point *pointPtr, p(3.5, 5.3);
   Circle *circlePtr, c(2.7, 1.2, 8.9);

   cout << "Point p: " << p << "\nCircle c: " << c << endl;

   // Treat a Circle as a Circle (with some casting)
   pointPtr = &c;   // assign address of Circle to pointPtr
   circlePtr = (Circle *) pointPtr;  // cast base to derived
   cout << "\nArea of c (via circlePtr): "
	<< circlePtr->area() << endl;

   // DANGEROUS: Treat a Point as a Circle
   // WARNING: Garbage value returned by getRadius()
   pointPtr = &p;   // assign address of Point to pointPtr
   circlePtr = (Circle *) pointPtr;  // cast base to derived
   cout << "\nRadius of object circlePtr points to: "
	<< circlePtr->getRadius() << endl;

   return 0;
}