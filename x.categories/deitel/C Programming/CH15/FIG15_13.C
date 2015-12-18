// Using overloaded functions
#include <iostream.h>

int square(int x) { return x * x; }

double square(double y) { return y * y; }

main()
{
   cout << "The square of integer 7 is " 
        << square(7) 
        << "\nThe square of double 7.5 is " 
        << square(7.5) << '\n';    

   return 0;
}

