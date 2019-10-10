#include <stdio.h>
#include <math.h>

float	xdistance(float y)
{
	return (sqrtf(((-3) - y) * (-4)));
}

int	main()
{
	float	x;
	float	y;

	scanf("%f %f", &x, &y);
	if (y <= -3)
	{
		printf("YES");
		return (0);
	}
	if (y > 2)
	{
		if (fabs(x) < xdistance(y) / 2)
		{
			printf("YES");
			return (0);
		}
	}
	else
		if (fabs(x) > xdistance(y) / 2)
		{
			printf("YES");
			return (0);
		}
	printf("NO");
	return (0);
}
