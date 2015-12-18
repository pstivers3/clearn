// fig21_28.cpp
// Demonstrating the flags member function.

#include <iostream.h>

main()
{
	int i = 1000;
	double d = 0.0947628;

	cout << "The value of the flags variable is: "
		  << cout.flags() << '\n'
		  << "Print int and double in original format:\n"
		  << i << '\t' << d << "\n\n";
	long originalFormat = cout.flags(ios::oct |
												ios::scientific);
	cout << "The value of the flags variable is: "
		  << cout.flags() << '\n'
		  << "Print int and double in a new format\n"
		  << "specified using the flags member function:\n"
		  << i << '\t' << d << "\n\n";
	cout.flags(originalFormat);
	cout << "The value of the flags variable is: "
		  << cout.flags() << '\n'
		  << "Print values in original format again:\n"
		  << i << '\t' << d << endl;

	return 0;
}
