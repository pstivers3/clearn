#include <stdio.h>

int a, b;

int swapByVal(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void main(void) {
  a=1, b=2;
  
  // swab a and b
  printf("before swap: a = %d, b = %d\n", a, b);
  swapByVal(a,b);
  printf("after swap:  a = %d, b = %d\n", a, b);
}
