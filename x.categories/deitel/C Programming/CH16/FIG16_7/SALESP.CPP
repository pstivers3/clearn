// SALESP.CPP
// Member functions for class SalesPerson
#include <iostream.h>
#include <iomanip.h>
#include "salesp.h"

// Constructor function initializes array
SalesPerson::SalesPerson()
{
   for (int i = 0; i <= 12; i++)
      sales[i] = 0.0;
}

// Function to set the 12 monthly sales figures
void SalesPerson::setSales()
{
   for (int i = 1; i <= 12; i++) {
      cout << "Enter sales amount for month "
	   << i << ": ";
      cin >> sales[i];
   }
}

// Private utility function to total annual sales
double SalesPerson::totalAnnualSales()
{
   double total = 0.0;

   for (int i = 1; i <= 12; i++)
      total += sales[i];

   return total;
}

// Print the total annual sales
void SalesPerson::printAnnualSales()
{
   cout << setprecision(2)
        << setiosflags(ios::fixed | ios::showpoint)
        << "\nThe total annual sales are: $"
        << totalAnnualSales() << endl;
}
