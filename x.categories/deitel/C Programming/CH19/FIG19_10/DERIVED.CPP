// DERIVED.CPP
// Member function definitions for class Derived
#include <iostream.h>
#include "derived.h"

// Constructor for Derived calls constructors for
// class Base1 and class Base2.
Derived::Derived(int i, char c, float f)
   : Base1(i), Base2(c)  // call both base-class constructors
{ real = f; }

// Return the value of real
float Derived::getReal() const { return real; }

// Display all the data members of Derived
ostream &operator<<(ostream &output, const Derived &d)
{
   output << "    Integer: " << d.value
          << "\n  Character: " << d.letter
          << "\nReal number: " << d.real;

   return output;   // enables concatenated calls
}