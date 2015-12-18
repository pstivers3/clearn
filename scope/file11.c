#include <stdio.h>

static int a=1;
int b=1;
int c=1;

void f1(void) {
  extern int b;
  b=2;
  printf("f1;   a=1, b=2, c=1 check; a=%d  b=%d  c=%d\n", a, b, c);
}

void main(void) {
  extern int b; 
  printf("main; a=1, b=1, c=1 check; a=%d  b=%d  c=%d\n", a, b, c);
  f1();
  f2();
  printf("main; a=1, b=2, c=1 check; a=%d  b=%d  c=%d\n", a, b, c);
}

