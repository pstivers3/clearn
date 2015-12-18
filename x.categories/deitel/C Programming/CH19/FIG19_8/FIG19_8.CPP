// FIG19_8.CPP
// Driver for class Circle
#include <iostream.h>
#include "point2.h"
#include "circle2.h"

main()
{
   Circle c(2.5, 3.7, 4.3);

   cout << "X coordinate is " << c.getX()
        << "\nY coordinate is " << c.getY()
	<< "\nRadius is " << c.getRadius();

   c.setRadius(4.25);
   c.setPoint(2, 2);
   cout << "\n\nThe new location and radius of c are\n"
	<< c << "\nArea: " << c.area() << endl;

   Point &pRef = c;
   cout << "\nCircle printed as a Point is: "
	<< pRef << endl;

   return 0;
}