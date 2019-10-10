#include <unistd.h>

char	getcha(void)
{
	char	c;

	read(0, &c, 1);
	return (c);
}

int	main()
{
	int	open;
	char	c;

	open = 0;
	c = getcha();
	while (c == ')' || c == '(')
	{
		if (open < 0)
		{
			write(1, "NO", 2);
			return (0);
		}
		if (c == ')')
			open--;
		else
			open++;
		c = getcha();
	}
	if (open == 0)
		write(1, "YES", 3);
	else
		write(1, "NO", 2);
	return (0);
}
