/* The name of an array is the same as &array[0] */
#include <stdio.h>

main()
{
   char array[5];

   printf("    array = %p\n&array[0] = %p\n",
          array, &array[0]);
   return 0;
}

