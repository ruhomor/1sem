#include <stdio.h>

int	main()
{
	short int	a[999];
	short int	n;
	short int	i;

	scanf("%hd", &n);
	i = 0;
	while (i < n)
	{
		scanf("%hd", &a[i]);
		printf("%hd ", a[i++]);
	}
	i = 0;
	while (i < n)
		printf("%hd ", a[i++]);
	return (0);
}
