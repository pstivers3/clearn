// Using template functions
#include <iostream.h>

template <class T>
void printArray(T *array, const int count)
{
   for (int i = 0; i < count; i++)
      cout << array[i] << " ";

   cout << '\n';
}

main()
{
   const int aCount = 5, bCount = 7, cCount = 6;
   int a[aCount] = {1, 2, 3, 4, 5};
   float b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
   char c[cCount] = "HELLO";  // 6th position for null

   cout << "Array a contains:\n";
   printArray(a, aCount);  // integer version

   cout << "Array b contains:\n";
   printArray(b, bCount);  // float version

   cout << "Array c contains:\n";
   printArray(c, cCount);  // character version 

   return 0;
}

