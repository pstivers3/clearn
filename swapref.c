#include <stdio.h>

swapByRef(int *c, int *d) {
  int temp; 
  temp= *c;
  *c = *d;
  *d = temp; 
}

void main(void) {
  int c=1, d=2;
//  int *c, *d;
  
  //swap c and d 
  printf("before swap: c = %d, d = %d\n", c, d);
  swapByRef(&c, &d); 
  printf("after swap:  c = %d, d = %d\n", c, d);
}
