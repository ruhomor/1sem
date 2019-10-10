#include <stdio.h>

int	main()
{
	int	n;
	int	a[14];
	int	i;
	int	j;
	int	raz;
	int	res;
	int	res1;
	int	meme;

	i = 0;
	j = 0;
	res = 0;
	n = 14;
	while (i < n)
		scanf("%d", &a[i++]);
	i = 0;
	while (i - 1 < n)
	{
		raz = a[i] - a[i + 1];
		res1 = 1;
		j = i;
		while (j - 1 < n)
		{
			if (a[j] - a[j + 1] == raz)
				res1++;
			else
				break;
			j++;
		}
		if (res1 > res)
		{
			res = res1;
			meme = j - res + 1;
		}
		i++;
	}
	printf("Длина: %d\n", res);
	while(res--)
		printf("%d ", a[meme++]);
	return (0);
}
