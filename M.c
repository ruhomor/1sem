#include <stdio.h>

unsigned long long int	f(unsigned long long int x)
{
	if ((x == 0) || (x == 1) || (x == 2))
		return (1);
	return (f(x - 1) + f(x - 2) + f(x - 3));
}

int	main()
{
	unsigned long long int a;
	scanf("%llu", &a);
	printf("%llu", f(a));
	return (0);
}
