#include <stdio.h>
#define SIZE 4

main()
{
  int i, a[SIZE] = {1,2,3,4}, b[SIZE] = {2,2,3,3};
  
  printf("array a is: ");
  for (i = 0; i <= SIZE-1; i++)
    printf("%3d", a[i]);
  printf("\n");

  printf("array b is: ");
  for (i = 0; i <= SIZE-1; i++)
    printf("%3d", b[i]);
  printf("\n");

  printf("sum ab is:  ");
  for (i = 0; i <= SIZE-1; i++)
    printf("%3d", a[i]+b[i]);
  printf("\n");
}
