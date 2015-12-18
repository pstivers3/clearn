#include <stdio.h>
#include <string.h>

/* A program to seperate a string into words */

main()
{
	char s1[] = "x := 56; y := 7;";
	char s2[] = " ;";
	char *p;
	
	p = strtok(s1,s2);

	if(p)
		printf("%s\n", p);

	while (p) {
		p = strtok(NULL, s2);
		if(p)
			printf("%s\n", p);
	}

	return 0;

}