// FIG17_6.CPP
// Non-friend/non-member functions cannot access
// private data of a class.
#include <iostream.h>

// Modified Count class
class Count {
public:
   Count() { x = 0; }                   // constructor
   void print() const { cout << x << '\n'; }  // output
private:
   int x;  // data member
};

// Function tries to modify private data of Count,
// but cannot because it is not a friend of Count.
void cannotSetX(Count &c, int val)
{
   c.x = val;  // ERROR: 'Count::x' is not accessible
}

main()
{
   Count object;

   cannotSetX(object, 3); // cannotSetX is not a friend

   return 0;
}