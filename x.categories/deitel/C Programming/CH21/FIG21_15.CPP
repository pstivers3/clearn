// fig21_15.cpp
// Unformatted I/O with the read,
// gcount and write member functions.
#include <iostream.h>
const SIZE = 80;

main()
{
	char buffer[SIZE];

	cout << "Enter a sentence:\n";
	cin.read(buffer, 20);
	cout << "\nThe sentence entered was:\n";
	cout.write(buffer, cin.gcount());
	cout << endl;

	return 0;
}
