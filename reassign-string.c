/*  Program 1 */

#include <stdio.h>
main()
{
	char a[] = "abc", *pa = a;

	puts(a);
	puts(pa);
	printf("memory location stored in a is %p\n"
		"memory location stored in pa is %p\n", a, pa);
	pa = "new";
	puts(a);
	puts(pa);
	printf("memory location stored in a is %p\n"
		"memory location stored in pa is %p\n", a, pa);
	putchar(*(a+3));
	putchar(*(pa+3));
	
	return 0;
}


/*   Output  
abc
abc
memory location stored in a is 0012FF7C
memory location stored in pa is 0012FF7C
abc
new
memory location stored in a is 0012FF7C
memory location stored in pa is 0042001C
*/

/* Program 2 */

/*
#include <stdio.h>
#include <string.h>

main()
{
	char a[] = "abc", *pa = a;

	puts(a);
	puts(pa);
	printf("memory location stored in a is %p\n"
		"memory location stored in pa is %p\n", a, pa);
	strcpy(pa, "new");
	puts(a);
	puts(pa);
	printf("memory location stored in a is %p\n"
	"memory location stored in pa is %p\n", a, pa);
	return 0;
}
*/

/*  Output
abc
abc
memory location stored in a is 0012FF7C
memory location stored in pa is 0012FF7C
new
new
memory location stored in a is 0012FF7C
memory location stored in pa is 0012FF7C
*/







/*
{
	char *pa;
	pa = "abc";
	puts(pa);
	return 0;

}*/