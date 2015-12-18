// Using an inline function to calculate 
// the volume of a cube
#include <iostream.h>

inline float cube(const float s) { return s * s * s; }

main()
{
   cout << "Enter the side length of your cube:  ";

   float side;

   cin >> side;
   cout << "Volume of cube with side " 
        << side << " is " << cube(side) << '\n';

   return 0;
}

