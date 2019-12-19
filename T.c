#include <stdio.h>

void	getArr(int a[], int n)
{
	int i;

	for (i=0; i < n; i++)
	{
		scanf("%d", & a[i]);
	}
}

int	main()
{
	int y, sum = 0, t[3][3];

	for (y = 0; y < 3; y++)
	{
		getArr(t[y], 3);
	}
	y = 0;
	while (y < 3)
	{
		sum += t[y][y];
		y++;
	}
	printf("%d", sum);
	return 0;
}
