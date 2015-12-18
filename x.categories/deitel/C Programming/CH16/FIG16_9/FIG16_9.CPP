// FIG16_9.CPP
// Demonstrating the order in which constructors and
// destructors are called.
#include <iostream.h>
#include "create.h"

void create(void);   // prototype

CreateAndDestroy first(1);  // global object

main()
{
   cout << "   (global created before main)\n";

   CreateAndDestroy second(2);        // local object
   cout << "   (local automatic in main)\n";

   static CreateAndDestroy third(3);  // local object
   cout << "   (local static in main)\n";

   create();  // call function to create objects

   CreateAndDestroy fourth(4);        // local object
   cout << "   (local automatic in main)\n";
   return 0;
}

// Function to create objects
void create(void)
{
   CreateAndDestroy fifth(5);
   cout << "   (local automatic in create)\n";

   static CreateAndDestroy sixth(6);
   cout << "   (local static in create)\n";

   CreateAndDestroy seventh(7);
   cout << "   (local automatic in create)\n";
}