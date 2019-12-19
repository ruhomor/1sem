#include <stdio.h>
#include <string.h>

union			u
{
	char		data[sizeof(long double)];
	float		fl;
	double		db;
	long double	ldb;
};

void			printnum(int sizebyte, char *data)
{
	int		curbit;
	int		four;

	while (sizebyte--)
	{
		curbit = 128;
		four = 0;
		while (curbit)
		{
			if (data[sizebyte] & curbit)
				printf("%c", '1');
			else
				printf("%c", '0');
			curbit >>= 1;
			four++;
			if (four == 4)
				printf(" ");
		}
		printf(" ");
	}
}

int			main()
{
	union u		sov;
	int		sizebyte;
	char		t[7];

	t[6] = '\0';

	scanf("%s", t);

	if (strcmp(t, "float") == 0)
	{
		scanf("%f", &sov.fl);
		sizebyte = sizeof(float);
		printnum(sizebyte, sov.data);
	}
	if (strcmp(t, "double") == 0)
	{
		scanf("%lf", &sov.db);
		sizebyte = sizeof(double);
		printnum(sizebyte, sov.data);
	}
	if (strcmp(t, "long") == 0)
	{
		scanf("%s", t);
		sizebyte = sizeof(long double);
		while (sizebyte--)
		{
			sov.data[sizebyte] = 0;
		}
		scanf("%Lf", &sov.ldb);
		sizebyte = sizeof(long double);
		printnum(sizebyte, sov.data);
	}
	return (0);
}
