#include <stdio.h>
main()
{
	char string1[20]; 

	printf("enter a string, x to end: ");
	scanf("%s",string1);
	do {	
	printf("string is %s\n", string1);
	printf("2nd and 3rd characters are %c and %c\n",string1[1],string1[2]);
	printf("enter a string, x to end: ");
	scanf("%s",string1);
	}
	while (string1[0] != 'x');

	return 0;
}