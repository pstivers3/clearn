// CIRCLE2.CPP
// Member function definitions for class Circle
#include <iostream.h>
#include <iomanip.h>
#include "circle2.h"

// Constructor for Circle calls constructor for Point
// with a member initializer and initializes radius.
Circle::Circle(float r, float a, float b)
   : Point(a, b)       // call base-class constructor
{ radius = r; }

// Set radius
void Circle::setRadius(float r) { radius = r; }

// Get radius
float Circle::getRadius() const { return radius; }

// Calculate area of Circle
float Circle::area() const
   { return 3.14159 * radius * radius; }

// Output a circle in the form:
// Center = [x, y]; Radius = #.##
ostream &operator<<(ostream &output, const Circle &c)
{
   output << "Center = [" << c.x << ", " << c.y
          << "]; Radius = " << setiosflags(ios::showpoint)
	  << setprecision(2) << c.radius;

   return output;   // enables concatenated calls
}