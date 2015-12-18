// illustrate errors in macros

#include <stdio.h>

#define max(A, B)  ((A) > (B) ? (A) : (B))
#define square(x)  x * x  // should be (x) * (x)

void main(void) {
  int i=1, j=2;
  int z = 2;
  printf("expect 3: %d\n", max(i++, j++));  // the larger value expands twice
  printf("expect 4: %d\n", j);
  printf("expect 8: %d\n", square(z+2));  
}

