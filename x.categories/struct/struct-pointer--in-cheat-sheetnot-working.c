/* struct pointer in cheat sheet */

/* not working */

#include <stdio.h>

int main(void){
   
	struct coord{
		int x;
		int y;
	} *pt1;

	(pt1)->x = 2;
	
	//printf("%d\n", pt1->x);  // prints 3
	

	return 0;
}