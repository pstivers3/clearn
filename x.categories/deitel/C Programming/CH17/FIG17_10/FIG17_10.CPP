// FIG17_10.CPP
// Test driver for Stack template
#include <iostream.h>
#include "tstack1.h"

main()
{
   Stack<float> floatStack(5);
   float f = 1.1;
   cout << "Pushing elements onto floatStack\n";

   while (floatStack.push(f)) { // success (1 returned)
      cout << f << ' ';
      f += 1.1;
   }

   cout << "\nStack is full. Cannot push " << f
	<< "\n\nPopping elements from floatStack" << endl;

   while (floatStack.pop(f))  // success (1 returned)
      cout << f << ' ';

   cout << "\nStack is empty. Cannot pop" << endl;

   Stack<int> intStack;
   int i = 1;
   cout << "\nPushing elements onto intStack\n";

   while (intStack.push(i)) { // success (1 returned)
      cout << i << ' ';
      i += 1;
   }

   cout << "\nStack is full. Cannot push " << i
	<< "\n\nPopping elements from intStack" << endl;

   while (intStack.pop(i))  // success (1 returned)
      cout << i << ' ';

   cout << "\nStack is empty. Cannot pop" << endl;
   return 0;
}