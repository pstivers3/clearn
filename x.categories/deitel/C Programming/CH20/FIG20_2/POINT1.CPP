// POINT1.CPP
// Member function definitions for class Point
#include <iostream.h>
#include "point1.h"

Point::Point(float a, float b)
{
   x = a;
   y = b;
}

void Point::setPoint(float a, float b)
{
   x = a;
   y = b;
}

ostream &operator<<(ostream &output, const Point &p)
{
   output << '[' << p.x << ", " << p.y << ']';

   return output;   // enables concatenated calls
}