// fig21_12.cpp
// Using member functions get, put, and eof.

#include <iostream.h>

main()
{
	int c;

	cout << "Before input cin.eof() is "
		  << cin.eof() << '\n'
		  << "Enter a sentence followed by end-of-file:\n";

	while ((c = cin.get()) != EOF)
		cout.put(c);

	cout << "\nAfter input cin.eof() is "
		  << cin.eof() << endl;

	return 0;
}
