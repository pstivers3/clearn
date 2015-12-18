// POINT.CPP
// Member functions for class Point
#include <iostream.h>
#include "point.h"

// Constructor for class Point
Point::Point(float a, float b)
{
   x = a;
   y = b;
}

// Set x and y coordinates of Point
void Point::setPoint(float a, float b)
{
   x = a;
   y = b;
}

// Output Point (with overloaded stream insertion operator)
ostream &operator<<(ostream &output, const Point &p)
{
   output << '[' << p.x << ", " << p.y << ']';

   return output;   // enables concatenated calls
}