#include <stdio.h>

int	main()
{
	int		n;
	short int	flagg;

	flagg = 0;
	scanf("%d", &n);
	while (n)
	{
		if (n % 10 != 0)
			flagg = 1;
		if (flagg == 1)
			printf("%d", n % 10);
		n /= 10;
	}
	return (0);
}
