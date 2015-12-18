// POINT.H
// Definition of class Point
#ifndef POINT_H
#define POINT_H

class Point {
   friend ostream &operator<<(ostream &, const Point &);
public:
   Point(float = 0, float = 0);      // default constructor
   void setPoint(float, float);      // set coordinates
   float getX() const { return x; }  // get x coordinate
   float getY() const { return y; }  // get y coordinate

protected:         // accessible by derived classes
   float x, y;     // x and y coordinates of the Point
};

#endif