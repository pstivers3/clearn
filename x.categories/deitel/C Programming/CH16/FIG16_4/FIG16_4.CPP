// FIG5_4.CPP
// Demonstrating the class member access operators . and ->
//
// Caution: In future examples we will use private data.
#include <iostream.h>

// Simple class Count
class Count {
public:
   int x;
   void print() { cout << x << '\n'; }
};

main()
{
   Count counter,                // create counter object
         *counterPtr = &counter, // pointer to counter
         &counterRef = counter;  // reference to counter

   cout << "Assign 7 to x and print using the object's name: ";
   counter.x = 7;       // assign 7 to data member x
   counter.print();     // call member function print

   cout << "Assign 8 to x and print using a reference: ";
   counterRef.x = 8;    // assign 8 to data member x
   counterRef.print();  // call member function print

   cout << "Assign 10 to x and print using a pointer: ";
   counterPtr->x = 10;  // assign 10 to data member x
   counterPtr->print(); // call member function print

   return 0;
}