// CIRCLE.CPP
// Member function definitions for class Circle
#include "circle.h"

// Constructor for Circle calls constructor for Point
// with a member initializer then initializes radius.
Circle::Circle(float r, float a, float b)
   : Point(a, b)       // call base-class constructor
{ radius = r; }

// Set radius of Circle
void Circle::setRadius(float r) { radius = r; }

// Get radius of Circle
float Circle::getRadius() const { return radius; }

// Calculate area of Circle
float Circle::area() const
{ return 3.14159 * radius * radius; }

// Output a Circle in the form:
// Center = [x, y]; Radius = #.##
ostream &operator<<(ostream &output, const Circle &c)
{
   output << "Center = [" << c.x << ", " << c.y
          << "]; Radius = " << setiosflags(ios::showpoint)
	  << setprecision(2) << c.radius;

   return output;
}