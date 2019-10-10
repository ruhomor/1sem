#include <stdio.h>

int	main()
{
	int	n;
	int	num;
	int	a;
	int	res;

	res = 0;
	scanf("%d", &num);
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		if (a == num)
			res++;
	}
	printf("%d", res);
	return (0);
}
