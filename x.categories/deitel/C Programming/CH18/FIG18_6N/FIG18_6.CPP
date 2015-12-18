// FIG18_6.CPP
// Driver for class Date
#include <iostream.h>
#include "date1.h"

main()
{
   Date d1, d2(12, 27, 1992), d3(0, 99, 8045);
   cout << "d1 is " << d1
        << "\nd2 is " << d2
        << "\nd3 is " << d3;

   cout << "\n\nd2 += 7 is " << (d2 += 7) << "\n\n";

   d3.setDate(2, 28, 1992);
   cout << "  d3 is " << d3;
   cout << "\n++d3 is " << ++d3 << "\n\n";

   Date d4(3, 18, 1969);
   cout << "Testing the preincrement operator:\n";
   cout << "  d4 is " << d4;
   cout << "\n++d4 is " << ++d4;
   cout << "\n  d4 is " << d4;
   cout << "\n\nTesting the postincrement operator:\n";
   cout << "  d4 is " << d4;
   cout << "\nd4++ is " << d4++;
   cout << "\n  d4 is " << d4 << endl;
   return 0;
}