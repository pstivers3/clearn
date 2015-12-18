// fig21_25.cpp
// Using the ios::showbase flag

#include <iostream.h>
#include <iomanip.h>

main()
{
	int x = 100;

	cout << setiosflags(ios::showbase)
		  << "Printing integers preceded by their base:\n"
		  << x << '\n'
		  << oct << x << '\n'
		  << hex << x << endl;

	return 0;
}
