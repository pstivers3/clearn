// ARRAY1.CPP
// Member function definitions for class Array
#include <iostream.h>
#include <stdlib.h>
#include <assert.h>
#include "array1.h"

// Initialize static data member at file scope
int Array::arrayCount = 0;   // no objects yet

// Return the number of Array objects instantiated
int Array::getArrayCount() { return arrayCount; }

// Default constructor for class Array
Array::Array(int arraySize)
{
   ++arrayCount;             // count one more object
   size = arraySize;         // default size is 10
   ptr = new int[size];      // create space for array
   assert(ptr != 0);  // terminate if memory not allocated

   for (int i = 0; i < size; i++)
      ptr[i] = 0;            // initialize array
}

// Copy constructor for class Array
Array::Array(const Array &init)
{
   ++arrayCount;             // count one more object
   size = init.size;         // size this object
   ptr = new int[size];      // create space for array
   assert(ptr != 0);  // terminate if memory not allocated

   for (int i = 0; i < size; i++)
      ptr[i] = init.ptr[i];  // copy init into object
}

// Destructor for class Array
Array::~Array()
{
   --arrayCount;             // one fewer objects
   delete [] ptr;            // reclaim space for array
}

// Get the size of the array
int Array::getSize() const { return size; }

// Overloaded subscript operator
int &Array::operator[](int subscript)
{
   // check for subscript out of range error
   assert(0 <= subscript && subscript < size);

   return ptr[subscript];   // reference return creates lvalue
}

// Determine if two arrays are equal and
// return 1 if true, 0 if false.
int Array::operator==(const Array &right) const
{
   if (size != right.size)
      return 0;    // arrays of different sizes

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
	 return 0; // arrays are not equal

   return 1;       // arrays are equal
}

// Determine if two arrays are not equal and
// return 1 if true, 0 if false.
int Array::operator!=(const Array &right) const
{
   if (size != right.size)
      return 1;    // arrays of different sizes

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
	 return 1; // arrays are not equal

   return 0;       // arrays are equal
}

// Overloaded assignment operator
const Array &Array::operator=(const Array &right)
{
   if (&right != this) {    // check for self-assignment
      delete [] ptr;        // reclaim space
      size = right.size;    // resize this object
      ptr = new int[size];  // create space for array copy
      assert(ptr != 0);     // terminate if memory not allocated

      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];  // copy array into object
   }

   return *this;   // enables x = y = z;
}

// Overloaded input operator for class Array;
// inputs values for entire array.
istream &operator>>(istream &input, const Array &a)
{
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];

   return input;   // enables cin >> x >> y;
}

// Overloaded output operator for class Array
ostream &operator<<(ostream &output, Array &a)
{
   for (int i = 0; i < a.size; i++) {
      output << a.ptr[i] << ' ';

      if ((i + 1) % 10 == 0)
         output << endl;
   }

   if (i % 10 != 0)
      output << endl;

   return output;   // enables cout << x << y;
}

