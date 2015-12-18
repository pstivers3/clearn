// ARRAY1.H
// Simple class Array (for integers)
#ifndef ARRAY1_H
#define ARRAY1_H

#include <iostream.h>

class Array {
   friend ostream &operator<<(ostream &, const Array &);
   friend istream &operator>>(istream &, Array &);
public:
   Array(int arraySize = 10);           // default constructor
   Array(const Array &);                // copy constructor
   ~Array();                            // destructor
   int getSize() const;                 // return size
   const Array &operator=(const Array &);  // assign arrays
   int operator==(const Array &) const; // compare equal
   int operator!=(const Array &) const; // compare !equal
   int &operator[](int);                // subscript operator
   static int getArrayCount();          // return count of
					// arrays instantiated
private:
   int *ptr; // pointer to first element of array
   int size; // size of the array
   static int arrayCount;  // # of Arrays instantiated
};

#endif