#include <stdio.h>

int	main()
{
	int n, a, size = 0, i, pov = 0, b[1000];

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		i = size;
		while (i--)
		{
			if (b[i] == a)
			{
				pov = 1;
			}
		}
		if (!pov)
		{
			size++;
			b[size - 1] = a;
		}
		pov = 0;
	}
	i = 0;
	while (i < size)
		printf("%d ", b[i++]);
	return (0);
}
