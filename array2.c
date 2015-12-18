#include <stdio.h>

void printarray(int v[]) {  
  int i;
  for (i=0; i <= 20; i++) 
    printf("%d  ", v[i]);
  printf("\n");
}

void main(void) {
  int v[6] = {1, 2, 3};
  printarray(v);
}
