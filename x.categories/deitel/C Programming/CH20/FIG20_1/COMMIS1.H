// COMMIS1.H
// CommissionWorker class derived from Employee
#ifndef COMMIS1_H
#define COMMIS1_H
#include "employ2.h"

class CommissionWorker : public Employee {
public:
   CommissionWorker(const char *, const char *,
                    float = 0.0, float = 0.0, int = 0);
   void setSalary(float);
   void setCommission(float);
   void setQuantity(int);
   virtual float earnings() const;
   virtual void print() const;
private:
   float salary;     // base salary per week
   float commission; // amount per item sold
   int quantity;     // total items sold for week
};

#endif
