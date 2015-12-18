// CIRCLE2.H
// Definition of class Circle
#ifndef CIRCLE2_H
#define CIRCLE2_H

#include "point2.h"

class Circle : public Point {
   friend ostream &operator<<(ostream &, const Circle &);
public:
   // default constructor
   Circle(float r = 0.0, float x = 0, float y = 0);
   void setRadius(float);      // set radius
   float getRadius() const;    // return radius
   float area() const;         // calculate area
protected:         // accessible to derived classes
   float radius;   // radius of the Circle
};

#endif
