/*  Ex2.3.1 */

#include <stdio.h>

void P(void);

typedef int *IntegerPointer;
IntegerPointer A;
IntegerPointer B;

int main(void){
	P();
	return 0;
}

void P(void){
	
	A = (IntegerPointer)malloc(sizeof(int));
	B = (IntegerPointer)malloc(sizeof(int));
	*A = 19;
	*B = 5;
	A = B;
	*B = 7;
	printf("%d\n",*A);
}

/* Prints 7 */