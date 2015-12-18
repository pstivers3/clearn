// EMPLY1.H
// Declaration of the Employee class.
// Member functions defined in EMPLY1.CPP

#ifndef EMPLY1_H
#define EMPLY1_H

#include "date1.h"

class Employee {
public:
   Employee(char *, char *, int, int, int, int, int, int);
   void print() const;
private:
   char lastName[25];
   char firstName[25];
   Date birthDate;
   Date hireDate;
};

#endif

