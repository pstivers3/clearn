// CIRCLE1.CPP
// Member function definitions for class Circle
#include <iostream.h>
#include <iomanip.h>
#include "circle1.h"

// Constructor for Circle call constructor for Point
Circle::Circle(float r, float a, float b)
   : Point(a, b)  // call base-class constructor
{ radius = r > 0 ? r : 0; }

// Set radius
void Circle::setRadius(float r) { radius = r > 0 ? r : 0; }

// Get radius
float Circle::getRadius() const { return radius; }

// Calculate area of a Circle
float Circle::area() const { return 3.14159 * radius * radius; }

// Output a circle in the form: Center=[x, y]; Radius=#.##
ostream &operator<<(ostream &output, const Circle &c)
{
   output << '[' << c.getX() << ", " << c.getY()
          << "]; Radius=" << setiosflags(ios::showpoint)
          << setprecision(2) << c.radius;

   return output;   // enables concatenated calls
}