/*  BC-310, Midterm, Paul Stivers, 3/25/00

	Program features:
	- user inputs number of students (1-50) and number of exams (1-10)
	- user inputs rows of data: student_ID  Exam_1  Exam_2 ..., prompt 
	  for data scales to number of students and number of exams.
	- program checks for data out of range, prints 'out of range ...' 
	  error messages as appropriate, and prompts to 'try again'.
	- program outputs student_ID and exam data and prompts user to verify
	  data.  If user answers data incorrect, program allows user to re-enter
	  data.
	- program calculates and outputs the following to display
	  and to 'output.txt'.
		.  average score for each exam
		.  number of scores above and below the average for each exam
		.  the average score for each student, final grade for each student, 
		   and the grade distribution.
	- program prints output data to a text file.

	Program strategy:	Store student IDs in a one dimensional array, store 
						exam scores in a two dimensional array.

*/

#include <stdio.h>
#define SIZE_S 50
#define SIZE_E 10
/* declare pointer to a file for data output */
FILE *fp;

void DATA_IN(int, int, int[], int[][SIZE_E]);
void DATA_OUT(int, int, int[], int[][SIZE_E]);
void EXAM_AVG(int, int, float[], int[][SIZE_E]);
void ABOVE_BELOW(int, int, float[], int[], int[], int[][SIZE_E]);
void STUDENT_GRADES(int, int, int[], float[], int[][SIZE_E]);

main()
{
	int sz_students, sz_exams, id[SIZE_S], data[SIZE_S][SIZE_E],
		count_above[SIZE_S], count_below[SIZE_S], check_data = 0;
	float ex_avg[SIZE_E], student_avg[SIZE_S]; 
	
	/* do while loop for user to varify that data is correct */
	do
	{	
		/* do while loop to input number of students and check for number */
		/* outside range */
		do
		{
			printf("Input the number of students in the class (1-50):   ");
			scanf("%d",&sz_students);
			if (sz_students < 1 || sz_students > 50)
				printf("Number of students outside of range 1-50.  "
					"Try again.\n");
		}
		while(sz_students < 1 || sz_students > 50);

		/* do while loop to input number of exams and check for number */
		/* outside range */
		do
		{
			printf("Input the number of exams (1-10):   ");
			scanf("%d",&sz_exams);
			if (sz_exams < 1 || sz_exams > 10)
				printf("Number of exams outside of range 1-10.  "
					"Try again.\n");
		}
		while(sz_exams < 1 || sz_exams > 10);

	
		/* input student ID and test score data */
		DATA_IN(sz_students, sz_exams, id, data);

		/* output student ID and test score data to display, */
		/* and to output.tx */
		/* open file for data output */
		fp = fopen("output.txt", "w");
		DATA_OUT(sz_students, sz_exams, id, data);

		/* prompt user to check for data correctness */
		printf("Is data correct (1 = yes, any other number = no)?   ");
		scanf("%d", &check_data);
		/* if user doesn't varify data by inputing 1, fclose, followed by */
		/* fopen "w" the next time through the while loop, overwrites the
		/*  bad datain the file */
		if (check_data != 1){
			printf("\nRe-enter data:\n");
			fclose(fp);
		}
	}
	/* if user doesn't varify data by inputing 1, the while loop continues */
	while(check_data != 1);

	/* calculate and output the average score for each exam */
	EXAM_AVG(sz_students, sz_exams, ex_avg, data);	
	/* calculate and output the number of scores above and below the */
	/* average for each exam */
	ABOVE_BELOW(sz_students, sz_exams, ex_avg,  count_above, 
		count_below, data);
	/* function call to output the average score for each student, final */
	/* gradefor each student, and the grade distribution */
	STUDENT_GRADES(sz_students, sz_exams, id, student_avg, data);
	
	/* close data output file */
	fclose(fp);
	
	return 0;
}

/* scan in student IDs and exam scores */
void DATA_IN(int in_sz_students, int in_sz_exams, int in_id[SIZE_S], 
			 int in_data[][SIZE_E])
{
	int i, j, range_check_id, range_check_score;
	
	
	/*  Print prompt for data input, scalable to number of exams */
	printf("\nInput student ID (1-9999) and test scores (0-100):\n");
	
	printf("\nInput:  Student_ID");	
	for (j=0; j < in_sz_exams; j++)
		printf("   Exam_%d", j+1);
	printf("\n\n");

	/* scan in id and scores.  If out of range, set range_check = 1. */
	do
	{
		/* scan in id */
		for(i=0; i<in_sz_students; i++)
		{
			range_check_id = 0;
			range_check_score = 0;
			printf("Row %d:   ", i+1);
			scanf("%d", &in_id[i]);
			if(in_id[i] < 0 || in_id[i] > 9999)
				range_check_id = 1;
			
			/* scan in scores */
			for(j=0; j < in_sz_exams; j++)
			{
				scanf("%d",&in_data[i][j]);
				if(in_data[i][j] < 0 || in_data[i][j] > 100)
					range_check_score = 1;
			}

			/* if range_check == 1 print error message */
			if (range_check_id == 1)
				printf("ID is outside range 0-9999.  Try again.\n");
			if (range_check_score == 1){
				printf("One or more scores is outside range 0-100.  "
					"Try again.\n");
			}

			/* if range_check == 1, decrament i to overwrite last row */
			if(range_check_id == 1 || range_check_score == 1)
				i--;
		}
	}
	/* if any data out of range, while loop continues for re-input of row */
	while(range_check_id == 1 || range_check_score == 1); 
}

/* output student IDs and exam scores to display and to output.txt */
void DATA_OUT(int out_sz_students, int out_sz_exams, int out_id[SIZE_S], 
			  int out_data[][SIZE_E])
{
	int i,j;
	
	/* print number of students */
	printf("\nNumber of Students:  %d\n\n", out_sz_students);
	fprintf(fp,"\nNumber of Students:  %d\n\n", out_sz_students);

	/*  Print table header, scalable to number of exams */
	printf("  ID  ");
	fprintf(fp,"  ID  ");
	for (j=0; j < out_sz_exams; j++){
		printf("   Exam_%d", j+1);
		fprintf(fp,"   Exam_%d", j+1);
	}
	printf("\n");
	fprintf(fp,"\n");

	/* print student ID */
	for(i=0; i < out_sz_students; i++)
	{
		/* print scores */
		printf("%4d", out_id[i]);
		fprintf(fp,"%4d", out_id[i]);
		for(j=0; j < out_sz_exams; j++){
			printf("%9d", out_data[i][j]);
			fprintf(fp,"%9d", out_data[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
}

/* calculate and output the average score for each exam, to display and */
/* to output.txt */
void EXAM_AVG(int students, int exams, float avg[SIZE_E], int score[][SIZE_E])
{
	int i, j, sum_exam;
	
	printf("\nThe average on each exam:\n");
	fprintf(fp,"\nThe average on each exam:\n");
	for(j=0; j<exams; j++)
	{
		sum_exam = 0;
		
		for (i=0; i<students; i++)
			sum_exam += score[i][j];
		
		printf("Exam%d: %10.2f\n", j+1, avg[j] = (float) sum_exam/students);	
		fprintf(fp,"Exam%d: %10.2f\n", j+1, 
			avg[j] = (float) sum_exam/students);	
	}
}

/* calculate and output the number of scores above and below the */
/* average for each exam, to display and to output.txt */
void ABOVE_BELOW(int ab_sz_students, int ab_sz_exams, float ab_ex_avg[SIZE_E], 
				 int c_above[SIZE_S], int c_below[SIZE_S], int test[][SIZE_E])
{
	int i, j;

	printf("\nNumber of grades above/below the average:\n");
	fprintf(fp,"\nNumber of grades above/below the average:\n"); 
	for(j=0; j<ab_sz_exams; j++)
	{
		c_above[j] = 0;
		c_below[j] = 0;
		
		for (i=0; i<ab_sz_students; i++)
		{
			if (test[i][j] > ab_ex_avg[j])
				c_above[j]++;			
			if (test[i][j] < ab_ex_avg[j])
				c_below[j]++;
		}
	
		printf("Exam%d:%9d/%d\n", j+1, c_above[j], c_below[j]);	
		fprintf(fp,"Exam%d:%9d/%d\n", j+1, c_above[j], c_below[j]);
	}
}

/* output the average score for each student, final grade for each student, */
/* and the grade distribution */ 
void STUDENT_GRADES(int g_sz_students, int g_sz_exams, int g_id[SIZE_S],
					float g_student_avg[SIZE_S], int g_data[][SIZE_E])
{
	int i, j, sum;
	int Aplus=0, A=0, Bplus=0, B=0, Cplus=0, C=0, Dplus=0, D=0, F=0;

	printf("\nOverall Student Grades:\n");
	fprintf(fp,"\nOverall Student Grades:\n");

	/* calculate average exam score for each student */
	for (i=0; i<g_sz_students; i++)
	{
		sum = 0;
		for(j=0; j<g_sz_exams; j++)
			sum += g_data[i][j];
		g_student_avg[i] = (float) sum/g_sz_exams;
	
		/* assign grade */
	
		if (g_student_avg[i] >= 97.0){
			printf("%d%10.2f   A+\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   A+\n", g_id[i], g_student_avg[i]);
			Aplus++;
		}
		else if (g_student_avg[i] >= 90.0){
			printf("%d%10.2f   A\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   A\n", g_id[i], g_student_avg[i]);
			A++;
		}
		else if (g_student_avg[i] >= 87.0){
			printf("%d%10.2f   B+\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   B+\n", g_id[i], g_student_avg[i]);
			Bplus++;
		}
		else if (g_student_avg[i] >= 80.0){
			printf("%d%10.2f   B\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   B\n", g_id[i], g_student_avg[i]);
			B++;
		}
		else if (g_student_avg[i] >= 77.0){
			printf("%d%10.2f   C+\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   C+\n", g_id[i], g_student_avg[i]);
			Cplus++;
		}
		else if (g_student_avg[i] >= 70.0){
			printf("%d%10.2f   C\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   C\n", g_id[i], g_student_avg[i]);
			C++;
		}
		else if (g_student_avg[i] >= 67.0){
			printf("%d%10.2f   D+\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   D+\n", g_id[i], g_student_avg[i]);
			Dplus++;
		}
		else if (g_student_avg[i] >= 60.0){
			printf("%d%10.2f   D\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   D\n", g_id[i], g_student_avg[i]);
			D++;
		}
		else{
			printf("%d%10.2f   F\n", g_id[i], g_student_avg[i]);
			fprintf(fp,"%d%10.2f   F\n", g_id[i], g_student_avg[i]);
			F++;
		}
	}

	/* print distribution of number of students in each letter grade */
	printf("\nGrade Distribution\n\n");
	fprintf(fp,"\nGrade Distribution\n\n");
	printf("A+%5d\nA %5d\nB+%5d\nB %5d\nC+%5d\nC %5d\nD+%5d\nD %5d\nF %5d\n", 
		Aplus, A, Bplus, B, Cplus, C, Dplus, D, F);
	fprintf(fp,"A+%5d\nA %5d\nB+%5d\nB %5d\nC+%5d\nC %5d\nD+%5d\nD %5d\n"
		"F %5d\n", Aplus, A, Bplus, B, Cplus, C, Dplus, D, F);

}