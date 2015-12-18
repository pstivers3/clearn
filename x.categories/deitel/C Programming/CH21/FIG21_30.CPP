// fig21_30.cpp
// User-defined insertion and extraction operators
#include <iostream.h>

class PhoneNumber {
	friend ostream& operator<<(ostream&, PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);
private:
	char areaCode[4];
	char exchange[4];
	char line[5];
};

ostream& operator<<(ostream& output, PhoneNumber& num)
{
	output << "(" << num.areaCode << ") "
			 << num.exchange << "-" << num.line;

	return output;
}

istream& operator>>(istream& input, PhoneNumber& num)
{
	input.ignore();                 // skip (
	input.getline(num.areaCode, 4);
	input.ignore(2);                // skip ) and space
	input.getline(num.exchange, 4);
	input.ignore();                 // skip -
	input.getline(num.line, 5);

	return input;
}

main()
{
	PhoneNumber phone;

	cout << "Enter a phone number in the "
		  << "form (123) 456-7890:\n";
	cin >> phone;
	cout << "The phone number entered was:\n"
		  << phone << endl;

	return 0;
}

