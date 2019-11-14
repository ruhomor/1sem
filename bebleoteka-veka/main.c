#include <stdio.h>
#include "meme.h"

int	main()
{
	int	a, b;

	scanf("%d%d", &a, &b);
	printf("summa:%d minimum:%d proizvedenie:%d\n cos(a):%f sin(b):%f\n", summa(a, b), minimum(a, b), multi(a, b), cos(a), sin(b));
	return (0);
}
