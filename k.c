#include <stdio.h>

int	main()
{
	int	a;
	int	res;

	res = 0;
	scanf("%d", &a);
	while (a / 2 != 0)
	{
		res += a % 2;
		a /= 2;
	}
	res += a % 2;
	printf("%d", res);
	return (0);
}
