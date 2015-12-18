#include <stdio.h>
#include <string.h>

main()
{
	char *str = "abc";
	printf("%s\n", str);
	printf("%c\n", *str);
	str = "klm";
	printf("%s\n", str);	
	printf("%s\n", str+1);
	return 0;
}

