/* Random file create */

#include <stdio.h>

main()
{
	struct account{
		int id;
		char name[30];
		float balance;
	} initialize = {0, "", 0.0};

	int i;

	FILE *fp;	   
	if ((fp= fopen("customer.dat", "w")) == NULL) 	 
		printf("File could not be opened\n");		
	else {
      	  
		for(i = 1; i <= 10; i++)
			fwrite(&initialize, sizeof(struct account),1, fp);

		}
	fclose(fp);
	return 0;	
}



