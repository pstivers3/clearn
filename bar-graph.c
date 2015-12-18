#include <stdio.h>

void bar(int);

main()
{
	printf("\n");
	printf("bar 1\t");
	bar(27);
	printf("bar 2\t");
	bar(41);
	printf("bar 3\t");
	bar(34);
	printf("bar 4\t");
	bar(22);
	printf("bar 5\t");
	bar(15);
	return 0;
}

void bar(int size)
{
	int j;

	for(j=1; j<=size; j++)
		printf("\xCD");
	printf("\n\n");
}
