#include <stdio.h>

int	main()
{
	int dh;
	int dm;
	int ah;
	int am;
	int resh;
	int resm;

	scanf("%d:%d\n%d:%d", &dh, &dm, &ah, &am);
	resh = ah + dh;
	resm = am + dm;
	while (resm >= 60)
	{
		resm -= 60;
		resh++;
	}
	while (resh >= 24)
		resh -= 24;
	printf("%02d:%02d", resh, resm);
	return (0);
}
