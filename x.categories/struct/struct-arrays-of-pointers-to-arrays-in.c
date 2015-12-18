#include <stdio.h>

typedef struct test {
	int a;
	char b[20];
} test;

main()
{	
	test ar[20], *par = ar;
	
	(par +0) ->b[0] = 'p';
	(par +0) ->b[1] = 's';
	(par +0) ->b[2] = '\0';

	(par +0) ->a = 1;

	printf("%s\n", (*par).b);
	printf("%d\n", (par+0) ->a);

	return 0;
}

