// FIG17_9.CPP
// Driver to test the employee class
#include <iostream.h>
#include "employ1.h"

main()
{
   cout << "Number of employees before instantiation is "
        << Employee::getCount() << endl;   // use class name

   Employee *e1Ptr = new Employee("Susan", "Baker");
   Employee *e2Ptr = new Employee("Robert", "Jones");

   cout << "Number of employees after instantiation is "
        << e1Ptr->getCount() << endl;

   cout << "\nEmployee 1: "
        << e1Ptr->getFirstName()
        << " " << e1Ptr->getLastName()
        << "\nEmployee 2: "
        << e2Ptr->getFirstName()
        << " " << e2Ptr->getLastName() << "\n\n";

   delete e1Ptr;   // recapture memory
   delete e2Ptr;   // recapture memory

   cout << "Number of employees after deletion is "
        << Employee::getCount() << endl;

   return 0;
}