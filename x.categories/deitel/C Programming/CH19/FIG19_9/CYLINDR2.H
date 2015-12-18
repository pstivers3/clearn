// CYLINDR2.H
// Definition of class Cylinder
#ifndef CYLINDR2_H
#define CYLINDR2_H
#include "circle2.h"

class Cylinder : public Circle {
   friend ostream& operator<<(ostream&, const Cylinder&);
public:
   // default constructor
   Cylinder(float h = 0.0, float r = 0.0,
            float x = 0.0, float y = 0.0);
   void setHeight(float);   // set height
   float getHeight() const; // return height
   float area() const;      // calculate and return area
   float volume() const;    // calculate and return volume
protected:
   float height;            // height of the Cylinder
};

#endif