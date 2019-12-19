#include <stdio.h>
#include <string.h>

union			fu
{
	char		data[sizeof(float)];
	float		fl;
};

union			du
{
	char		data[sizeof(double)];
	double		db;
};

union			ldu
{
	char		data[sizeof(long double)];
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
	union fu	uf;
	union du	ud;
	union ldu	uld;
	int		sizebyte;
	char		t[7];

	t[6] = '\0';

	scanf("%s", t);

	if (strcmp(t, "float") == 0)
	{
		scanf("%f", &uf.fl);
		sizebyte = sizeof(float);
		printnum(sizebyte, uf.data);
	}
	if (strcmp(t, "double") == 0)
	{
		scanf("%lf", &ud.db);
		sizebyte = sizeof(double);
		printnum(sizebyte, ud.data);
	}
	if (strcmp(t, "long") == 0)
	{
		scanf("%s", t);
		scanf("%Lf", &uld.ldb);
		sizebyte = sizeof(long double);
		printnum(sizebyte, uld.data);
	}
	return (0);
}
