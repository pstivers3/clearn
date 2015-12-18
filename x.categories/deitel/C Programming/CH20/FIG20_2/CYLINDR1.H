// CYLINDER.H
// Definition of class Cylinder
#ifndef CYLINDER_H
#define CYLINDER_H
#include "circle1.h"

class Cylinder : public Circle {
   friend ostream &operator<<(ostream &, const Cylinder &);
public:
   // default constructor
   Cylinder(float h = 0.0, float r = 0.0,
	    float x = 0.0, float y = 0.0);

   void setHeight(float);
   virtual float area() const;
   virtual float volume() const;
   virtual void printShapeName() const { cout << "Cylinder: "; }
private:
   float height;   // height of Cylinder
};

#endif