#include <unistd.h>

char	getcha(void)
{
	char	c;

	read(0, &c, 1);
	return (c);
}

int	main()
{
	char			c;
	unsigned long long int	res;

	c = getcha();
	res = 0;
	while (c >= '0' && c <= '9')
	{
		res += c - '0';
		c = getcha();
	}
	if (res % 3 == 0)
		write(1, "YES", 3);
	else
		write(1, "NO", 2);
	return (0);
}
