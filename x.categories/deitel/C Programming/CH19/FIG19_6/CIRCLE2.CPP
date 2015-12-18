// CIRCLE2.CPP
// Member function definitions for class Circle
#include "circle2.h"

// Constructor for Circle calls constructor for Point
Circle::Circle(float r, float a, float b)
   : Point(a, b)   // call base-class constructor
{
   radius = r;

   cout << "Circle constructor: radius is "
        << radius << " [" << a << ", " << b << ']' << endl;
}

// Destructor for class Circle
Circle::~Circle()
{
   cout << "Circle destructor:  radius is "
        << radius << " [" << x << ", " << y << ']' << endl;
}
