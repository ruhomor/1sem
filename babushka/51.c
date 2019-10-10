#include <stdio.h>

int	main()
{
	int k, a[14], n = 14, c, i = 0, j;

	while (i < n)
		scanf("%d", &a[i++]);
	i = 0;
	while (i < n)
	{
		j = i;
		k = i;
		while (j < n)
		{
			if (a[j] < a[k])
				k = j;
			j++;
		}
		c = a[i];
		a[i++] = a[k];
		a[k] = c;
	}
	i = 0;
	while (i < n)
		printf("%d ", a[i++]);
	return (0);
}
