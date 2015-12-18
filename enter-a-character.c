#include <stdio.h>

main()
{
	
	char str[10], dummy[10] ;
	
    do
	{
		printf("enter a character:   ");
		scanf("%c", &str[0]);
		printf("Character is %c\n", str[0]);
		scanf("%c", &dummy[0]);	
		
	}
	while (str[0] != 'y' && str[0] != 'Y');

return 0;
}
