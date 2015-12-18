// FIG18_8.CPP
// Test driver for HugeInt class
#include <iostream.h>
#include "hugeint1.h"

main()
{
   HugeInt n1(7654321), n2(7891234),
           n3("99999999999999999999999999999"),
           n4("1"), n5;

   cout << "n1 is " << n1 << "\nn2 is " << n2
        << "\nn3 is " << n3 << "\nn4 is " << n4
        << "\nn5 is " << n5 << "\n\n";

   n5 = n1 + n2;
   cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

   cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

   n5 = n1 + 9;
   cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

   n5 = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";

   return 0;
}