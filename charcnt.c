#include <stdio.h>
void main(void)
{
    int count = 0;

    printf("Type in any word of phrase, the press enter:\n");
    while (getche() != '\r')
       count++;
    printf("\nCharacter count is %d.",count);

}