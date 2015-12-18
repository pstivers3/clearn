/*  Ex2.3.2 */

#include <stdio.h>

void P(void);

int main(void){
	P();
	return 0;
}

void P(void){
	int *A, *B;
	A = (int *)malloc(sizeof(int));
	B = (int *)malloc(sizeof(int));
	*A = 19;
	*B = 5;
	*A = *B;
	*B = 7;
	printf("%d\n",*A);
}

/* Prints 7 */