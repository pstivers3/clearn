// fig21_21.cpp
// Controlling the printing of trailing
// zeros and decimal points when using
// floating point values with float values.

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

main()
{	   
	cout << "cout prints 9.9900 as: " << 9.9900
		  << "\ncout prints 9.9000 as: " << 9.9000
		  << "\ncout prints 9.0000 as: " << 9.0000
		  << "\n\nAfter setting the ios::showpoint flag\n";
	cout.setf(ios::showpoint);
 
	cout << "cout prints 9.9900 as: " << 9.9900
		  << "\ncout prints 9.9000 as: " << 9.9000
		  << "\ncout prints 9.0000 as: " << 9.0000 << endl;
   
   return 0;
}

