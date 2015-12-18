/* Using strerror */
#include <stdio.h>
#include <string.h>

main()
{
	int i;
	char ans, return_absorb;
   	
	printf("Error\nNumber   Message\n");
	
	for (i=0; i<=100; i++)
	{
	 	printf("%4d     %s\n", i, strerror(i));
		if (i > 1 && i%20 == 0)
		{
			printf("Want 20 more ? (yes = y, no = any other key):");
			scanf("%c%c", &ans, &return_absorb);
			if (ans != 'y' && ans != 'Y')
				i = 600;
		}	
	}
		return 0;
}

