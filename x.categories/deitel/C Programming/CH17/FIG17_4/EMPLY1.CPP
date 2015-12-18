// EMPLY1.CPP
// Member function definitions for Employee class.
#include <iostream.h>
#include <string.h>
#include "emply1.h"
#include "date1.h"

Employee::Employee(char *fname, char *lname,
                   int bmonth, int bday, int byear,
                   int hmonth, int hday, int hyear)
   : birthDate(bmonth, bday, byear),
     hireDate(hmonth, hday, hyear)
{
   strncpy(firstName, fname, 24);
   firstName[24] = '\0';
   strncpy(lastName, lname, 24);
   lastName[24] = '\0';
   cout << "Employee object constructor: "
        << firstName << ' ' << lastName << endl;
}

void Employee::print() const
{
   cout << lastName << ", " << firstName << "\nHired: ";
   hireDate.print();
   cout << "  Birthday: ";
   birthDate.print();
   cout << endl;
}