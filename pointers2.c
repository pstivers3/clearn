#include <stdio.h>
main()
{
	char a[] = "abc", *pa = a, i;

	puts(a);
	puts(pa);
	printf("memory location stored in a is %u\n"
		"memory location stored in pa is %u\n", a, pa);
	pa = "new";
	puts(a);
	puts(pa);
	printf("memory location stored in a is %u\n"
		"memory location stored in pa is %u\n", a, pa);
	for(i = 0; i<3; i++)
		printf("%u\n", *(a+i));	
	return 0;
}
