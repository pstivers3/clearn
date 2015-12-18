// fig21_08.cpp
// Printing the address stored in a char* variable

#include <iostream.h>

main()
{
	char *string = "test";

	cout << "Value of string is: " << string
		  << "\nValue of (void *)string is: "
		  << (void *)string << endl;

	return 0;
}
