// CIRCLE.H
// Definition of class Circle
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream.h>
#include <iomanip.h>
#include "point.h"

class Circle : public Point {  // Circle inherits from Point
   friend ostream &operator<<(ostream &, const Circle &);
public:
   // default constructor
   Circle(float r = 0.0, float x = 0, float y = 0);

   void setRadius(float);      // set radius
   float getRadius() const;    // return radius
   float area() const;         // calculate area
protected:
   float radius;
};

#endif
