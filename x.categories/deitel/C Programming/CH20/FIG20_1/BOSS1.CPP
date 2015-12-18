// BOSS1.CPP
// Member functions for class Boss
#include <iostream.h>
#include "boss1.h"

// Constructor function for class Boss
Boss::Boss(const char *first, const char *last, float s)
   : Employee(first, last)  // call base-class constructor
{ weeklySalary = s > 0 ? s : 0; }

// Set the Boss's salary
void Boss::setWeeklySalary(float s)
{ weeklySalary = s > 0 ? s : 0; }

// Get the Boss's pay
float Boss::earnings() const { return weeklySalary; }

// Print the Boss's name and pay
void Boss::print() const
{
   cout << "\n             Boss: " << getFirstName()
	<< ' ' << getLastName();
}

