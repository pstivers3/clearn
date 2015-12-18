// POINT2.CPP
// Member functions for class Point
#include <iostream.h>
#include "point2.h"

// Constructor for class Point
Point::Point(float a, float b)
{
   x = a;
   y = b;

   cout << "Point  constructor: "
	<< '[' << x << ", " << y << ']' << endl;
}

// Destructor for class Point
Point::~Point()
{
   cout << "Point  destructor:  "
        << '[' << x << ", " << y << ']' << endl;
}
