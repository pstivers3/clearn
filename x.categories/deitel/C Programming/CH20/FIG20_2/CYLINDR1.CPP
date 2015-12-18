// CYLINDR1.CPP
// Member and friend function definitions for class Cylinder
#include <iostream.h>
#include <iomanip.h>
#include "cylindr1.h"

Cylinder::Cylinder(float h, float r, float x, float y)
   : Circle(r, x, y)  // call base-class constructor
{ height = h > 0 ? h : 0; }

void Cylinder::setHeight(float h)
   { height = h > 0 ? h : 0; }

float Cylinder::area() const
{
   // surface area of Cylinder
   return 2 * Circle::area() +
          2 * 3.14159 * Circle::getRadius() * height;
}

float Cylinder::volume() const
{
   float r = Circle::getRadius();
   return 3.14159 * r * r * height;
}

ostream &operator<<(ostream &output, const Cylinder& c)
{
   output << '[' << c.getX() << ", " << c.getY()
          << "]; Radius=" << setiosflags(ios::showpoint)
          << setprecision(2) << c.getRadius()
          << "; Height=" << c.height;

   return output;   // enables concatenated calls
}