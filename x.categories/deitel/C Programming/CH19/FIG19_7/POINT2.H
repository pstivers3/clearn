// POINT2.H
// Definition of class Point
#ifndef POINT2_H
#define POINT2_H

class Point {
   friend ostream &operator<<(ostream &, const Point &);
public:
   Point(float = 0, float = 0);      // default constructor
   void setPoint(float, float);      // set coordinates
   float getX() const { return x; }  // get x coordinate
   float getY() const { return y; }  // get y coordinate
protected:        // accessible to derived classes
   float x, y;    // coordinates of the point
};

#endif