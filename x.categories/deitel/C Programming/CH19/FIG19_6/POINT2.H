// POINT2.H
// Definition of class Point
#ifndef POINT2_H
#define POINT2_H

class Point {
public:
   Point(float = 0.0, float = 0.0);  // default constructor
   ~Point();    // destructor
protected:      // accessible by derived classes
   float x, y;  // x and y coordinates of Point
};

#endif