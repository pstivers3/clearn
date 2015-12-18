// SALESP.H
// SalesPerson class definition
// Member functions defined in SALESP.CPP

#ifndef SALESP_H
#define SALESP_H

class SalesPerson {
public:
   SalesPerson();             // constructor
   void setSales();           // user supplies sales figures
   void printAnnualSales();
private:
   double sales[13];          // 12 monthly sales figures
   double totalAnnualSales(); // utility function
};

#endif