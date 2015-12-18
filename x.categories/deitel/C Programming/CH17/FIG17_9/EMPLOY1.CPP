// EMPLOY1.CPP
// Member functions definitions for class Employee
#include <iostream.h>
#include <string.h>
#include <assert.h>
#include "employ1.h"

// Initialize the static data member
int Employee::count = 0;

// Define the static member function that
// returns the number of employee objects instantiated.
int Employee::getCount() { return count; }

// Constructor dunamically allocates space for the
// first and last name and uses strcpy to copy
// the first and last names into the object
Employee::Employee(const char *first, const char *last)
{
   firstName = new char[ strlen(first) + 1 ];
   assert(firstName != 0);   // ensure memory allocated
   strcpy(firstName, first);

   lastName = new char[ strlen(last) + 1 ];
   assert(lastName != 0);    // ensure memory allocated
   strcpy(lastName, last);

   ++count;  // increment static count of employees
   cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called.\n";
}

// Destructor deallocates dynamically allocated memory
Employee::~Employee()
{
   cout << "~Employee() called for " << firstName
        << ' ' << lastName << endl;
   delete firstName;  // recapture memory
   delete lastName;   // recapture memory
   --count;  // decrement static count of employees
}

// Return first name of employee
char *Employee::getFirstName() const
{
   char *tempPtr = new char[strlen(firstName) + 1];
   assert(tempPtr != 0);   // ensure memory allocated
   strcpy(tempPtr, firstName);
   return tempPtr;
}

// Return last name of employee
char *Employee::getLastName() const
{
   char *tempPtr = new char[strlen(lastName) + 1];
   assert(tempPtr != 0);   // ensure memory allocated
   strcpy(tempPtr, lastName);
   return tempPtr;
}


