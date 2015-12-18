/* struct in cheat sheet */

#include <stdio.h>

/*  General structure layout */  

/*
  struct struct_type{
		type member1;
		type member2;
		...
	} struct_variable1, struct_variable2, ...;

		// declare another variable
	struct struct_type variable3;  
		
		// typedef struct_type to typedef_type
	typedef struct struct_type typedef_type;
		// declare another variable using typedef_type this time
	typedef_type variable4;

*/

int main(void){
   
	struct coord{
		int x;
		int y;
	} pt1, pt2;

	struct coord pt3;
	
	typedef struct coord point;
	
	point pt4;

	pt1.x = 2;
	pt1.y = 3;
	pt2.x = 5;
	pt2.y = 6;
	pt3.x = 10;
	pt3.y = 11;
	pt4.x = 12;
	pt4.y = 13;

	printf("%d\n", pt1.y);  // prints 3
	printf("%d\n", pt3.x);	// prints 10
	printf("%d\n", pt4.y);	// prints 13;

	return 0;
}