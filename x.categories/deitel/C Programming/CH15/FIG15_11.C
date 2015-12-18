// Using default arguments
#include <iostream.h>

// Calculate the volume of a box 
inline int boxVolume(int length = 1, int width = 1, 
                     int height = 1)
   { return length * width * height; }

main()
{
   cout << "The default box volume is: "
        << boxVolume()
        << "\n\nThe volume of a box with length 10,\n"
        << "width 1 and height 1 is: "
        << boxVolume(10)
        << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 1 is: "
        << boxVolume(10, 5)
        << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 2 is: "
        << boxVolume(10, 5, 2)
        << '\n';

   return 0;
}

