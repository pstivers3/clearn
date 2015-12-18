// fig21_14.cpp
// Character input with member function getline

#include <iostream.h>
const int SIZE = 80;

main()
{
	char buffer[SIZE];

	cout << "Enter a sentence:\n";
	cin.getline(buffer, SIZE);
	cout << "\nThe sentence entered is:\n"
		  << buffer << endl;
	return 0;
}
