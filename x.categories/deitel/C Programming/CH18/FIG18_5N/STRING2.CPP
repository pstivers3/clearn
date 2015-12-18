// STRING2.CPP
// Member function definitions for class String
#include <iostream.h>
#include <string.h>
#include <assert.h>
#include "string2.h"

// Conversion constructor: Convert a char * to String
String::String(const char *s)
{
   cout << "Conversion constructor: " << s << endl;
   length = strlen(s);          // compute length
   sPtr = new char[length + 1]; // allocate storage
   assert(sPtr != 0);  // terminate if memory not allocated
   strcpy(sPtr, s);             // copy literal to object
}

// Copy constructor
String::String(const String &copy)
{
   cout << "Copy constructor: " << copy.sPtr << endl;
   length = copy.length;        // copy length
   sPtr = new char[length + 1]; // allocate storage
   assert(sPtr != 0);           // ensure memory allocated
   strcpy(sPtr, copy.sPtr);     // copy string
}

// Destructor
String::~String()
{
   cout << "Destructor: " << sPtr << endl;
   delete [] sPtr;              // reclaim string
}

// Overloaded = operator; avoids self assignment
const String &String::operator=(const String &right)
{
   cout << "operator= called" << endl;

   if (&right != this) {           // avoid self assignment
      delete [] sPtr;              // prevents memory leak
      length = right.length;       // new String length
      sPtr = new char[length + 1]; // allocate memory
      assert(sPtr != 0);           // ensure memory allocated
      strcpy(sPtr, right.sPtr);    // copy string
   }
   else
      cout << "Attempted assignment of a String to itself\n";

   return *this;   // enables concatenated assignments
}

// Concatenate right operand to this object and
// store in this object.
String &String::operator+=(const String &right)
{
   char *tempPtr = sPtr;        // hold to be able to delete
   length += right.length;      // new String length
   sPtr = new char[length + 1]; // create space
   assert(sPtr != 0);   // terminate if memory not allocated
   strcpy(sPtr, tempPtr);       // left part of new String
   strcat(sPtr, right.sPtr);    // right part of new String
   delete [] tempPtr;           // reclaim old space
   return *this;                // enables concatenated calls
}

// Is this String empty?
int String::operator!() const { return length == 0; }

// Is this String equal to right String?
int String::operator==(const String &right) const
   { return strcmp(sPtr, right.sPtr) == 0; }

// Is this String not equal to right String?
int String::operator!=(const String &right) const
   { return strcmp(sPtr, right.sPtr) != 0; }

// Is this String less than right String?
int String::operator<(const String &right) const
   { return strcmp(sPtr, right.sPtr) < 0; }

// Is this String greater than right String?
int String::operator>(const String &right) const
   { return strcmp(sPtr, right.sPtr) > 0; }

// Is this String greater than or equal to right String?
int String::operator>=(const String &right) const
   { return strcmp(sPtr, right.sPtr) >= 0; }

// Is this String less than or equal to right String?
int String::operator<=(const String &right) const
   { return strcmp(sPtr, right.sPtr) <= 0; }

// Return a reference to a character in a String.
char &String::operator[](int subscript)
{
   // First test for subscript out of range
   assert(subscript >= 0 && subscript < length);

   return sPtr[subscript];  // creates lvalue
}

// Return a substring beginning at index and
// of length subLength as a reference to a String object.
String &String::operator()(int index, int subLength)
{
   // ensure index is in range and substring length >= 0
   assert(index >= 0 && index < length && subLength >= 0);

   String *subPtr = new String;   // empty String
   assert(subPtr != 0);  // ensure new String allocated

   // determine length of substring
   int size;

   if ((subLength == 0) || (index + subLength > length))
      size = length - index + 1;
   else
      size = subLength + 1;

   // allocate memory for substring
   subPtr->length = size;
   subPtr->sPtr = new char[size];
   assert(subPtr->sPtr != 0);  // ensure space allocated

   // copy substring into new String
   for (int i = index, j = 0; i < index + size - 1; i++, j++)
      subPtr->sPtr[j] = sPtr[i];

   subPtr->sPtr[j] = '\0';  // terminate the new String
   return *subPtr;          // return new String
}

// Return string length
int String::getLength() const { return length; }

// Overloaded output operator
ostream &operator<<(ostream &output, const String &s)
{
   output << s.sPtr;
   return output;   // enables concatenation
}

// Overloaded input operator
istream &operator>>(istream &input, String &s)
{
   static char temp[100];   // buffer to store input

   input >> temp;
   s = temp;    // Use String class assignment operator
   return input;    // enables concatenation
}
