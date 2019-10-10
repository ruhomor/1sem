#include <stdio.h>

int	main()
{
	int	x;
	int	y;

	x = 0;
	switch(x) 
	{
		case 0: y = 1;
		case 1: y = 2; break;
		default: y = 3; break;
	}
	printf("%d", y);
	return (0);
}
