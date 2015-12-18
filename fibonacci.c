#include <stdio.h>

main()

{ 
	int i, n=0;
	long j, ktemp, k;
	
	while (n <=30)
	{
	printf("enter n, 31 to quite: ");
	scanf("%d",&n);
	
	switch (n)
	{
	case 0: case 1:
		printf("%d\n",n);
		break;
	case 31:
		break;
	default:
		{
		j=0, ktemp=1, k=1;
		for (i=2; i <= n; i++)
			{
				ktemp = k;
				k += j;
				j = ktemp;
			}
		printf("%ld\n",k);
		}
	
	}
	}
	return 0;
}

