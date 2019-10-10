#include <stdio.h>

int	main()
{
	int x = 7, y;
	void *p = &x;

	y = *(int*)p;
	printf("%d", y);
	return (0);
}
