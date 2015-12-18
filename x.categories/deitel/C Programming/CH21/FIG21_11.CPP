// fig21_11.cpp
// Stream extraction operator returning
// false on end-of-file.
#include <iostream.h>

main()
{
   int grade, highestGrade = -1;

	cout << "Enter grade (enter end-of-file to end): ";
	while (cin >> grade) {

      if (grade > highestGrade)
         highestGrade = grade;
  
		cout << "Enter grade (enter end-of-file to end): ";
   }

	cout << "\nHighest grade is: " << highestGrade
		  << endl;

	return 0;
}

