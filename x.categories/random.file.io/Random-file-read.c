/* Random file read */

#include <stdio.h>

main()
{
	struct account{
		int id;
		char name[30];
		float balance;
	} customer;
	
	FILE *fp;	   
	if ((fp= fopen("customer.dat", "r")) == NULL) 	 
		printf("File could not be opened\n");		
	else {
      	  
	while (!feof(fp)) {
		fread(&customer, sizeof(struct account),1, fp);
 		if(customer.id !=0)
			printf("%-6d%-10s%.2f\n", customer.id, customer.name, 
				customer.balance);
	}
    fclose(fp); 	
}
   return 0;
}

