#include <stdio.h>

float sqr(float);

main()
{
	float x, x_squared;

	x = 2.5;
	x_squared = sqr(x);
		printf("%f squared = %f\n", x, x_squared);
	return 0;
}

float sqr(float y)
{
	return y*y;
}
