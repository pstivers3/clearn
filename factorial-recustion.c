#include <stdio.h>

long int fact(long);

main()

{
	long num,result;
	printf("enter number ");
	scanf("%ld",&num);
	result = fact(num);
	printf("%ld factorial = %ld\n",num,result);
		return 0;
}

	long fact(long y){
		if (y <= 1)
			return 1;
		else
			return y*fact(y-1);
	}