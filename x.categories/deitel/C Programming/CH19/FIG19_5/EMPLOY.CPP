// EMPLOY.CPP
// Member functions definitions for class Employee
#include <string.h>
#include <iostream.h>
#include <assert.h>
#include "employ.h"

// Constructor dynamically allocates space for the
// first and last name and uses strcpy to copy
// the first and last names into the object.
Employee::Employee(const char *first, const char *last)
{
   firstName = new char[ strlen(first) + 1 ];
   assert(firstName != 0);  // terminate if memory not allocated
   strcpy(firstName, first);

   lastName = new char[ strlen(last) + 1 ];
   assert(lastName != 0);   // terminate if memory not allocated
   strcpy(lastName, last);
}

// Output employee name
void Employee::print() const
{ cout << firstName << ' ' << lastName; }

// Destructor deallocates dynamically allocated memory
Employee::~Employee()
{
   delete [] firstName;   // reclaim dynamic memory
   delete [] lastName;    // reclaim dynamic memory
}

