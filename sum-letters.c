#include <stdio.h>

	char letter;
	int i, sum = 0;
	
int main(void)
{
	while ((letter = getchar()) != '.')
	{
		if (letter == 'a')
			sum = sum + 1;
		if (letter == 'b')
			sum = sum + 2;
		if (letter == 'c')
			sum = sum + 3;
		if (letter == 'd')
			sum = sum + 4;
		if (letter == 'e')
			sum = sum + 5;
		if (letter == 'f')
			sum = sum + 6;
		if (letter == 'g')
			sum = sum + 7;
		if (letter == 'h')
			sum = sum + 8;
		if (letter == 'i')
			sum = sum + 9;
		if (letter == 'j')
			sum = sum + 10;
		if (letter == 'k')
			sum = sum + 11;
		if (letter == 'l')
			sum = sum + 12;
		if (letter == 'm')
			sum = sum + 13;
		if (letter == 'n')
			sum = sum + 14;
		if (letter == 'o')
			sum = sum + 15;
		if (letter == 'p')
			sum = sum + 16;
		if (letter == 'q')
			sum = sum + 17;
		if (letter == 'r')
			sum = sum + 18;
		if (letter == 's')
			sum = sum + 19;
		if (letter == 't')
			sum = sum + 20;
		if (letter == 'u')
			sum = sum + 21;
		if (letter == 'v')
			sum = sum + 22;
		if (letter == 'w')
			sum = sum + 23;
		if (letter == 'x')
			sum = sum + 24;
		if (letter == 'y')
			sum = sum + 25;
		if (letter == 'z')
			sum = sum + 26;

		if (letter == ' ' || letter == '\n')
		{
			printf("%s%d\n", "  ",sum);	
			sum = 0;
		}
		
		putchar(letter);
	}
	
	return 0;
}

