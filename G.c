#include <stdio.h>

float	f1(float x)
{
	return (1 + x * x);
}

float	f2(float x)
{
	return (-2 - x * x);
}

int	main()
{
	float	x;
	float	y;

	scanf("%f %f", &x, &y);
	if ((y < f1(x)) && (y > f2(x)))
	{
		printf("NO");
		return (0);
	}
	printf("YES");
	return (0);
}
