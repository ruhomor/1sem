#include <stdio.h>

int	main()
{
	short int	n;
	long long int	res;
	int		a;
	int		i;

	scanf("%hd", &n);
	res = 0;
	i = 0;
	while (i < n)
	{
		scanf("%d", &a);
		if (i++ % 2)
			res -= a;
		else
			res += a;
	}
	printf("%lld", res);
	return (0);
}
