// fig21_18.cpp
// Demonstrating the width member function

#include <iostream.h>

main()
{
	int w = 4;
	char string[10];

	cout << "Enter a sentence:\n";
	cin.width(5);

	while (cin >> string) {
		cout.width(w++);
		cout << string << '\n';
		cin.width(5);
	}

	return 0;
}
