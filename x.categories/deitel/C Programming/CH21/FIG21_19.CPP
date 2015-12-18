// fig21_19.cpp
// Testing user-defined, nonparameterized manipulators
#include <iostream.h>

// bell manipulator (using escape sequence \a)
ostream& bell(ostream& output)
{
	return output << '\a';
}

// ret manipulator (using escape sequence \r)
ostream& ret(ostream& output)
{
	return output << '\r';
}

// tab manipulator (using escape sequence \t)
ostream& tab(ostream& output)
{
	return output << '\t';
}

// endLine manipulator (using escape sequence \n
// and the flush member function)
ostream& endLine(ostream& output)
{
	return output << '\n' << flush;
}

main()
{
	cout << "Testing the tab manipulator:\n"
		  << 'a' << tab << 'b' << tab << 'c' << endLine
		  << "Testing the ret and bell manipulators:\n"
		  << "..........";

	for (int i = 1; i <= 100; i++)
		cout << bell;

	cout << ret << "-----" << endLine;

	return 0;
}