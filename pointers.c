#include <stdio.h>

void main(void) {
  int x = 1, y = 2, z[10];
  int *ip;      // ip is declared as a pointer to int. it stores an address.
  ip = &x;      // assings the adress of x to ip. ip now points to x
  printf("ip = %p\n", ip);
  y = *ip;      // assignes the object in memory location ip (= &x) to y. y is now 1
  printf("y = %d\n", y);
  *ip = 0;      // assins 0 as the object in memory location ip (*ip). x is now 0
  printf("*ip = x = %d\n", *ip);
  ip = &z[0];   // ip now points to z[0]
  printf("ip = %p\n", ip);
}

