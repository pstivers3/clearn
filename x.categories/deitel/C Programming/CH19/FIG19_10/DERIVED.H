// DERIVED.H
// Definition of class Derived which inherits
// multiple base classes (Base1 and Base2).
#ifndef DERIVED_H
#define DERIVED_H

#include "base1.h"
#include "base2.h"

// multiple inheritance
class Derived : public Base1, public Base2 {
   friend ostream &operator<<(ostream &, const Derived &);
public:
   Derived(int, char, float);
   float getReal() const;
private:
   float real;   // derived class's private data
};

#endif