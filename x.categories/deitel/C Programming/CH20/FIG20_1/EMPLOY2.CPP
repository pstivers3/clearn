// EMPLOY2.CPP
// Member function definitions for
// abstract base class Employee.
// Note: No definitions given for pure virtual functions.
#include <iostream.h>
#include <string.h>
#include <assert.h>
#include "employ2.h"

// Constructor dynamically allocates space for the
// first and last name and uses strcpy to copy
// the first and last names into the object.
Employee::Employee(const char *first, const char *last)
{
   firstName = new char[ strlen(first) + 1 ];
   assert(firstName != 0);    // test that new worked
   strcpy(firstName, first);

   lastName = new char[ strlen(last) + 1 ];
   assert(lastName != 0);     // test that new worked
   strcpy(lastName, last);
}

// Destructor deallocates dynamically allocated memory
Employee::~Employee()
{
   delete [] firstName;
   delete [] lastName;
}

// Return a pointer to the first name
const char *Employee::getFirstName() const
{
   // Const prevents caller from modifying private data.
   // Caller should copy returned string before destructor
   // deletes dynamic storage to prevent undefined pointer.

   return firstName;
}

// Return a pointer to the last name
const char *Employee::getLastName() const
{
   // Const prevents caller from modifying private data.
   // Caller should copy returned string before destructor
   // deletes dynamic storage to prevent undefined pointer.

   return lastName;
}

