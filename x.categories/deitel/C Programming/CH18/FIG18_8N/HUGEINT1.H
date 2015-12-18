// HUGEINT1.H
// Definition of the HugeInt class
#ifndef HUGEINT1_H
#define HUGEINT1_H

#include <iostream.h>

class HugeInt {
   friend ostream& operator<<(ostream&, HugeInt&);
public:
   HugeInt(long = 0);           // conversion constructor
   HugeInt(const char *);       // conversion constructor
   HugeInt operator+(HugeInt&); // addition
private:
   short integer[30];
};

#endif