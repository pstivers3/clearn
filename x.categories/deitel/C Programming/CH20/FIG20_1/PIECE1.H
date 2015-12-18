// PIECE1.H
// PieceWorker class derived from Employee
#ifndef PIECE1_H
#define PIECE1_H
#include "employ2.h"

class PieceWorker : public Employee {
public:
   PieceWorker(const char *, const char *,
               float = 0.0, int = 0);
   void setWage(float);
   void setQuantity(int);
   virtual float earnings() const;
   virtual void print() const;
private:
   float wagePerPiece; // wage for each piece output
   int quantity;       // output for week
};

#endif
