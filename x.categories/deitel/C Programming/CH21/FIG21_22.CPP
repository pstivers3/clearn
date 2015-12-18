// fig21_22.cpp
// Left justification and right justification.
#include <iostream.h>
#include <iomanip.h>

main()
{
	int x = 12345;

	cout << "Default is right justified:\n"
		  << setw(10) << x
		  << "\n\nUSING MEMBER FUNCTIONS\n"
		  << "Use setf to set ios::left:\n" << setw(10);
	cout.setf(ios::left, ios::adjustfield);
	cout << x << "\nUse unsetf to restore default:\n";
	cout.unsetf(ios::left);
	cout << setw(10) << x
		  << "\n\nUSING PARAMETERIZED STREAM MANIPULATORS"
		  << "\nUse setiosflags to set ios::left:\n"
		  << setw(10) << setiosflags(ios::left) << x
		  << "\nUse resetiosflags to restore default:\n"
		  << setw(10) << resetiosflags(ios::left) << x << endl;

	return 0;
}
