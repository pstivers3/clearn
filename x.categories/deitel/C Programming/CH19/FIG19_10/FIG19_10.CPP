// FIG19_10.CPP
// Driver for multiple inheritance example
#include <iostream.h>
#include "base1.h"
#include "base2.h"
#include "derived.h"

main()
{
   Base1 b1(10), *base1Ptr;   // create base-class object
   Base2 b2('Z'), *base2Ptr;  // create other base-class object
   Derived d(7, 'A', 3.5);    // create derived-class object

   // print data members of base class objects
   cout << "Object b1 contains integer "
	<< b1.getData()
	<< "\nObject b2 contains character "
	<< b2.getData()
	<< "\nObject d contains:\n" << d;

   // print data members of derived class object
   // scope resolution operator resolves getData ambiguity
   cout << "\n\nData members of Derived can be"
	<< " accessed individually:\n"
	<< "    Integer: " << d.Base1::getData()
	<< "\n  Character: " << d.Base2::getData()
	<< "\nReal number: " << d.getReal() << "\n\n";

   cout << "Derived can be treated as an "
	<< "object of either base class:\n";

   // treat Derived object as a Base1 object
   base1Ptr = &d;
   cout << "base1Ptr->getData() yields "
	<< base1Ptr->getData();

   // treat Derived object as a Base2 object
   base2Ptr = &d;
   cout << "\nbase2Ptr->getData() yields "
	<< base2Ptr->getData() << endl;

   return 0;
}