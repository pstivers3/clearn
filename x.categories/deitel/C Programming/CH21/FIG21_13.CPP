// fig21_13.cpp
// Contrasting input of a string with cin and cin.get.

#include <iostream.h>
const int SIZE = 80;

main()
{
	char buffer1[SIZE], buffer2[SIZE];

	cout << "Enter a sentence:\n";
	cin >> buffer1;
	cout << "\nThe string read with cin was:\n"
		  << buffer1 << "\n\n";
	cin.get(buffer2, SIZE);
	cout << "The string read with cin.get was:\n"
		  << buffer2 << endl;

	return 0;
}
