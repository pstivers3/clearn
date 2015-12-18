// fig21_24.cpp
// Using the fill member function and the setfill
// manipulator to change the padding character for
// fields larger than the values being printed.
#include <iostream.h>
#include <iomanip.h>

main()
{
	int x = 10000;

	cout << x
		  << " printed as int right and left justified\n"
		  << "and as hex with internal justification.\n"
		  << "Using the default pad character (space):\n";
	cout.setf(ios::showbase);
	cout << setw(10) << x << '\n';
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(10) << x << '\n';
	cout.setf(ios::internal, ios::adjustfield);
	cout << setw(10) << hex << x << "\n\n";

	cout << "Using various padding characters:\n";
	cout.setf(ios::right, ios::adjustfield);
	cout.fill('*');
	cout << setw(10) << dec << x << '\n';
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(10) << setfill('%') << x << '\n';
	cout.setf(ios::internal, ios::adjustfield);
	cout << setw(10) << setfill('^') << hex
		  << x << endl;

	return 0;
}
