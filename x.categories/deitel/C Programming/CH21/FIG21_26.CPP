// fig21_26.cpp
// Displaying floating point values in system default,
// scientific, and fixed formats.

#include <iostream.h>

main()
{
	double x = .001234567, y = 1.946e9;

	cout << "Displayed in default format:\n"
		  << x << '\t' << y << '\n';
	cout.setf(ios::scientific, ios::floatfield);
	cout << "Displayed in scientific format:\n"
		  << x << '\t' << y << '\n';
	cout.unsetf(ios::scientific);
	cout << "Displayed in default format after unsetf:\n"
		  << x << '\t' << y << '\n';
	cout.setf(ios::fixed, ios::floatfield);
	cout << "Displayed in fixed format:\n"
		  << x << '\t' << y << endl;

	return 0;
}
