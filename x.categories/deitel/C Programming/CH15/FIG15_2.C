// Functions that take no arguments
#include <iostream.h>

void f1();
void f2(void);

main()
{
   f1();
   f2();

   return 0;
}

void f1()
{
   cout << "Function f1 takes no arguments\n";
}

void f2(void)
{
   cout << "Function f2 also takes no arguments\n";
}

