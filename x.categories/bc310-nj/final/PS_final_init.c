/*	BC-310, PS_final_init.c, Paul Stivesr, 5/14/00 
	Program to write initial data to a random access binary file
	for input to PS_final.c 
*/

#include <stdio.h>
#define SIZE 10

main()
{
	/* Declare structure, type is customer */
	typedef struct customer {
		char name[30];
		int account_id;
		int pin;
		float balance;
	} customer;
	
	/* Initialization data */
	customer initial[SIZE] = {
		{"Person_1", 1, 1001, 500.00},
		{"Person_2", 2, 2002, 500.00},
		{"Person_3", 3, 3003, 500.00},
		{"Person_4", 4, 4004, 500.00},
		{"Person_5", 5, 5005, 500.00},
		{"Person_6", 6, 6006, 500.00},
		{"Person_7", 7, 7007, 500.00},
		{"Person_8", 8, 8008, 500.00},
		{"Person_9", 9, 9009, 500.00},
		{"Person_10", 10, 1010, 500.00}};

	int i;
	
	/* Assign pointer fp to file */
	FILE *fp;	   
	
	/* Open file, and error trap for file not able to open */
	if ((fp= fopen("atm.dat", "wb")) == NULL) 	 
		printf("File could not be opened\n");		
	/* Write data to file */
	else {
    	for(i = 0; i < SIZE; i++)
			fwrite(&initial[i], sizeof(customer),1, fp);
	}
	/* Close file */
	fclose(fp);

	return 0;
}

