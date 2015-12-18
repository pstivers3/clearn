#include <stdio.h>
#include <math.h>

/*  pt = c^d mod n */


int main(void)
{
	long pt,c,d,n;

	printf("c?:  ");
	scanf("%d", &c);
	printf("d?:  ");
	scanf("%d", &d);
    printf("n?:  ");
	scanf("%d", &n);
	
	pt = 1;
	
	while(d != 0)
	{
		if (d%2 == 1)
		{
			pt = (pt*c) % n;
			printf("pt = %ld",pt);
			
		}
		
		c = (c*c) % n;
		
		if (d%2 == 1)
			d = (d-1)/2;
		else
		    d = d/2;
	}

	printf("%ld\n",pt);

	return 0;
}