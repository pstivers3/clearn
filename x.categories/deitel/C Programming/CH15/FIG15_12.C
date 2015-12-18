// Using the unary scope resolution operator
#include <iostream.h>

float value = 1.2345;

main()
{
   int value = 7;

   cout << "Local value = " << value
        << "\nGlobal value = " << ::value << '\n';

   return 0;
}

