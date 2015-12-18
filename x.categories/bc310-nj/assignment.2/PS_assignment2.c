/*  PS_assignment2, Array Functions, Paul Stivers, 2/17/00
	
	This program calculates and displays a list of array functions on 
	two arrays of equal size.  The user inputs the array size and the 
	elements of each array */

#include <stdio.h>
#define SIZE 20

/* function prototypes */
void LOAD(int[], int);
int SUM(int[], int);
int MIN(int[], int);
int MAX(int[], int);
void DISPLAY(int[], int);
void ADD2ARRAYS(int[], int[], int[], int);
int PRODUCT(int[], int[], int);
void CHOOSE(int[], int, int, int[]);

main()
{
	int a[SIZE], b[SIZE], c[SIZE];	
	int sz, check=0;
		
		
	/* user input array size */
	printf("Enter array size 1-20, or -1 to end:    ");
	scanf("%d", &sz);
	
	if (sz == -1)
		printf("\nProgram terminated by -1\n");
	
	/* while loop to test for sz = -1 to terminate program */
	while (sz != -1)
	{
		/* test for size out of range 1-20 */
		if (sz < 1 || sz > 20)
			printf("Size out of range 1-20\nTry Again\n");
		else
		{
		
			/* call LOAD to load a[], then call DISPLAY to display */
			/* a[] for user check.  Do the same for b[] */
			do
			{
				printf("\nLoad array a\n");
				LOAD(a, sz);
				printf("\na = ");
				DISPLAY(a, sz);		
				printf("Is this correct ");
				printf("(yes = 1, no = any other number)?:  ");
				scanf("%d", &check);
			}
			while(check != 1);	
			
			do
			{
				printf("\nLoad array b\n");
				LOAD(b, sz);
				printf("\nb = ");
				DISPLAY(b, sz);		
				printf("Is this correct ");
				printf("(yes = 1, no = any other number)?:  ");
				scanf("%d", &check);
			}
			while(check != 1);
			
			/* Calculate and output results.  Note - the functions are */
			/* are often called from within the prinf statements */
			printf("\nResults\n");
			printf("***************************************************\n");
						
			/* call DISPLAY to display a[] and b[] */
			printf("a = ");
			DISPLAY(a, sz);
			
			printf("b = ");
			DISPLAY(b, sz);
			
			/* call SUM and print the sum of elements in a[] and b[] */
			printf("\nsum of a = %d \n", SUM(a, sz));
			printf("sum of b = %d \n", SUM(b, sz));

			/* call MIN and print the mimimum element in a[] and b[] */
			printf("\nminimum of a = %d \n", MIN(a, sz));
			printf("minimum of b = %d \n", MIN(b, sz));

			/* call MAX and print the maximum element in a[] and b[] */
			printf("\nmaximum of a = %d \n", MAX(a, sz));
			printf("maximum of b = %d \n", MAX(b, sz));

			/* call ADD2ARRAYS to add the corresponding elements of a and b, */
			/* and store in c[], display the result c[] */
			ADD2ARRAYS(a, b, c, sz);
			printf("\nADD2ARRAYS a + b =  ");
			DISPLAY(c, sz);
				
			/* call PRODUCT, returns the sum of the product of the */
			/* corresponding elements of a[] and b[], print the answer */
			
			printf("\nPRODUCT of a and b = %d \n", PRODUCT(a, b, sz));
		
			/* call CHOOSE for a[] to choose elements that are  greater */
			/* than 3, store them in c[], set the rest of the elements */
			/* in c[] to zero, and display the result c[].  Do the same */
			/* for b[] */
			CHOOSE(a, sz, 3, c);
			printf("\nCHOOSE elements greater than 3, of a = ");
			DISPLAY(c, sz);
			
			CHOOSE(b, sz, 3, c);
			printf("CHOOSE elements greater than 3, of b = ");
			DISPLAY(c, sz);

			printf("***************************************************\n");
		}
		/* Give user a chance to input another array size to perform */
		/* functions again, or in case user entered array size out of */
		/* of range the previous time */
		printf("\nEnter array size 1-20, or -1 to end:    ");
		scanf("%d", &sz);
	
		if (sz == -1)
		printf("\nProgram terminated by -1\n");

	}
	
	return 0;
}

/**********************  End of Main()  ********************************/

	/* function LOAD, user input to load array x[n] */
	void LOAD(int x[], int n)
	{
		int i;

		for (i=0; i < n; i++)
		{
			printf("Enter element %d:    ", i);
			scanf("%d", &x[i]);
		}
	}
		
	
	/* function SUM, returns the sum of the elements of x[n] */
	int SUM(int x[], int n)
	{
		int i, tot=0;

		for(i=0; i < n; i++)
			tot += x[i];

		return tot;
	}

	/* function MIN, returns the minimum element in x[n] */
	int MIN(int x[], int n)
	{
		int i, mini;

		mini = x[0];

		for(i=1; i < n; i++)
			if (mini > x[i])
				mini = x[i];
			
		return mini;
	}
	
	/* function MAX, returns the maximum element in x[n] */
	int MAX(int x[], int n)
	{
		int i, maxi;

		maxi = x[0];

		for(i=1; i < n; i++)
			if (maxi < x[i])
				maxi = x[i];
			
		return maxi;

	}
	
	/* function DISPLAY, displays x[n] in format '( #, #, ..., #)' */
	void DISPLAY(int x[], int n)
	{
		int i;

		printf("(");
		for(i=0; i < n; i++)
		{
			printf(" %d",x[i]);
			if (i < n-1)
				printf(",");
		}
		printf(") \n");
	}


	/* function ADD2ARRAYS, add the corresponding elements of x[n] and y[n] */
	/* and store in z[]*/
	void ADD2ARRAYS( int x[], int y[], int z[], int n)
	{
		int i;
		
		for(i=0; i < n; i++)
			z[i] = x[i] + y[i];
	}
	
	/* function PRODUCT, returns the sum of the product of corresponding */
	/* elements of x[n] and y[n] */
	int PRODUCT(int x[], int y[], int n)
	{
		int i, prod=0;
		
			for(i=0; i < n; i++)
				prod += x[i] * y[i];
		
		return prod;
	}
	
	/* function CHOOSE, chooses elements in x[n] that are greater */
	/* than 3, stores them in y[n], and sets the rest of the */
	/* elements in y[n] to zero */
	void CHOOSE(int x[], int n, int threshold, int y[])
	{
		int i, j=0;
		
			for(i=0; i < n; i++)
				y[i] = 0;

			for(i=0; i < n; i++)
				if(x[i] > threshold)
				{
					y[j] = x[i];
					j++;
				}
				
	}