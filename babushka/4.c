#include <stdio.h>

void	swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	cmp(int *a, int *b)
{
	if ((*a < 0) && (*b > 0))
		swap(a, b);
}

int	main()
{
	int	a[14];
	int	j;
	int	i;
	int	n;

	n = 14;
	i = 0;
	while (i < n)
		scanf("%d", &a[i++]);
	i = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			cmp(&a[j], &a[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
		printf("%d ", a[i++]);
	return (0);
}
