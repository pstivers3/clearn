#include <stdio.h>
main() {
  char string1[80];

  do {
    printf("enter a string, x to end: ");
    scanf("%s",string1);
    printf("string is: %s\n", string1);
  }
  while (string1[0] != 'x');
  return 0;
}
