/*  Ex2.3.2 */

/* caution, risky to run.  May tie up memory.  Will run continuous loop.
   causes a lot of disk activity */

#include <stdio.h>

void P(void);

int main(void){
	P();
	return 0;
}

void P(void){
	typedef int BigArray[1000];
	BigArray *A;

	while ((A = (BigArray *)malloc(sizeof(BigArray))) != NULL){
		;
	}
	
	printf("storage allocation failure occured");
}

/* didn't print message */