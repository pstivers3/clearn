#include <stdio.h>

void main() {
  int a=1;
  do {
    printf("%d\n", a);
  } while (++a <= 3);
  printf("a outside of while = %d\n", a);
}
