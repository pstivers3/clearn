// fig21_17.cpp
// Controlling precision of floating point values
#include <iostream.h>
#include <iomanip.h>
#include <math.h>

main()
{
	double root2 = sqrt(2.0);

	cout << "Square root of 2 with precisions 0-9.\n"
		  << "Precision set by the "
		  << "precision member function:\n";

	for (int places = 0; places <= 9; places++) {
		cout.precision(places);
		cout << root2 << endl;
	}

	cout << "\nPrecision set by the "
		  << "setprecision manipulator:\n";

	for (places = 0; places <= 9; places++)
		cout << setprecision(places) << root2 << endl;

	return 0;
}

