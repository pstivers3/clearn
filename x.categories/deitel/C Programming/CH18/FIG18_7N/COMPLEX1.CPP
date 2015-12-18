// COMPLEX1.CPP
// Member function definitions for class Complex
#include <iostream.h>
#include "complex1.h"

// Constructor
Complex::Complex(double r, double i)
{
   real = r;
   imaginary = i;
}

// Overloaded addition operator
Complex Complex::operator+(const Complex &operand2) const
{
   Complex sum;
   sum.real = real + operand2.real;
   sum.imaginary = imaginary + operand2.imaginary;
   return sum;
}

// Overloaded subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
   Complex diff;
   diff.real = real - operand2.real;
   diff.imaginary = imaginary - operand2.imaginary;
   return diff;
}

// Overloaded = operator
Complex& Complex::operator=(const Complex &right)
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;   // enables concatenation
}

// Display a Complex object in the form: (a, b)
void Complex::print() const
   { cout << '(' << real << ", " << imaginary << ')'; }