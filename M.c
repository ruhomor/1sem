#include <stdio.h>

int	main()
{
	unsigned short int a;
	unsigned int res;
	unsigned int b;
	unsigned int c;
	unsigned int d;

	b = 1;
	c = 1;
	d = 1;
	res = 1;
	scanf("%hu", &a);
	while (a-- >= 3)
	{
		d = res;
		res += b + c;
		b = c;
		c = d;
	}
	printf("%u", res);
	return (0);
}
