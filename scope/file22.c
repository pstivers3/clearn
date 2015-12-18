#include <stdio.h>

void f2(void) {
  extern int a;
  int b=2;
  printf("f2;   a=1, b=2, check; a=%d  b=%d\n", a, b);
}

