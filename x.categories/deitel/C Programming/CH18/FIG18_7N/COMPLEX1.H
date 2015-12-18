// COMPLEX1.H
// Definition of class Complex
#ifndef COMPLEX1_H
#define COMPLEX1_H

class Complex {
public:
   Complex(double = 0.0, double = 0.0);     // constructor
   Complex operator+(const Complex&) const; // addition
   Complex operator-(const Complex&) const; // subtraction
   Complex& operator=(const Complex&);      // assignment
   void print() const;                      // output
private:
   double real;       // real part
   double imaginary;  // imaginary part
};

#endif