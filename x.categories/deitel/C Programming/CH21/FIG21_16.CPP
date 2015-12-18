// fig21_16.cpp
// Using hex, oct, dec and setbase stream manipulators.
#include <iostream.h>
#include <iomanip.h>

main()
{
	int n;

	cout << "Enter a decimal number: ";
	cin >> n;

	cout << n << " in hexadecimal is: "
		  << hex << n << '\n'
		  << dec << n << " in octal is: "
		  << oct << n << '\n'
		  << setbase(10) << n << " in decimal is: "
		  << n << endl;

	return 0;
}

