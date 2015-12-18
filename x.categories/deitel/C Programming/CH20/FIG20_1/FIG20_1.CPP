// FIG20_1.CPP
// Driver for Employee hierarchy
#include <iostream.h>
#include <iomanip.h>
#include "employ2.h"
#include "boss1.h"
#include "commis1.h"
#include "piece1.h"
#include "hourly1.h"

main()
{
   // set output formatting
   cout << setiosflags(ios::showpoint) << setprecision(2);

   Employee *ptr;  // base-class pointer

   Boss b("John", "Smith", 800.00);
   ptr = &b;  // base-class pointer to derived-class object
   ptr->print();                           // dynamic binding
   cout << " earned $" << ptr->earnings(); // dynamic binding
   b.print();                              // static binding
   cout << " earned $" << b.earnings();    // static binding

   CommissionWorker c("Sue", "Jones", 200.0, 3.0, 150);
   ptr = &c;  // base-class pointer to derived-class object
   ptr->print();                           // dynamic binding
   cout << " earned $" << ptr->earnings(); // dynamic binding
   c.print();                              // static binding
   cout << " earned $" << c.earnings();    // static binding

   PieceWorker p("Bob", "Lewis", 2.5, 200);
   ptr = &p;  // base-class pointer to derived-class object
   ptr->print();                           // dynamic binding
   cout << " earned $" << ptr->earnings(); // dynamic binding
   p.print();                              // static binding
   cout << " earned $" << p.earnings();    // static binding

   HourlyWorker h("Karen", "Price", 13.75, 40);
   ptr = &h;  // base-class pointer to derived-class object
   ptr->print();                           // dynamic binding
   cout << " earned $" << ptr->earnings(); // dynamic binding
   h.print();                              // static binding
   cout << " earned $" << h.earnings();    // static binding

   cout << endl;
   return 0;
}