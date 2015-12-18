#include <stdio.h>

struct number{
	int a[10];
} b;

int fun(int);

main()
{	
	int c;
	b.a[0] = 5;
	c = fun(b.a[0]);
	printf("%d\n", c);

	return 0;
}

fun(int b)
{
	return b += 3;
}

