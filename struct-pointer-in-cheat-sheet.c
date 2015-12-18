/* struct pointer in cheat sheet */

/* not working */

#include <stdio.h>

int main(void){
   
	
	struct point{
		int x;
		int y;
	}pt, *ppt;

	ppt=&pt;
	ppt->x = 2;
	(*ppt).y = 3;
	
	printf("%d,%d\n", ppt->x, (*ppt).y);  // prints 2,3
	

	return 0;
}