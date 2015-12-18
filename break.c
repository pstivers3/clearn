#include <stdio.h>
main ()

{
int grade;
int acount=0, bcount=0, ccount=0, dcount =0, fcount=0;

printf("Enter the letter grades, or EOF to end input.\n");

while ( (grade = getchar() ) != EOF) {

	switch (grade)	{

	case 'A': case 'a':
		++acount;
		break;

    case 'B': case 'b':
		++bcount;
		break;

	case 'C': case 'c':
		++ccount;
		break;

	case 'D': case 'd':
		++dcount;
		break;

	case 'F': case 'f':
		++fcount;
		break;

	case '\n': case ' ':
		break;

	default:
		printf("Incorrect letter grade entered.  Enter a new grade.\n");

	
	}
}

printf("\nTotals for each letter grade are:\n");
printf("A: %d\n", acount);
printf("B: %d\n", bcount);
printf("C: %d\n", ccount);
printf("D: %d\n", dcount);
printf("F: %d\n", fcount);

return 0;

}