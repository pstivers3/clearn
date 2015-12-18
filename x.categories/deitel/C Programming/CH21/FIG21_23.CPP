// fig21_23.cpp
// Printing an integer with internal spacing and
// forcing the plus sign.
#include <iostream.h>
#include <iomanip.h>

main()
{
   cout << setiosflags(ios::internal | ios::showpos)
	<< setw(10) << 123 << endl;
   return 0;
}
