// POINT2.CPP
// Member functions for class Point
#include <iostream.h>
#include "point2.h"

// Constructor for class Point
Point::Point(float a, float b)
{
   x = a;
   y = b;
}

// Set the x and y coordinates
void Point::setPoint(float a, float b)
{
   x = a;
   y = b;
}

// Output the Point
ostream &operator<<(ostream &output, const Point &p)
{
   output << '[' << p.x << ", " << p.y << ']';

   return output;          // enables concatenation
}