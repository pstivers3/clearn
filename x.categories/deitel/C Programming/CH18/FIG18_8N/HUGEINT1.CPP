// HUGEINT1.CPP  --> cpp_htp\overload\ex06
// Member and friend function definitions for class HugeInt
#include <string.h>
#include "hugeint1.h"

// Conversion constructor
HugeInt::HugeInt(long val)
{
   for (int i = 0; i <= 29; i++)
      integer[i] = 0;   // initialize array to zero

   for (i = 29; val != 0 && i >= 0; i--) {
      integer[i] = val % 10;
      val /= 10;
   }
}

HugeInt::HugeInt(const char *string)
{
   int i, j;

   for (i = 0; i <= 29; i++)
      integer[i] = 0;

   for (i = 30 - strlen(string), j = 0; i <= 29; i++, j++)
      integer[i] = string[j] - '0';
}

// Addition
HugeInt HugeInt::operator+(HugeInt &op2)
{
   HugeInt temp;
   int carry = 0;

   for (int i = 29; i >= 0; i--) {
      temp.integer[i] = integer[i] + op2.integer[i] + carry;

      if (temp.integer[i] > 9) {
	 temp.integer[i] %= 10;
	 carry = 1;
      }
      else
	 carry = 0;
   }

   return temp;
}

ostream &operator<<(ostream &output, HugeInt &num)
{
   for (int i = 0; (num.integer[i] == 0) && (i <= 29); i++)
      ; // skip leading zeros

   if (i == 30)
      output << 0;
   else
      for ( ; i <= 29; i++)
         output << num.integer[i];

   return output;
}