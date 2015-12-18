// FIG17_7.CPP
// Using the this pointer to refer to object members.
#include <iostream.h>

class Test {
public:
   Test(int = 0);
   void print() const;
private:
   int x;
};

Test::Test(int a) { x = a; }    // constructor

void Test::print() const
{
   cout << "        x = " << x
        << "\n  this->x = " << this->x
        << "\n(*this).x = " << (*this).x << '\n';
}

main()
{
   Test a(12);

   a.print();

   return 0;
}