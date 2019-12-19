#include <stdio.h>

void	printArr(int a[], int n) 
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

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
	int y;
	int t[3][3];

	for (y = 0; y < 3; y++)
	{
		getArr(t[y], 3);
	}
	for (y = 0; y < 3; y++)
	{
		printArr(t[y], 3);
	}
	return 0;
}
