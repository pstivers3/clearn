// FIG18_3.CPP
// Overloading the stream insertion and
// stream extraction operators.
#include <iostream.h>

class PhoneNumber {
   friend ostream &operator<<(ostream &, PhoneNumber &);
   friend istream &operator>>(istream &, PhoneNumber &);
private:
   char areaCode[4];  // 3-digit area code and null
   char exchange[4];  // 3-digit exchange and null
   char line[5];      // 4-digit line and null
};

// Overloaded stream insertion operator (cannot be
// a member function).
ostream &operator<<(ostream &output, PhoneNumber &num)
{
   output << "(" << num.areaCode << ") "
          << num.exchange << "-" << num.line;

   return output;     // enables cout << a << b << c;
}

// overloaded stream extraction operator
istream &operator>>(istream &input, PhoneNumber &num)
{
   input.ignore();                 // skip (
   input.getline(num.areaCode, 4); // input area code
   input.ignore(2);                // skip ) and space
   input.getline(num.exchange, 4); // input exchange
   input.ignore();                 // skip -
   input.getline(num.line, 5);     // input line

   return input;      // enables cin >> a >> b >> c;
}

main()
{
   PhoneNumber phone; // create object phone

   cout << "Enter a phone number in the "
	<< "form (123) 456-7890:\n";

   // cin >> phone invokes operator>> function by
   // issuing the call operator>>(cin, phone).
   cin >> phone;

   // cout << phone invokes operator<< function by
   // issuing the call operator<<(cout, phone).
   cout << "The phone number entered was:\n"
	<< phone << endl;
   return 0;
}

