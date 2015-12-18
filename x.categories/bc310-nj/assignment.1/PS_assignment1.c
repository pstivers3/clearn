	/*  BC310, Assignment 1 - Grades, Paul Stivers, 2/13/00              */
	/*                                                                   */
	/*  Program features:                                                */
	/*      - Allows for the input of a list of number grades,           */
	/*        terminated by -1.                                          */
	/*      - Determines and prints the letter grade.                    */
	/*      - Error checks for input outside 0-100 but allowing -1.      */	
	/*      - Computes and prints the average grade.                     */
	/*      - Computes and prints the total number of each letter grade. */

	#include <stdio.h>

	main()
	{											
		/* initialize intigers */
		int grade=0, sum=0, count=0,        
			A=0, B=0, C=0, D=0, F=0;
	
		/* input first grade */
		printf("Enter numeric grade, or -1 to end:      "); 
		scanf("%d",&grade);
	
		if (grade == -1)
			printf("\nProgram terminated by -1\n");
	
		/* loop for input of more grades while grade is not -1 */
		while (grade != -1)     
		{					
			/* check for grade out of range 0-100 */
			if (grade < 0 || grade > 100)     
			{
				printf("Number was outside of range 0-100\n");
				printf("Try again.\n");
			}

			/* while grade != -1 and if grade not outside range 0-100   */
			/* (from above conditions), sum up grades, increment grade  */
			/* count, and continue with if/else statements to determine */
			/* letter-grade and incrament letter-grade count.           */
			else						
			{					
				sum += grade;		
				count++;
			
				if (grade >= 90) {					
					printf("Letter grade is A\n"); 
					A++;							
				}	
				else if (grade >= 80) {				
					printf("Letter grade is B\n");
					B++;
				}
				else if (grade >= 70) {
					printf("Letter grade is C\n"); 
					C++;
				}
				else if (grade >= 60) {
					printf("Letter grade is D\n");
					D++;
				}
				else { 
					printf("Letter grade is F\n"); 
					F++;
				}
			}
	
			/* input additional grades from inside loop */
			printf("Enter numeric grade, or -1 to end:      ");	
			scanf("%d",&grade);									

			if (grade == -1)
			printf("\nProgram terminated by -1\n");
		}
	
		/* If no legitimate grades entered, protect against divide by */	
		/* zero, and skip the grade printouts. */
		if (count > 0)  
		            
		{	
			/* calculate and print average grade */
			printf("\nAverage grade = %d\n\n", sum/count);   
			                                           
			/* print total of each letter grade from incramented */
			/* variables */
			printf("Number of A grades = %3d\n", A);	
			printf("Number of B grades = %3d\n", B);	
			printf("Number of C grades = %3d\n", C);
			printf("Number of D grades = %3d\n", D);
			printf("Number of F grades = %3d\n\n", F);
		}
	
		else printf("No legitimate grades entered.\n");

	return 0;

	}