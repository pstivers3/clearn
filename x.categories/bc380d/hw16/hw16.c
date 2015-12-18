#include <stdio.h>
#define MAX 4

int A[MAX];
int sum(int i);

main()
{
	int i;

	for(i = 0; i < MAX; i++){
		scanf("%d", &A[i]);
		printf("i = %d, A[i] = %d\n", i, A[i]);
	}
	printf("%d\n", sum(0));

	return 0;
}

int sum(int i)
{
	if(i > MAX)
		return 0;
	else
		return A[i] + sum(i+1);
}

/*   Output  

0
i = 0, A[i] = 0
10
i = 1, A[i] = 10
20
i = 2, A[i] = 20
30
i = 3, A[i] = 30
60
Press any key to continue
*/