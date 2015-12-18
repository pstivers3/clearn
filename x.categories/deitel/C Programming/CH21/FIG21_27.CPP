// fig21_27.cpp
// Using the ios::uppercase flag

#include <iostream.h>
#include <iomanip.h>

main()
{
	cout << setiosflags(ios::uppercase)
		  << "Printing uppercase letters in scientific\n"
		  << "notation exponents and hexadecimal values:\n"
		  << 4.345e10 << '\n'
		  << hex << 123456789 << endl;

	return 0;
}
