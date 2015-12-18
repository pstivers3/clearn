#include <stdio.h>

main()
{
	FILE *fptr;

	fptr = fopen("output.txt", "w");
    
	fprintf(fptr,"First entry"); 
	
	fclose(fptr);
	fptr = fopen("output.txt", "w");
	fprintf(fptr,"Second Entry");
	fclose(fptr);

	return 0;
}


