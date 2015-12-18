// FIG20_2.CPP
// Driver for point, circle, cylinder hierarchy
#include <iostream.h>
#include <iomanip.h>
#include "shape.h"
#include "point1.h"
#include "circle1.h"
#include "cylindr1.h"

main()
{
   // create some shape objects
   Point point(7, 11);
   Circle circle(3.5, 22, 8);
   Cylinder cylinder(10, 3.3, 10, 10);

   point.printShapeName();     // static binding
   cout << point << endl;

   circle.printShapeName();    // static binding
   cout << circle << endl;

   cylinder.printShapeName();  // static binding
   cout << cylinder << "\n\n";

   cout << setiosflags(ios::showpoint) << setprecision(2);
   Shape *ptr;                 // create base-class pointer

   // aim base-class pointer at derived-class Point object
   ptr = &point;
   ptr->printShapeName();      // dynamic binding
   cout << "x = " << point.getX() << "; y = " << point.getY()
	<< "\nArea = " << ptr->area()
	<< "\nVolume = " << ptr->volume() << "\n\n";

   ptr = &circle;
   ptr->printShapeName();      // dynamic binding
   cout << "x = " << circle.getX() << "; y =" << circle.getY()
	<< "\nArea = " << ptr->area()
	<< "\nVolume = " << ptr->volume() << "\n\n";

   ptr = &cylinder;
   ptr->printShapeName();      // dynamic binding
   cout << "x = " << cylinder.getX() << "; y = " << cylinder.getY()
	<< "\nArea = " << ptr->area()
	<< "\nVolume = " << ptr->volume() << endl;

   return 0;
}