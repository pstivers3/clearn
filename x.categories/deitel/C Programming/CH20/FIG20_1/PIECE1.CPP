// PIECE1.CPP
// Member function definitions for class PieceWorker
#include <iostream.h>
#include "piece1.h"

// Constructor for class PieceWorker
PieceWorker::PieceWorker(const char *first,
             const char *last, float w, int q)
   : Employee(first, last)  // call base-class constructor
{
   wagePerPiece = w > 0 ? w : 0;
   quantity = q > 0 ? q : 0;
}

// Set the wage
void PieceWorker::setWage(float w)
{ wagePerPiece = w > 0 ? w : 0; }

// Set the number of items output
void PieceWorker::setQuantity(int q)
{ quantity = q > 0 ? q : 0; }

// Determine the PieceWorker's earnings
float PieceWorker::earnings() const
{ return quantity * wagePerPiece; }

// Print the PieceWorker's name and pay
void PieceWorker::print() const
{
   cout << "\n     Piece worker: " << getFirstName()
	<< ' ' << getLastName();
}

