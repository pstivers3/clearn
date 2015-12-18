#include <stdio.h>
#include <string.h>

main()
{
	char string[] = "This is a test", *p = string;
	char *word;
	word = strtok(p," ");

	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}

	return 0;
}

