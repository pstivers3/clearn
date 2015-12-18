/*  BC-310, Final, Paul Stivers, 5/14/00 

	Program features:

	-   Program reads intial data from atm.dat.  Source code to generate
		atm.dat is contained in PS_final_init.c.  Initial data is:
	   
		 Name      Acct_ID   PIN       Balance
		Person_1      1      1001      500.00
		Person_2      2      2002      500.00
		Person_3      3      3003      500.00
		Person_4      4      4004      500.00
		Person_5      5      5005      500.00
		Person_6      6      6006      500.00
		Person_7      7      7007      500.00
		Person_8      8      8008      500.00
		Person_9      9      9009      500.00
		Person_10    10      1010      500.00

	-  User inputs account ID and PIN.
		o  Program validates account ID and PIN.
		o  If validation fails 3 times, program asks customer to contact a 
		   bank representative, and exits the program.
		o  If account ID = 0 and PIN = 9999, program prints a list of name,
		   account ID, PIN, and final Balance; then exits.
	-  Program provides 5 choices:  
		1.  Deposit.  
			o	Error checks for deposit amount <= 0.  If 3 input failures,
				program asks customer to contact a bank representative, 
				exits out of routine, re-prints choices, and allows customer
				to re-select a choice.
		2.  Withdraw.
			o	Error checks for withdraw amount <=0 or > 300 or > balance.  
				If 3 input failures, program asks customer to contact a bank
				representative, exits out of routine, re-prints	choices,
				and allows customer to re-select a choice.
		3.  Balance.
			o   Prints the current balance.
		4.  Transfer.
			o   Error checks for withdraw amount <=0 or > 300 or > balance.  
				If 3 input failures, program asks customer to contact a bank
				representative, exits out of routine, re-prints	choices,
				and allows customer to re-select a choice.
		5.  Exit.
			o   Exits choices, and allows customer to input a new account ID,
				and PIN.
	-   After each transaction, program prints the transaction amount, 
	    balance before transaction, and balance after transaction.
*/


#include <stdio.h>
#define SIZE 10
#define ALLOW 3


/* Declare structure, type is customer */
typedef struct customer {
	char name[30];
	int account_id;
	int pin;
	float balance;
} customer;

/* Function prototypes */
void ReadData(customer []);
int Validate(customer [], int, int, int);
void Deposit(customer [], int);
void Withdraw(customer [], int);
void Balance(customer [], int);
void Transfer(customer [], int);
void Print(customer [], int);

int main(void)
{
	int acct_num, pin, valid, choice, fail_valid = 0;
	customer account[SIZE];

	printf("Welcome to ATM\n");
	
	/* Call function to read intial data */
	ReadData(account);
	
	/* Do while not (account ID = 0 and PIN = 9999) and validation
	   fails < 3 */
	do{
		fail_valid = 0;
		/* Input account number and PIN and trap input errors */
		do{
			/* User input account number and PIN */
			printf("\n(Account Number 0 and PIN 9999 to end.)\n");
			printf("Enter Account Number:  ");
			scanf("%d", &acct_num);
			printf("Enter Pin Code:   ");
			scanf("%d", &pin);
			/* Exit loop if account number 0 and PIN 9999 */
			if(acct_num == 0 && pin == 9999)
				break;
			/* Validate account number and PIN */
			valid = Validate(account, SIZE, acct_num, pin);
			
			/* Trap invalid account number or PIN */
			if(valid == 0){
				printf("Invalid Account Number or Pin, Try Again.\n\n");
				/* Count number of failed validations */
				fail_valid++;
			}
			else 
				printf("Customer is validated\n");
		}  
		while (valid == 0 && fail_valid < ALLOW);
		
		/*  If validation fails more than ALLOW, or (account number 0 and
		    PIN 9999), next do-while loop is skipped */
		if(fail_valid < ALLOW && !(acct_num == 0 && pin == 9999)){
		
			/* Do while choice not equal 5 */
			do{
				/*  User input choice */
				printf("\n1 = Deposit\n2 = Withdraw\n3 = Balance\n"
					"4 = Transfer\n5 = Exit\n\nEnter your choice (1-5):   ");
				scanf("%d", &choice);
			
				/* Error trap for choice outsid of range 1-5 */
				do{		
					if(choice < 1 || choice > 5){
						printf("Choice was outside of range 1-5.  "
							"Try again.\n\nEnter your choice (1-5):   ");
						scanf("%d", &choice);
					}
				}
				while(choice < 1 || choice > 5);
		
				/*  Use switch to call appropriate function for choice */
				switch(choice){
					case 1:  Deposit(account, acct_num);
						break;
					case 2:  Withdraw(account, acct_num);
						break;
					case 3:  Balance(account, acct_num);
						break;
					case 4:  Transfer(account, acct_num);
						break;
					default:
						break;
				}
			}
			while(choice != 5);
		}
	}
	while(fail_valid < ALLOW && !(acct_num == 0 && pin == 9999) );
	
	if(fail_valid >= ALLOW && !(acct_num == 0 && pin == 9999))
		printf("Sorry you are having trouble.\n"
				"Please contact a bank representative for help.\n");

	if(acct_num == 0 && pin == 9999)
		Print(account, SIZE);
		
	return 0;
}

/********************* Begin Functions ****************************/

/*  Function to Read initial data */
void ReadData(customer acct_read[])
{
	int i;
	
	/*  Assign pointer fp to file */
	FILE *fp;	   
	
	/*  Open file and error trap for file not able to open */
	if ((fp= fopen("atm.dat", "rb")) == NULL) 	 
		printf("File could not be opened\n");		
	else {
      	/*  Read data from file */  
		for(i = 0; i < SIZE; i++){
			fread(&acct_read[i], sizeof(customer),1, fp);
		}
	
	}
	/* Close file */
	fclose(fp);
	return;
}

/*  Function to validate account number and PIN */
int Validate(customer accnt_val[], int sz_val, int num_val, int pin_val)
{
	int i;

	for(i = 0; i < SIZE; i++)
		/*  If account number and PIN match those in one of the records, 
		    return 1 and exit function */
		if(accnt_val[i].account_id == num_val  &&  
			accnt_val[i].pin == pin_val)
			return 1;
	/*  If none of the records has matching account number and PIN, 
		return 0. */
	return 0;
}

/*  Funtion to deposit money in the current account. */
void Deposit(customer acct_dep[], int num_dep)
{
	/* fail_cnt counts input errors for deposit amount */
	/* fail_amount is a boolean flag for error deposit amount <= 00.00 */
	int fail_cnt = 0, fail_amount;
	float amount_dep;
	
	/*  Input deposit amount and trap input errors */
	do{
		fail_amount = 0;
		
		printf("Enter Deposit Amount (000.00):   ");
		scanf("%f", &amount_dep);
		printf("\nDeposit amount is %.2f\n", amount_dep);
		if(amount_dep <= 0.00){
			printf("Amount you requested is less than or equal to "
				"00.00\n");
			fail_amount = 1;
		}
		if(fail_amount == 1)
			fail_cnt++;
		if(fail_amount == 1 && fail_cnt < ALLOW)
			printf("Try Again.\n\n");
	}
	while(fail_amount == 1 && fail_cnt < ALLOW);

	/* If fail count < ALLOW, calculate and report new balance */
	if(fail_cnt < ALLOW){
		printf("Balance before deposit is %.2f\n", 
			acct_dep[num_dep -1].balance);
		acct_dep[num_dep -1].balance += amount_dep;
		printf("Balance after deposit is %.2f\n", 
			acct_dep[num_dep -1].balance);
	}
	else 
		printf("Sorry you are having trouble.  "
			"Please contact a bank representative for help.\n");
}

/*  Funtion to withdraw money from the current account. */
void Withdraw(customer acct_wit[], int num_wit)
{
	/* fail_cnt counts input errors for withdraw amount */
	/* fail_amount is a boolean flag for error withdraw amount > 300 */
	/* or > balance or <= 0.00 */
	int fail_cnt = 0, fail_amount;
	float amount_wit;
	
	
	/*  Input withdraw amount and trap input errors */
	do{
		fail_amount = 0;
		
		printf("Enter Withdraw Amount (up to 300.00):   ");
		scanf("%f", &amount_wit);
		printf("\nWithdraw amount is %.2f\n", amount_wit);
		if(amount_wit > 300.00){
			printf("Amount you requested is over $300.00\n");
			fail_amount = 1;
		}
		if(amount_wit <= 0.00){
			printf("Amount you requested is less than or equal to "
				"00.00\n");
			fail_amount = 1;
		}		
		if(amount_wit > acct_wit[num_wit -1].balance){
			printf("Amount you requested is greater than your balance.\n");
			fail_amount = 1;
		}
		if(fail_amount == 1)
			fail_cnt++;
		if( fail_amount == 1 && fail_cnt < ALLOW)
			printf("Try Again.\n\n");
	}
	while( fail_amount == 1 && fail_cnt < ALLOW);
	
	/* If fail count < ALLOW, calculate and report new balance */
	if(fail_cnt < ALLOW){
 		printf("Balance before withdrawal is %.2f\n", 
			acct_wit[num_wit -1].balance);
		acct_wit[num_wit -1].balance -= amount_wit;
		printf("Balance after withdrawal is %.2f\n", 
			acct_wit[num_wit -1].balance);
	}
	else
		printf("Sorry you are having trouble.  "
			"Please contact a bank representative for help.\n");
	
	return;
}

/* Function to print balance */
void Balance(customer acct_bal[], int num_bal)
{
	printf("\nYour balance is %.2f\n", acct_bal[num_bal-1].balance);
	return;
}

/* Function to transfer money from current account to another account */
void Transfer(customer acct_tfr[], int num_send)
{
	/* num_rec is account number of receiving account */
	/* fail_num counts input errors for receiving account number outside */
	/* of range 1-10 */
	/* fail_cnt counts input errors for transfer amount */
	/* fail_amount is a boolean flag for error transfer amount > 300 */
	/* or > balance or <= 0.00 */
	int num_rec, fail_num = 0, fail_cnt = 0, fail_amount;
	float amount_tfr;
	
	/* Input receiving account number, and trap input errors */
	do{
		printf("Enter Account Number to transfer to:   ");
		scanf("%d", &num_rec);
		if (num_rec < 1 || num_rec > 10)
			fail_num++;
	}
	while ( (num_rec < 1 || num_rec > 10) && fail_num < ALLOW);
	
	/*  If fail_num < ALLOW, from above do-while loop, execute the */
	/*  the rest of the function */
	if(fail_num < ALLOW){
		/* Input transfer amount and trap input errors */
		do{
			fail_amount = 0;
			
			printf("Enter Transfer Amount (up to 300.00):   ");
			scanf("%f", &amount_tfr);
			printf("\nTransfer Amount is %.2f\n", amount_tfr);
			if(amount_tfr > 300.00){
				printf("Amount you requested is over $300.00.\n");
				fail_amount = 1;
			}
			if(amount_tfr <= 0.00){
				printf("Amount you requested is less than or equal to "
					"00.00\n");
				fail_amount = 1;
			}
			if(amount_tfr > acct_tfr[num_send -1].balance){
				printf("Amount you requested is greater than your "
					"balance.\n");
				fail_amount = 1;
			}
			if(fail_amount == 1)
				fail_cnt++;
			if(fail_amount == 1 && fail_cnt < ALLOW)
				printf("Try Again.\n\n");
		}
		while(fail_amount == 1 && fail_cnt < ALLOW);
	
		/* If input amount errors < ALLOW, calculate and print balance */
		/* before and after transfer in sending and receiving accunts. */
		if(fail_cnt < ALLOW){
			printf("\nBalance in sending account ID %d, before transfer "
				"is  %.2f\n", num_send, acct_tfr[num_send -1].balance);
			acct_tfr[num_send -1].balance -= amount_tfr;
			printf("Balance in sending account ID %d, after transfer "
				"is  %.2f\n", num_send, acct_tfr[num_send -1].balance);
			printf("Balance in receiving account ID %d, before transfer "
				"is  %.2f\n", num_rec, acct_tfr[num_rec -1].balance);
 			acct_tfr[num_rec -1].balance += amount_tfr;
			printf("Balance in receiving account ID %d, after transfer "
				"is  %.2f\n", num_rec, acct_tfr[num_rec -1].balance);
		}
		else
			printf("Sorry you are having trouble.  "
				"Please contact a bank representative for help.\n");
	}
	else
		printf("Sorry you are having trouble.  "
			"Please contact a bank representative for help.\n");
	
	return;
}

/* Function to print list of name, account number, PIN, and balance. */
void Print(customer acct_prt[], int sz_prt)
{
	int i;

	printf("\n   Name      Acct_ID   PIN       Balance\n");
	for(i=0; i<sz_prt; i++)
			printf("  %-10s%5d%10d%12.2f\n", acct_prt[i].name,
				acct_prt[i].account_id, acct_prt[i].pin,
				acct_prt[i].balance);

	return;
}