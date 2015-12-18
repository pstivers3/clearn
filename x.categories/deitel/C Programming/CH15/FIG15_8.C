// References must be initialized
#include <iostream.h>

main()
{
   int x = 3, &y = x;  // y is now an alias for x

   cout << "x = " << x << '\n'
        << "y = " << y << '\n';
   y = 7;
   cout << "x = " << x << '\n'
        << "y = " << y << '\n';

   return 0;
}

