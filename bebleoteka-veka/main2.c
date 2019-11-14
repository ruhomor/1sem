#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char	c;

	fd = open("input", O_RDONLY);
	while(read(fd, &c, 1))
		write(1, &c, 1);
	return (0);
}
