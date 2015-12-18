// CIRCLE2.H
// Definition of class Circle
#ifndef CIRCLE3_H
#define CIRCLE3_H

#include "point2.h"
#include <iomanip.h>

class Circle : public Point {
public:
   // default constructor
   Circle(float r = 0.0, float x = 0, float y = 0);
   ~Circle();      // destructor
private:
   float radius;   // radius of Circle
};

#endif
