// CIRCLE1.H
// Definition of class Circle
#ifndef CIRCLE1_H
#define CIRCLE1_H
#include "point1.h"

class Circle : public Point {
   friend ostream &operator<<(ostream &, const Circle &);
public:
   // default constructor
   Circle(float r = 0.0, float x = 0.0, float y = 0.0);

   void setRadius(float);
   float getRadius() const;
   virtual float area() const;
   virtual void printShapeName() const { cout << "Circle: "; }
private:
   float radius;   // radius of Circle
};

#endif
