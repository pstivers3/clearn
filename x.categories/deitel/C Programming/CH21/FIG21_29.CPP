// fig21_29.cpp
// Testing error states.

#include <iostream.h>

main()
{
	int x;

	cout << "Before a bad input operation:\n"
		  << "cin.rdstate(): " << cin.rdstate()
		  << "\n    cin.eof(): " << cin.eof()
		  << "\n   cin.fail(): " << cin.fail()
		  << "\n    cin.bad(): " << cin.bad()
		  << "\n   cin.good(): " << cin.good()
		  << "\n\nExpects an integer, but enter a character: ";
	cin >> x;
	cout << "\nAfter a bad input operation:\n"
		  << "cin.rdstate(): " << cin.rdstate()
		  << "\n    cin.eof(): " << cin.eof()
		  << "\n   cin.fail(): " << cin.fail()
		  << "\n    cin.bad(): " << cin.bad()
		  << "\n   cin.good(): " << cin.good() << "\n\n";

	cin.clear();
	cout << "After cin.clear()\n"
		  << "cin.fail(): " << cin.fail() << endl;

	return 0;
}
