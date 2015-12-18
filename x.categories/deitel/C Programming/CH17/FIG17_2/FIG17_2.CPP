// FIG17_2.CPP
// Using a member initializer to initialize a
// simple constant of a built in data type.
#include <iostream.h>

class Increment {
public:
   Increment(int c = 0, int i = 1);
   void addIncrement() { count += increment; }
   void print() const;
private:
   int count;
   const int increment;
};

// Constructor for class Increment
Increment::Increment(int c, int i)
   : increment(i)   // Member initializer
{ count = c; }

// Print the data
void Increment::print() const
{
   cout << "count = " << count
        << ", increment = " << increment << endl;
}

main()
{
   Increment value(10, 5);

   cout << "Before incrementing: ";
   value.print();

   for (int j = 1; j <= 3; j++) {
      value.addIncrement();
      cout << "After increment " << j << ": ";
      value.print();
   }

   return 0;
}