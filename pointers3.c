#include <stdio.h>

void main(void) {
  int k, i = 3, j = 5, *p = &i, *r;
  printf("*(r = &j) *= *p = %d\n", *(r = &j) *= *p); // = 15
  // (k=3) *= 5; // throws error:  lvalue required as left operand of assignment
}

