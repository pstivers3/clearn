#include <stdio.h>

void f2(void) {
  int a = 2;
  int b = 2;
  extern c;
  printf("f2;   a=2, b=2, c=1 check; a=%d  b=%d  c=%d\n", a, b, c);
}

