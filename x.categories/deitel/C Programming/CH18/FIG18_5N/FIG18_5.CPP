// FIG18_4.CPP
// Driver for class String
#include <iostream.h>
#include "string2.h"

main()
{
   String s1("happy"), s2(" birthday"), s3;

   // test overloaded equality and relational operators
   cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
        << "\"; s3 is empty\n"
        << "The results of comparing s2 and s1:"
        << "\ns2 == s1 yields " << (s2 == s1)
        << "\ns2 != s1 yields " << (s2 != s1)
        << "\ns2 >  s1 yields " << (s2 > s1)
        << "\ns2 <  s1 yields " << (s2 < s1)
        << "\ns2 >= s1 yields " << (s2 >= s1)
        << "\ns2 <= s1 yields " << (s2 <= s1) << "\n\n";

   // test overloaded String empty (!) operator
   cout << "Testing !s3:\n";
   if (!s3) {
      cout << "s3 is empty; assigning s1 to s3;\n";
      s3 = s1;              // test overloaded assignment
      cout << "s3 is \"" << s3 << "\"\n\n";
   }

   // test overloaded String concatenation operator
   cout << "s1 += s2 yields s1 = ";
   s1 += s2;                // test overloaded concatenation
   cout << s1 << "\n\n";

   // test conversion constructor
   cout << "s1 += \" to you\" yields\n";
   s1 += " to you";        // test conversion constructor
   cout << "s1 = " << s1 << "\n\n";

   // test overloaded function call operator () for substring
   cout << "The substring of s1 starting at\n"
	<< "location 0 for 14 characters, s1(0, 14), is: "
	<< s1(0, 14) << "\n\n";

   // test substring "to-end-of-String" option
   cout << "The substring of s1 starting at\n"
	<< "location 15, s1(15, 0), is: "
	<< s1(15, 0) << "\n\n";  // 0 means "to end of string"

   // test copy constructor
   String *s4Ptr = new String(s1);
   cout << "*s4Ptr = " << *s4Ptr << "\n\n";

   // test assignment operator (=) with self-assignment
   cout << "assigning *s4Ptr to *s4Ptr\n";
   *s4Ptr = *s4Ptr;  // test overloaded assignment
   cout << "*s4Ptr = " << *s4Ptr << endl;

   // test destructor
   delete s4Ptr;

   // test using subscript operator to create lvalue
   s1[0] = 'H';
   s1[6] = 'B';
   cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
        << s1 << "\n\n";

   // test subscript out of range
   cout << "Attempt to assign 'd' to s1[30] yields:\n";
   s1[30] = 'd';     // ERROR: subscript out of range

   return 0;
}