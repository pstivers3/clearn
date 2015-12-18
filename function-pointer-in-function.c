#include <stdio.h>

int max(int, int);
int min(int, int);
int optimize(int *, int(*)(int , int ), int);

main()
{
	int selection, opt;
	int x[5] = { 23,56,45,72,9};

	printf("Enter 1 for maximum, 2 for minimum\n");
	scanf("%d", &selection);

	if( selection == 1)
		opt = optimize(x, max, 5);
	else if(selection == 2)
		opt = optimize(x, min, 5);
	else
		printf("Error in selection\n");

	printf("The result is %d\n", opt);

	return 0;
	
}

int optimize(int x[], int (*f)(int a,int b), int size)
{
	int i;
	int result = x[0];

	for(i=0; i<size; i++)
		result = f(result, x[i]);

	return result;
}

int max( int a, int b )
{
	if(a>b)
		return a;
	else
		return b;
}

int min( int a, int b )
{
	if(a<b)
		return a;
	else
		return b;
}

