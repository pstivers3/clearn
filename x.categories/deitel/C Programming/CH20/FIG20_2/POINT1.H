// POINT1.H
// Definition of class Point
#ifndef POINT1_H
#define POINT1_H
#include <iostream.h>
#include "shape.h"

class Point : public Shape {
   friend ostream &operator<<(ostream &, const Point &);
public:
   Point(float = 0, float = 0);  // default constructor
   void setPoint(float, float);
   float getX() const { return x; }
   float getY() const { return y; }
   virtual void printShapeName() const { cout << "Point: "; }
private:
   float x, y;   // x and y coordinates of Point
};

#endif                                          