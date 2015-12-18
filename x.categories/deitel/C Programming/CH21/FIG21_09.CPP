// fig21_09.cpp
// Calculating the sum of two integers
// input from the keyboard with cin
// and the stream extraction operator.
#include <iostream.h>

main()
{
	int x, y;

	cout << "Enter two integers: ";
	cin >> x >> y;
	cout << "Sum of " << x << " and " << y << " is: "
		  << x + y << endl;

	return 0;
}

