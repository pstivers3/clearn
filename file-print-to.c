#include <stdio.h>

main()
{
	FILE *fptr;
	char  d[20];

	fptr = fopen("dummy.txt", "w");
    printf("enter string:   "); 
	fprintf(fptr,"enter string:   "); 
	scanf("%s", d);
	fprintf(fptr,"%s\n", d);
	printf("%s\n", d);
	fprintf(fptr,"%s\n", d);
	fclose(fptr);
	return 0;
}


