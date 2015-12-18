// fig21_10.cpp
// Revealing a precedence problem.
// Need parentheses around the conditional expression.
#include <iostream.h>

main()
{
	int x, y;

	cout << "Enter two integers: ";
	cin >> x >> y;
	cout << x << (x == y ? " is" : " is not")
		  << " equal to " << y << endl;

   return 0;
}

