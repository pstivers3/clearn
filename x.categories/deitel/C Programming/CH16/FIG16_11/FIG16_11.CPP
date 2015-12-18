// FIG5_11.CPP
// Demonstrating a public member function that
// returns a reference to a private data member.
// Time class has been trimmed for this example.
#include <iostream.h>
#include "time4.h"

main()
{
   Time t;
   int &hourRef = t.badSetHour(20);

   cout << "Hour before modification: "
        << hourRef << '\n';
   hourRef = 30;  // modification with invalid value
   cout << "Hour after modification: "
        << hourRef << '\n';

   // Dangerous: Function call that returns
   // a reference can be used as an lvalue.
   t.badSetHour(12) = 74;
   cout << "\n*********************************\n"
        << "BAD PROGRAMMING PRACTICE!!!!!!!!!\n"
        << "badSetHour as an lvalue, Hour: "
        << t.getHour()
        << "\n*********************************\n";

   return 0;
}
