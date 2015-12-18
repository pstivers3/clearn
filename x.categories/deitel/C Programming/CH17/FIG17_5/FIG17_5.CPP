// FIG17_5.CPP
// Friends can access private members of a class.
#include <iostream.h>

// Modified Count class
class Count {
   friend void setX(Count &, int);  // friend declaration
public:
   Count() { x = 0; }               // constructor
   void print() const { cout << x << endl; }  // output
private:
   int x;  // data member
};

// Can modify private data of Count because
// setX is declared as a friend of Count
void setX(Count &c, int val)
{
   c.x = val;  // legal: setX is a friend of Count
}

main()
{
   Count object;

   cout << "object.x after instantiation: ";
   object.print();
   cout << "object.x after call to setX friend function: ";
   setX(object, 8);  // set x with a friend
   object.print();

   return 0;
}