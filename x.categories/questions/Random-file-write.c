/* Random file write */

#include <stdio.h>

main()
{
	struct account{
		int id;
		char name[30];
		float balance;
	} customer;

	FILE *fp;	   
	if ((fp= fopen("customer.dat", "r+")) == NULL) 	 
		printf("File could not be opened\n");		
	else {
      	  
		printf("Enter customer ID (1 - 10, any other number to end):\n");
		scanf("%d", &customer.id);
		
		while (customer.id >= 1 && customer.id <= 10) {
			printf("Enter Name (no spaces), Balance:\n");
			scanf("%s%f", &customer.name, &customer.balance);
			// printf("%s%f", customer.name, customer.balance); 
			fseek(fp, (customer.id - 1) * sizeof(struct account), SEEK_SET);
			fwrite(&customer, sizeof(struct account), 1, fp);

			printf("Enter customer ID (1 - 10, any other number to end):\n");
			scanf("%d", &customer.id);
		}
		
	}
fclose(fp); 
return 0;
}

/* Gives a runtime error.  But if I un-comment the printf statement, 
recompile, delete that printf statement, and recompile again, there
is not runtime error */