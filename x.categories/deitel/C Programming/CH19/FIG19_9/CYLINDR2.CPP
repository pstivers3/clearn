// CYLINDR2.CPP
// Member and friend function definitions for class Cylinder
#include <iostream.h>
#include <iomanip.h>
#include "cylindr2.h"

// Cylinder constructor calls Circle constructor
Cylinder::Cylinder(float h, float r, float x, float y)
   : Circle(r, x, y)   // call base-class constructor
{ height = h; }

// Set height of Cylinder
void Cylinder::setHeight(float h) { height = h; }

// Get height of Cylinder
float Cylinder::getHeight() const { return height; }

// Calculate area of Cylinder (i.e., surface area)
float Cylinder::area() const
{
   return 2 * Circle::area() +
          2 * 3.14159 * radius * height;
}

// Calculate volume of Cylinder
float Cylinder::volume() const
   { return Circle::area() * height; }

// Output Cylinder dimensions
ostream& operator<<(ostream &output, const Cylinder& c)
{
   output << "Center = [" << c.x << ", " << c.y
          << "]; Radius = " << setiosflags(ios::showpoint)
          << setprecision(2) << c.radius
          << "; Height = " << c.height;

   return output;   // enables concatenated calls
}