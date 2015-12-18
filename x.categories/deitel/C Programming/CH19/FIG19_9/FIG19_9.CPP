// FIG19_9.CPP
// Driver for class Cylinder
#include <iostream.h>
#include <iomanip.h>
#include "point2.h"
#include "circle2.h"
#include "cylindr2.h"

main()
{
   // create Cylinder object
   Cylinder cyl(5.7, 2.5, 1.2, 2.3);

   // use get functions to display the Cylinder
   cout << "X coordinate is " << cyl.getX()
	<< "\nYcoordinate is " << cyl.getY()
	<< "\nRadius is " << cyl.getRadius()
	<< "\nHeight is " << cyl.getHeight();

   // use set functions to change the Cylinder's attributes
   cyl.setHeight(10);
   cyl.setRadius(4.25);
   cyl.setPoint(2, 2);
   cout << "\n\nThe new location, radius, "
        << "and height of cyl are:\n" << cyl
        << "\nArea: " << cyl.area()
        << "   Volume: " << cyl.volume();

   // display the Cylinder as a Point
   Point &pRef = cyl;   // pRef "thinks" it is a Point
   cout << "\n\nCylinder printed as a Point is: " << pRef;

   // display the Cylinder as a Circle
   Circle &cRef = cyl;  // cRef "thinks" it is a Circle
   cout << "\n\nCylinder printed as a Circle is:\n" << cRef
	<< "\nArea: " << cRef.area() << endl;

   return 0;
}