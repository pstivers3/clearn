// BASE2.H
// Definition of class Base2
#ifndef BASE2_H
#define BASE2_H

class Base2 {
public:
   Base2(char c) { letter = c; }
   char getData() const { return letter; }
protected:        // accessible to derived classes
   char letter;   // inherited by derived class
};

#endif