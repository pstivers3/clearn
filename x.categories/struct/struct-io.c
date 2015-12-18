/* use struct to output the input lines */

#include <stdio.h>

int main(void){
   
	struct data{
		char str[30];
	} var;
	
	while ( var.str != "EOF" ){    // EOF doesn't work
		scanf("%s", &var.str);	
		printf("%s\n", var.str);
	}

	return 0;
}