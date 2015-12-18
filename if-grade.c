#include <stdio.h>
main ()

{
int grade =0;
int acount=0, bcount=0, ccount=0, dcount =0, fcount=0;

printf("Enter the letter grades, or EOF to end input.\n");

while ( (grade = getchar() ) != EOF)
{


	if (grade == 'a')
	   ++acount;

	else 
		if (grade == 'b') 
			++bcount;
	else 
		if (grade == 'c') 
			++ccount;
    else 
		if (grade == 'd') 
			++dcount;
    else 
		if (grade == 'f') 
			++fcount;

    else 
		if (grade == '\n', grade == ' ') ;

    else
		printf("Incorrect letter grade entered.  Enter a new grade.\n");

}

printf("\nTotals for each letter grade are:\n");
printf("A: %d\n", acount);
printf("B: %d\n", bcount);
printf("C: %d\n", ccount);
printf("D: %d\n", dcount);
printf("F: %d\n", fcount);

return 0;

}