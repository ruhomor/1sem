#include <stdio.h>

int	pow2(int s)
{
	int	res;

	res = 1;
	while (s)
	{
		res *= 2;
		s--;
	}
	return (res);
}

int	main()
{
	printf("%d", pow2(sizeof(unsigned long long int)));
	return (0);
}
