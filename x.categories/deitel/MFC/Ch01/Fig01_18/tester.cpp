#include <iostream.h>
void myFunction( int c );

int main()
{
   int x = 0;

   cout << "Please enter a number: ";
   cin >> x;

   myFunction( x );

   return 0;
}

void myFunction( int c )
{
   if ( c > 0 )
      cout << "positive";
   else
      cout << "negative";

   cout << endl;
}

