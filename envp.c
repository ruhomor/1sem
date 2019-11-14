#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		int i = 0;
		argc = atoi(argv[1]);
		while (i < argc)
			printf("%s", envp[i++]);
	}
	return (0);
}
