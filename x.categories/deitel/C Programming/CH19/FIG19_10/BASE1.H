// BASE1.H
// Definition of class Base1
#ifndef BASE1_H
#define BASE1_H

class Base1 {
public:
   Base1(int x) { value = x; }
   int getData() const { return value; }
protected:      // accessible to derived classes
   int value;   // inherited by derived class
};

#endif