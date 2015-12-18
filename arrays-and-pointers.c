#include <stdio.h>
#define SIZE 4

main()
{
	int *p, *q, a[SIZE] = {1,2,3,4};
	p = a;
	q = p + 1;
	printf("p = %p\n", p);
	printf("*p = %d\n", *p);
	printf("q-p address = %p\n", q-p);
	printf("q-p element loc = %p\n", q-p);
	printf("q-p element loc = %d\n", q-p);
}