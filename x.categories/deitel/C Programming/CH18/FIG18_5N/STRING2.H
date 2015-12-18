// STRING2.H
// Definition of a String class
#ifndef STRING1_H
#define STRING1_H

#include <iostream.h>

class String {
   friend ostream &operator<<(ostream &, const String &);
   friend istream &operator>>(istream &, String &);
public:
   String(const char * = ""); // conversion constructor
   String(const String &);    // copy constructor
   ~String();                 // destructor
   const String &operator=(const String &);  // assignment
   String &operator+=(const String &);    // concatenation
   int operator!() const;                 // is String empty?
   int operator==(const String &) const;  // test s1 == s2
   int operator!=(const String &) const;  // test s1 != s2
   int operator<(const String &)  const;  // test s1 < s2
   int operator>(const String &)  const;  // test s1 > s2
   int operator>=(const String &) const;  // test s1 >= s2
   int operator<=(const String &) const;  // test s1 <= s2
   char &operator[](int);        // return char reference
   String &operator()(int, int); // return a substring
   int getLength() const;        // return string length
private:
   char *sPtr;                   // pointer to start of string
   int length;                   // length of the string
};

#endif