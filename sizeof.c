#include <stdio.h>

main()
{
	
	int a = 5;
	float b;
	int c[20] = {0};

	b = 2.4356;

	printf("number of bytes in short = %d\n", sizeof(int));
	printf("number of bytes in int = %d\n", sizeof(int));
	printf("number of bytes in long = %d\n", sizeof(int));
	printf("number of bytes in float = %d\n", sizeof(int));
	printf("number of bytes in double = %d\n", sizeof(int));
	printf("number of bytes in int a = %d\n", sizeof(a));
	printf("number of bytes in float b = %d\n", sizeof(b));
	printf("number of elements in a[20] = %d\n", sizeof(c)/sizeof(int));

	return 0;
}
