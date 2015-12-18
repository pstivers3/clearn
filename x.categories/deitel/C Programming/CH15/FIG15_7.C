// Comparing call by value, call by reference with
// pointers, and call by reference with references
#include <iostream.h>

int squareByValue(int);
void squareByPointer(int *);
void squareByReference(int &);

main()
{
   int x = 2, y = 3, z = 4;

   cout << "x = " << x << " before squareByValue\n"
        << "Value returned by squareByValue: "
        << squareByValue(x)
        << "\nx = " << x << " after squareByValue\n\n";

   cout << "y = " << y << " before squareByPointer\n";
   squareByPointer(&y);
   cout << "y = " << y << " after squareByPointer\n\n";
   
   cout << "z = " << z << " before squareByReference\n";
   squareByReference(z);
   cout << "z = " << z << " after squareByReference\n";

   return 0;
}

int squareByValue(int a)
{
   return a *= a;   // caller's argument not modified
}

void squareByPointer(int *bPtr)
{
   *bPtr *= *bPtr;  // caller's argument modified
}

void squareByReference(int &cRef)
{
   cRef *= cRef;    // caller's argument modified
}

