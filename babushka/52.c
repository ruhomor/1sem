#include <stdio.h>

int	main()
{
	int k, a[14], n = 14, x, i = 0, j = 0;

	scanf("%d", &k);
	while (i < n)
		scanf("%d", &a[i++]);
	i = k;
	while (i < n)
	{
    		x = a[i];
    		j = i;
    		while (j > 0 && a[j - 1] > x)
		{
        		a[j] = a[j - 1];
        		j--;
    		}
    		a[j] = x;
		i++;
	}
	i = 0;
	while (i < n)
		printf("%d ", a[i++]);
	return (0);
}
