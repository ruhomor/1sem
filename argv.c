#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	res = 0;

	while (argc > 1)
		res += atoi(argv[--argc]);
	return (res);
}
